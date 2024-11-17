#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Task {
	private:
		string name;
		int burstDuration;
		int arrivalTime;
		int unfinished;
		int waitTime;
		int waitCycle;
		int responseTime;
	public:

	Task(string n, int d, int t){
		name = n;
		burstDuration = d;
		arrivalTime = t;
		unfinished = d;
		waitTime = 0;
		waitCycle = 0;
		responseTime = 0;
	}
	string getName() const {
		return name;
	}
	int getDuration() const {
		return burstDuration;
	}
	int getArrival() const {
		return arrivalTime;
	}
	void resetCycles() {
		unfinished = burstDuration;
		waitTime = 0;
		waitCycle = arrivalTime;
		responseTime = 0;
	}
	void wait(int cycle){
		waitCycle = cycle;
	}
	void ready(int cycle){
		waitTime += cycle - waitCycle;
	}
	void setResponseTime(int cycle){
		responseTime = cycle - arrivalTime;
	}
	void complete() {
		unfinished--;
	}
	int getWaitTime() const {
		return waitTime;
	}
	int getWaitCycle() const {
		return waitCycle;
	}
	int getResponseTime() const {
		return responseTime;
	}
	int getUnfinished() const {
		return unfinished;
	}
	bool operator==(const Task& other) const {
		return name == other.name && burstDuration == other.burstDuration && arrivalTime == other.arrivalTime;
	}
};


vector<Task> readFile(const string& filename) {
	vector<Task> tasks;
	ifstream file(filename);

	if (!file.is_open()) {
		cerr << "Error: Could not open file " << filename << endl;
		return tasks;
	}

	string line;
	while (getline(file, line)) {
		istringstream stream(line);
		string name;
		int duration, time;

		if (stream >> name >> duration >> time) {
			tasks.push_back(Task(name, duration, time));
		} else {
			cerr << "Error: Incorrect data format in line: " << line << endl;
		}
	}
	file.close();
	return tasks;
}

void sortByArrivalTime(vector<Task>& tasks) {
	sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
		return t1.getArrival() < t2.getArrival();
	});
}

vector<vector<char>> createGrid(const vector<Task>& tasks) {
	int columns = 0;
	for (const auto& task : tasks) {
		columns += task.getDuration();
	}
	return vector<vector<char>>(tasks.size(), vector<char>(columns, '-'));
}

void displayGrid(const vector<vector<char>>& grid, const vector<Task>& tasks) {
	for (size_t i = 0; i < grid.size(); ++i) {
		cout << tasks[i].getName() << "\t";
		for (const auto& cell : grid[i]) {
			cout << cell;
		}
		cout << endl;
	}
}

void fifo(vector<Task>& tasks){
	cout << endl << "fifo" << endl << endl;

	int cycle = 0;
	int row = 0;
	float averageResponseTime = 0;
	float averageWaitTime = 0;
	int throughput = 0;
	vector<vector<char>> grid = createGrid(tasks);

	for (vector<Task>::iterator it = tasks.begin(); it !=tasks.end(); ++it) {
		it->resetCycles();
	}

	for (vector<Task>::iterator it = tasks.begin(); it !=tasks.end(); ++it) {
		for (int i = 0; i < (it->getDuration()); ++i) {
			if (i == 0) {
				it->setResponseTime(cycle);
				it->ready(cycle);
			}
			if (cycle == 10) {
				for (vector<Task>::iterator tp = tasks.begin(); tp !=tasks.end(); ++tp) {
					if (0 == tp->getUnfinished()){
						throughput++;
					}
				}
			}
			grid[row][cycle] = '#';
			cycle++;
			it -> complete();
		}
		averageResponseTime += it->getResponseTime();
		averageWaitTime += it->getWaitTime();
		row++;
	}
	averageResponseTime /= row;
	averageWaitTime /= row;
	displayGrid(grid, tasks);
	cout << endl;
	cout << "Average Response Time: " << averageResponseTime << endl;
	cout << "Average Wait Time: " << averageWaitTime << endl;
	cout << "Throughput at 10 Cycles: " << throughput << endl;
}

