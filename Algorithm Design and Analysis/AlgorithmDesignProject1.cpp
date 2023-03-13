//Authors: Elijah Garmon, Jonnuelle Astacio, Trevor Kingery 

#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

class Node{
  private:
    int id;
    int x;
    int y;
    int bidPrice;
    vector<Node*>* adjacencyList;

public:
  Node(int _id, int _x, int _y, int _bidPrice){
    id = _id;
    x = _x;
    y = _y;
    bidPrice = _bidPrice;
  }
  Node(Node* const nodes){
    id = nodes->GetId();
    x = nodes->GetX();
    y = nodes->GetY();
    bidPrice = nodes->GetPrice();
  }

  int const GetId() {
    return id;  
  }

  int const GetX() {
    return x;  
  }

  int const GetY(){
    return y;
  }

  int const GetPrice(){
    return bidPrice;
  }

  vector<Node*>* GetAdjacencyList(){
    return adjacencyList;
  }

  void SetX(int _x){
    x = _x;
  }

  void SetY(int _y){
    y = _y;
  }

  void SetPrice(int price){
    bidPrice = price;
  }  

  void AddConnection(Node* node){
    adjacencyList->push_back(node);
  }

  void SetAdjacencyList(vector<Node*>* list){
    adjacencyList = list;
  }
};

class Graph{
  private:
    int numVertices;
    list<int> *adjLists;
    
  public:
    Graph(int V);
    void addEdge(int src, int dest);
};

//Print Vector
void printVector(vector<Node*>* nodes){
  for (int i = 0; i < nodes->size(); i++){
    cout << nodes->at(i)->GetId() << ".  \t" << nodes->at(i)->GetX() << ",  \t" << nodes->at(i)->GetY() << ",  \t" << nodes->at(i)->GetPrice() << "   \t T: " << nodes->at(i)->GetAdjacencyList()->size() << "   \t R: " << (double)nodes->at(i)->GetPrice() / (double)(nodes->at(i)->GetAdjacencyList()->size() + 1) <<  endl;
    }
}

//get the distance between two given nodes
double GetNodeDistance(Node point1, Node point2){
  double xChange = pow(((double)point2.GetX()-(double)point1.GetX()), 2);
  double yChange = pow(((double)point2.GetY()-(double)point1.GetY()), 2);
  return sqrt(xChange+yChange);
}

//Determine the amount of nodes within the radius
vector<Node*>* GetNodesTouching(vector<Node*>* const nodes, Node* point, double radius) {
  vector<Node*>* touching = new vector<Node*>();
  for (int i = 0; i < nodes->size(); i++)
    {
      if (nodes->at(i)->GetId() != point->GetId() && GetNodeDistance(*point, *(nodes->at(i))) <= radius)
      {
        touching->push_back(nodes->at(i));
      }
    }

  return touching;
}

void RemoveNodesTouching(vector<Node*>* nodes, Node* point, double radius) {
  for (int i = 0; i < nodes->size(); i++)
    {
      if (nodes->at(i)->GetId() != point->GetId() && GetNodeDistance(*point, *(nodes->at(i))) <= radius)
      {
        nodes->erase(nodes->begin() + i);
        i--;
      }
    }
}

//Determine if the node is within the vector
bool isNodeInVector(Node input, vector<Node*>* const nodes) {
  for (int i = 0; i < nodes->size(); i++) {
      if (input.GetId() == nodes->at(i)->GetId())
        return true;
    }
  return false;
}

//Determine the Id of a Node
Node GetNodeById(vector<Node*>* const nodes, int id){
  for (int i = 0; i < nodes->size(); i++)
    {
      if (nodes->at(i)->GetId() == id)
        return nodes->at(i);
    }
  return NULL;
}

