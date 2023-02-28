// C++ program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;
// Function to check if brackets are balanced
int areBracketsBalanced(string expr){
// Declare a stack to hold the previous brackets.
  stack<char> temp;
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] == '(' || expr[i] == ')' || expr[i] == '{' || expr[i] == '}' || expr[i] == '[' || expr[i] == ']') {
      if (temp.empty()) {
      // If the stack is empty
      // just push the current bracket
        temp.push(expr[i]);
      }
      else if ((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']')) {
      // If we found any complete pair of bracket
      // then pop
        temp.pop();
      }
      else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
        //Return Failed Position
        return i+1;
      }
      else {
        //Push if not a misplaced closing bracket
        temp.push(expr[i]);
      }
    }
  }
  if (temp.empty()) {
      // If stack is empty return true
      return -1;
  }
return expr.length();
}

void printBalance(string expr){
  //Print Success
  if (areBracketsBalanced(expr) == -1)
    cout << "Success" << endl;
  else
  //Print Failure Location
    cout << areBracketsBalanced(expr)<< endl;
}

string createStringFromFile(string file){
  //Create a Usable String from the File
  ifstream ifs(file);
  string str((istreambuf_iterator<char>(ifs)),(istreambuf_iterator<char>()));

  return str;
}


// Driver code
int main() {
  //Declaring Variables
  string sample1 = "[]";
  string sample2 = "{}[]";
  string sample3 = "[()]";
  string sample4 = "(())";
  string sample5 = "{[]}()";
  string sample6 = "{";
  string sample7 = "{[}";
  string sample8 = "foo(bar)";
  string sample9 = "foo(bar[i)";

  // Testing Samples

  printBalance(sample1);
  printBalance(sample2);
  printBalance(sample3);
  printBalance(sample4);
  printBalance(sample5);
  printBalance(sample6);
  printBalance(sample7);
  printBalance(sample8);
  printBalance(sample9);
  cout << endl;

  
  // Declaring Files as strings

  string test1 = createStringFromFile("01");
  string test2 = createStringFromFile("02");
  string test3 = createStringFromFile("03");
  string test4 = createStringFromFile("04");
  string test5 = createStringFromFile("05");
  string test6 = createStringFromFile("06");
  string test7 = createStringFromFile("07");
  string test8 = createStringFromFile("08");
  string test9 = createStringFromFile("09");
  string test10 = createStringFromFile("10");
  string test11 = createStringFromFile("11");
  string test12 = createStringFromFile("12");
  string test13 = createStringFromFile("13");
  string test14 = createStringFromFile("14");
  string test15 = createStringFromFile("15");
  string test16 = createStringFromFile("16");
  string test17 = createStringFromFile("17");
  string test18 = createStringFromFile("18");
  string test19 = createStringFromFile("19");
  string test20 = createStringFromFile("20");
  string test21 = createStringFromFile("21");
  string test22 = createStringFromFile("22");
  string test23 = createStringFromFile("23");
  string test24 = createStringFromFile("24");
  string test25 = createStringFromFile("25");
  string test26 = createStringFromFile("26");
  string test27 = createStringFromFile("27");
  string test28 = createStringFromFile("28");
  string test29 = createStringFromFile("29");
  string test30 = createStringFromFile("30");
  string test31 = createStringFromFile("31");
  string test32 = createStringFromFile("32");
  string test33 = createStringFromFile("33");
  string test34 = createStringFromFile("34");
  string test35 = createStringFromFile("35");
  string test36 = createStringFromFile("36");
  string test37 = createStringFromFile("37");
  string test38 = createStringFromFile("38");
  string test39 = createStringFromFile("39");
  string test40 = createStringFromFile("40");
  string test41 = createStringFromFile("41");
  string test42 = createStringFromFile("42");
  string test43 = createStringFromFile("43");
  string test44 = createStringFromFile("44");
  string test45 = createStringFromFile("45");
  string test46 = createStringFromFile("46");
  string test47 = createStringFromFile("47");
  string test48 = createStringFromFile("48");
  string test49 = createStringFromFile("49");
  string test50 = createStringFromFile("50");
  
  //Testing Test Files
  printBalance(test1);
  printBalance(test2);
  printBalance(test3);
  printBalance(test4);
  printBalance(test5);
  printBalance(test6);
  printBalance(test7);
  printBalance(test8);
  printBalance(test9);
  printBalance(test10);
  printBalance(test11);
  printBalance(test12);
  printBalance(test13);
  printBalance(test14);
  printBalance(test15);
  printBalance(test16);
  printBalance(test17);
  printBalance(test18);
  printBalance(test19);
  printBalance(test20);
  printBalance(test21);
  printBalance(test22);
  printBalance(test23);
  printBalance(test24);
  printBalance(test25);
  printBalance(test26);
  printBalance(test27);
  printBalance(test28);
  printBalance(test29);
  printBalance(test30);
  printBalance(test31);
  printBalance(test32);
  printBalance(test33);
  printBalance(test34);
  printBalance(test35);
  printBalance(test36);
  printBalance(test37);
  printBalance(test38);
  printBalance(test39);
  printBalance(test40);
  printBalance(test41);
  printBalance(test42);
  printBalance(test43);
  printBalance(test44);
  printBalance(test45);
  printBalance(test46);
  printBalance(test47);
  printBalance(test48);
  printBalance(test49);
  printBalance(test50);

return 0;
}