void sjf(vector<Task>& tasks) {
	cout << endl <<"sjf" << endl << endl;

	int cycle = 0;
	float averageResponseTime = 0;
	float averageWaitTime = 0;
	int throughput = 0;
	vector<vector<char>> grid = createGrid(tasks);

	for (auto& task : tasks) {
		task.resetCycles();
	}

	auto cmp = [&tasks](int t1Index, int t2Index) {
		return tasks[t1Index].getUnfinished() > tasks[t2Index].getUnfinished();
	};
	priority_queue<int, vector<int>, decltype(cmp)> readyQueue(cmp);

	size_t taskIndex = 0;

	while (taskIndex < tasks.size() || !readyQueue.empty()) {
		while (taskIndex < tasks.size() && tasks[taskIndex].getArrival() <= cycle) {
			readyQueue.push(taskIndex);
			taskIndex++;
		}

		if (!readyQueue.empty()) {
			int currentIndex = readyQueue.top();
			readyQueue.pop();

			Task& currentTask = tasks[currentIndex];
			currentTask.ready(cycle);

			if (currentTask.getUnfinished() == currentTask.getDuration()) {
				currentTask.setResponseTime(cycle);
				averageResponseTime += currentTask.getResponseTime();
			}

			grid[currentIndex][cycle] = '#';
			currentTask.complete();

			if (cycle == 10) {
				for (vector<Task>::iterator tp = tasks.begin(); tp !=tasks.end(); ++tp) {
					if (0 == tp->getUnfinished()){
						throughput++;
					}
				}
			}


			if (currentTask.getUnfinished() > 0) {
				currentTask.wait(cycle);
				readyQueue.push(currentIndex);
			}
			else {
				averageWaitTime += currentTask.getWaitTime();
			}

			cycle++;

		}
		else {
			cycle++;
		}
	}
	averageResponseTime /= tasks.size();
	averageWaitTime /= tasks.size();

	displayGrid(grid, tasks);
	cout << endl;
	cout << "Average Response Time: " << averageResponseTime << endl;
	cout << "Average Wait Time: " << averageWaitTime << endl;
	cout << "Throughput at 10 Cycles: " << throughput << endl;
}

void rr(vector<Task>& tasks) {
	cout << endl<< "rr" << endl << endl;

	int cycle = 0;
	float averageResponseTime = 0;
	float averageWaitTime = 0;
	int throughput = 0;

	vector<vector<char>> grid = createGrid(tasks);

	for (auto& task : tasks) {
		task.resetCycles();
	}

	queue<int> readyQueue;
	size_t taskIndex = 0;

	while (taskIndex < tasks.size() && tasks[taskIndex].getArrival() <= cycle) {
		readyQueue.push(taskIndex++);
	}

	while (!readyQueue.empty()) {
		int currentIndex = readyQueue.front();
		readyQueue.pop();
		Task& currentTask = tasks[currentIndex];

		currentTask.ready(cycle);

		if (currentTask.getUnfinished() == currentTask.getDuration()) {
			currentTask.setResponseTime(cycle);
			averageResponseTime += currentTask.getResponseTime();
		}

		grid[currentIndex][cycle] = '#';
		currentTask.complete();

		if (cycle == 10) {
			for (vector<Task>::iterator tp = tasks.begin(); tp != tasks.end(); ++tp) {
				if (0 == tp->getUnfinished()) {
					throughput++;
				}
			}
		}

		if (currentTask.getUnfinished() > 0) {
			readyQueue.push(currentIndex);
			currentTask.wait(cycle);
		}
		else {
			averageWaitTime += currentTask.getWaitTime();
		}
		cycle++;

		while (taskIndex < tasks.size() && tasks[taskIndex].getArrival() <= cycle) {
			readyQueue.push(taskIndex++);
		}
	}

	averageResponseTime /= tasks.size();
	averageWaitTime /= tasks.size();

	displayGrid(grid, tasks);
	cout << endl;
	cout << "Average Response Time: " << averageResponseTime << endl;
	cout << "Average Wait Time: " << averageWaitTime << endl;
	cout << "Throughput at 10 Cycles: " << throughput << endl;
}

int main() {
	string fileName;
	cout << "Enter Filename: ";
	cin >> fileName;

	vector<Task> tasks = readFile(fileName);
	if (tasks.empty()) {
		return 1;
	}

	sortByArrivalTime(tasks);
	fifo(tasks);
	sjf(tasks);
	rr(tasks);

	return 0;
}