//Generate All 100 Locations
vector<Node*>* createLocations(double radius){
  //Set the seed
   srand( (unsigned)time( NULL ) );
  //Vector
  vector<Node*>* nodes = new vector<Node*>();
  //SetValues
  for (int i = 0; i < 100; i++){
    nodes->push_back(new Node(i,  rand() % 1000, rand() % 1000, rand() % 100 + 1));
    ;
  }

  for (int i = 0; i < nodes->size(); i++) {
      nodes->at(i)->SetAdjacencyList(GetNodesTouching(nodes, (nodes->at(i)), radius));
    }
  return nodes;
}

//Generate 100 locations clustered in 4 groups of 25
//group 1 has cheap bid prices
//group 2 & 3 has medium prices
//group 4 has high bid prices
vector<Node*>* createLocationsCluster(double radius){
  //Set the seed
   srand( (unsigned)time( NULL ) );
  //Vector
  vector<Node*>* nodes = new vector<Node*>();
  //SetValues
  for (int i = 0; i < 100; i++){
//cheap-bid prices
   if(i<25){
     nodes->push_back(new Node(i, rand() % 100 + 1, rand() % 100 + 1, rand() % 25 + 1));
   }
//mid-bid prices
    else if(i>=25 && i<50){
      nodes->push_back(new Node(i, rand() % 100 + 1, (rand() % 100) + 501, rand() % 25 + 26));
    }
//mid-bid prices
    else if(i>=50 && i<75){
      nodes->push_back(new Node(i, (rand() % 100) + 501, rand() % 100 + 1, rand() % 25+36));
    }
//high-bid prices
    else{
      nodes->push_back(new Node(i, (rand() % 100) + 801, (rand() % 100) + 801, rand() % 25 + 76));
    }
  }

  for (int i = 0; i < nodes->size(); i++) {
      nodes->at(i)->SetAdjacencyList(GetNodesTouching(nodes, (nodes->at(i)), radius));
    }
  
  return nodes;
}

//sort Nodes by lowest bid price
vector<Node*>* sortNodesByPrice(vector<Node*>* const nodes) {
   //insertion Sort
  vector<Node*>* sorted = new vector<Node*>();

  for (int i = 0; i < nodes->size(); i++) {
      int currentIndex = 0;
      while (currentIndex < sorted->size()) {
          if (nodes->at(i)->GetPrice() > sorted->at(currentIndex)->GetPrice()) {
              currentIndex++;
              continue;
            }
          break;
        }
      sorted->insert(sorted->begin() + currentIndex, nodes->at(i));
    }
  return sorted;
}

//Sort Nodes by the amount the price divided by the nodes within the radius
vector<Node*>* sortNodesByRatio(vector<Node*>* const nodes, double radius) {
   //insertion Sort
  vector<Node*>* sorted = new vector<Node*>();
  int currentIndex = 0;
  double currentRatio;
  double tempRatio;
  for (int i = 0; i < nodes->size(); i++) { 
    currentIndex = 0;
      tempRatio = (double)nodes->at(i)->GetPrice() / (double)(nodes->at(i)->GetAdjacencyList()->size() + 1);
      while (currentIndex < sorted->size()) {
          currentRatio = (double)sorted->at(currentIndex)->GetPrice() / (double)(sorted->at(currentIndex)->GetAdjacencyList()->size() + 1);
          if (tempRatio > currentRatio) {
              currentIndex++;
              continue;
            }
          break;
        }
      sorted->insert(sorted->begin() + currentIndex, nodes->at(i)); 
    }
  return sorted;
}

//Run the Greedy Algorithm
vector<Node*>* TakePoints_greedy(double radius, int* budget, vector<Node*>* const nodes) {
  vector<Node*>* sortedNodes = new vector<Node*>;
  sortedNodes = sortNodesByPrice(nodes);
  
  vector<Node*>* pointsTaken = new vector<Node*>();
  for (int i = 0; i < sortedNodes -> size(); i++){
    if ((*budget - sortedNodes->at(i)->GetPrice()) >= 0){ 
      *budget -= sortedNodes->at(i)->GetPrice();
      pointsTaken->push_back(sortedNodes->at(i));
    }
  }

  //delete pointsTaken;
  return pointsTaken;
}

