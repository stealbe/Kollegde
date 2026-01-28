#include <iostream>
#include <mutex>
#include <thread>
#include <fstream>
#include <string>
using namespace std;

mutex mtx;

string logName = "log.txt";

string inputName = "input.txt";
string forbiddenName = "forbidden.txt";
string reportName = "report.txt";

void logPrint(string fileName, string message, int thread)
{
	lock_guard<mutex> lock(mtx);
	ofstream logFile(fileName, ios::app);
	if (logFile.is_open()) {
		logFile << thread << " " << message << endl;
		logFile.close();
	}
}

void logForbidden(string logFile, string forbiddenFile, string line, int lineNum)
{
	ifstream forbiddenList(forbiddenFile);
	string forbiddenChar;
	while (getline(forbiddenList, forbiddenChar))
	{
		size_t pos = 0;
		while ((pos = line.find(forbiddenChar, pos)) != string::npos) {
			lock_guard<mutex> lock(mtx);
			ofstream log(logFile, ios::app);
			if (log.is_open()) {
				log << forbiddenChar << " (" << lineNum << " | " << pos + 1 << ")" << endl;
			}
			pos++;
		}
	}
}

int main() {
	// 1
	/*ofstream logFile(logName, ios::trunc);
	logFile.close();
	const int thCount = 5;
	thread threads[thCount];
	cin.ignore();
	for (int i = 0; i < thCount; ++i) {
		string log;
		cout << "Enter log message: ";
		getline(cin, log);
		threads[i] = thread(logPrint, logName, log, i + 1);
	}
	for (int i = 0; i < thCount; ++i) {
		threads[i].join();
	}
	ifstream readFile(logName);
	if (readFile.is_open()) {
		string line;
		while (getline(readFile, line)) {
			cout << line << endl;
		}
		readFile.close();
	}*/

	//2
	ofstream clearReport(reportName, ios::trunc);
	clearReport.close();
	ifstream inputFile(inputName);
	if (inputFile.is_open()) {
		string line;
		int lineNum = 0;
		int countLines = 0;
		while (getline(inputFile, line)) {
			countLines++;
		}
		inputFile.clear();
		inputFile.seekg(0, ios::beg);
		thread* threads = new thread[countLines];
		while (getline(inputFile, line)) {
			++lineNum;
			threads[lineNum - 1] = thread(logForbidden, reportName, forbiddenName, line, lineNum);
		}
		for (size_t i = 0; i < countLines; i++)
		{
			threads[i].join();
		}
		inputFile.close();
		delete[] threads;
	}
	return 0;
}