//Run the Maximum Converage Algorithm
vector<Node*>* TakePoints_maximumCoverage(double radius, int* budget, vector<Node*>* const nodes){
  vector<Node*>* sortedNodes = new vector<Node*>;
  sortedNodes = sortNodesByRatio(nodes, radius);

  vector<Node*>* pointsTaken = new vector<Node*>();
  vector<Node*>* touching = new vector<Node*>();
  for (int i = 0; i < sortedNodes -> size(); i++){
    if ((*budget - sortedNodes->at(i)->GetPrice()) >= 0){ 
      *budget -= sortedNodes->at(i)->GetPrice();
      pointsTaken->push_back(sortedNodes->at(i));

      //erase all points that are touching
      for (int e = 0; e < sortedNodes->size(); e++) {
      
      if (sortedNodes->at(i)->GetId() != sortedNodes->at(e)->GetId() && isNodeInVector(sortedNodes->at(e), sortedNodes->at(i)->GetAdjacencyList())) {
        //shift i according to e
        if (e < i)
          i--;
        
        sortedNodes->erase(sortedNodes->begin() + e);
        e--;
      }
    }

      sortedNodes->erase(sortedNodes->begin() + i);
      i--;
    }
  }

  //delete pointsTaken;
  return pointsTaken;
}

//Determine the percentage coverered by the algorithm
double CalculateCoverage(vector<Node*>* const nodes, vector<Node*>* const pointsTaken, double radius = 10) {
  vector<Node*>* freePoints = new vector<Node*>();

  for (int i = 0; i < pointsTaken->size(); i++) {
    
    for (int e = 0; e < pointsTaken->at(i)->GetAdjacencyList()->size(); e++) {
        if (!isNodeInVector(pointsTaken->at(i)->GetAdjacencyList()->at(e), freePoints) && 
          !isNodeInVector(pointsTaken->at(i)->GetAdjacencyList()->at(e), pointsTaken)) {
          freePoints->push_back(pointsTaken->at(i)->GetAdjacencyList()->at(e));
        }
      }
    }

  vector<Node*>* allPointsCaptured = new vector<Node*>();
  allPointsCaptured->reserve( pointsTaken->size() + freePoints->size() ); // preallocate memory
  allPointsCaptured->insert( allPointsCaptured->end(), pointsTaken->begin(), pointsTaken->end() );
  allPointsCaptured->insert( allPointsCaptured->end(), freePoints->begin(), freePoints->end() );

  double coverage = 100.00 * ((double)allPointsCaptured->size() / (double)nodes->size());

  delete freePoints;
  delete allPointsCaptured;

  return coverage;
}

//Create Manual Test
vector<Node*>* createManual(double radius){
  vector<Node*>* manualNodes = new vector<Node*>();
  manualNodes->push_back(new Node(1, 1, 1, 1));
  manualNodes->push_back(new Node(2, 2, 2, 2));
  manualNodes->push_back(new Node(3, 3, 3, 3));
  manualNodes->push_back(new Node(4, 4, 4, 4));

  manualNodes->push_back(new Node(5, 59, 50, 5));
  manualNodes->push_back(new Node(6, 41, 50, 6));
  manualNodes->push_back(new Node(7, 50, 50, 7));
  manualNodes->push_back(new Node(8, 45, 50, 8));

  manualNodes->push_back(new Node(9, 100, 9, 9));
  manualNodes->push_back(new Node(10, 200, 10, 10));
  manualNodes->push_back(new Node(11, 300, 11, 11));
  manualNodes->push_back(new Node(12, 400, 12, 12));

  for (int i = 0; i < manualNodes->size(); i++) {
      manualNodes->at(i)->SetAdjacencyList(GetNodesTouching(manualNodes, (manualNodes->at(i)), radius));
    }
  
  return manualNodes;
}

int main() {
  //Declaring Variables
  double radius = 10;
  int budget = 500;

  //Create Nodes
  vector<Node*>* simulatedNodes = createLocations(radius);
  vector<Node*>* clusteredNodes = createLocationsCluster(radius);

  //Print Nodes
  cout << "Raw Uniform Locations" << endl;
  printVector(simulatedNodes);
  cout << endl;
  cout << "Raw Clustered Locations" << endl;
  printVector(clusteredNodes);

  cout << endl;
  cout << endl;

  //Run Greedy Algorithm and Determine which nodes are taken
  int remainingBudget1 = budget;
  int remainingBudget2 = budget;

  
  cout << "Uniform Locations" << endl;
  vector<Node*>* s_pointsTaken = TakePoints_greedy(radius, &remainingBudget1, simulatedNodes);
  vector<Node*>* s_pointsTaken_maxC = TakePoints_maximumCoverage(radius, &remainingBudget2, simulatedNodes);

   cout << "Points After Greedy" << endl;
  printVector(s_pointsTaken);
  cout << "Total Coverage (greedy): " << CalculateCoverage(simulatedNodes, s_pointsTaken, radius) << "%" << endl;
  cout << "Budget Left (greedy): " << remainingBudget1 << "$ " << endl;
  cout << endl;
  
  cout << "Points After MaxCov" << endl;
  printVector(s_pointsTaken_maxC);
  cout << "Total Coverage (maxCov): " << CalculateCoverage(simulatedNodes, s_pointsTaken_maxC, radius) << "%" << endl;
  cout << "Budget Left (maxCov): " << remainingBudget2 << "$ " << endl;

  
  cout << endl;
  cout << endl;

  remainingBudget1 = budget;
  remainingBudget2 = budget;

  //Testing clustered locations
  cout << "Clustered Locations" << endl;
  vector<Node*>* c_pointsTaken = TakePoints_greedy(radius, &remainingBudget1, clusteredNodes);
  vector<Node*>* c_pointsTaken_maxC = TakePoints_maximumCoverage(radius, &remainingBudget2, clusteredNodes);
  cout << "Points After Greedy" << endl;
  printVector(c_pointsTaken);
   cout << "Total Coverage (greedy): " << CalculateCoverage(clusteredNodes, c_pointsTaken, radius) << "%" << endl;
  cout << "Budget Left (greedy): " << remainingBudget1 << "$ " << endl;
  cout << endl;
  
  cout << "Points After MaxCov" << endl;
  printVector(c_pointsTaken_maxC);
  cout << "Total Coverage (maxCov): " << CalculateCoverage(clusteredNodes, c_pointsTaken_maxC, radius) << "%" << endl;
  cout << "Budget Left (maxCov): " << remainingBudget2 << "$ " << endl;
  cout << endl;
  cout << endl;
  

  //Manual Test of Greedy Algorithm

  remainingBudget1 = 20;
  remainingBudget2 = 20;
  
  cout << "Manual Test" << endl;
  vector<Node*>* manualNodes = createManual(10);
  
  vector<Node*>* m_pointsTaken_greedy = TakePoints_greedy(10, &remainingBudget1, manualNodes);
  vector<Node*>* m_pointsTaken_maxC = TakePoints_maximumCoverage(10, &remainingBudget2, manualNodes);
  
  cout << "Points After Greedy" << endl;
  printVector(m_pointsTaken_greedy);
  cout << "Total Coverage (greedy): " << CalculateCoverage(manualNodes, m_pointsTaken_greedy) << "%" << endl;
  cout << "Budget Left (greedy): " << remainingBudget1 << "$ " << endl;
  cout << endl;

  cout << "Points After MaxCov" << endl;
  printVector(m_pointsTaken_maxC);
  cout << "Total Coverage (maxCov): " << CalculateCoverage(manualNodes, m_pointsTaken_maxC) << "%" << endl;
  cout << "Budget Left (maxCov): " << remainingBudget2 << "$ " << endl;
  cout << endl;
  
  return 0;
}