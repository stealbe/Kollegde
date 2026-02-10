#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <fstream>

using namespace std;

mutex mtx;

class FileWriter
{
private:
	string fileName;
	static int FileCounter;
	static mutex mtx;

	//friend void AppendLine(FileWriter& wr, const string& str);
	//friend void AppendLineUnsafe(FileWriter& wr, const string& str);
public:
	FileWriter() : fileName("output.txt") { FileCounter++; }
	//FileWriter() : fileName("output_" + to_string(FileCounter) + ".txt") { FileCounter++; }
	FileWriter(string fn) : fileName(fn) { FileCounter++; }
	void appendLine(const string& line)
	{
		mtx.lock();
		ofstream file(fileName, ios::app);
		file << line << endl;
		file.close();
		mtx.unlock();
	}
	void appendLineUnsafe(const string& line)
	{
		ofstream file(fileName, ios::app);
		file << line << endl;
		file.close();
	}
	void clearFile()
	{
		mtx.lock();
		ofstream file(fileName, ios::trunc);
		file.close();
		mtx.unlock();
	}
};

//void AppendLine(FileWriter& wr, const string& str)
//{
//	mtx.lock();
//	ofstream file(wr.fileName, ios::app);
//	file << str << endl;
//	file.close();
//	mtx.unlock();
//}
//
//void AppendLineUnsafe(FileWriter& wr, const string& str)
//{
//	ofstream file(wr.fileName, ios::app);
//	file << str << endl;
//	file.close();
//}

int StudentCount = 0;

class Student
{
	private:
	string fullName;
	int age;
	string university;
	float averageGrade;

	static int StudentCount;

	mutex mtx;
public:
	Student() : fullName(""), age(0), university(""), averageGrade(0.0f) { StudentCount++; }
	Student(string fn, int a, string uni, float ag) : fullName(fn), age(a), university(uni), averageGrade(ag) { StudentCount++; }
	void inputData()
	{
		cout << "Enter full name: ";
		getline(cin, fullName);
		cout << "Enter age: ";
		cin >> age;
		cin.ignore();
		cout << "Enter university: ";
		getline(cin, university);
		cout << "Enter average grade: ";
		cin >> averageGrade;
		cin.ignore();
	}
	void displayData()
	{
		cout << "Full Name: " << fullName << endl;
		cout << "Age: " << age << endl;
		cout << "University: " << university << endl;
		cout << "Average Grade: " << averageGrade << endl;
	}
	void writeToFile()
	{
		FileWriter writer(string("Student_" + to_string(StudentCount) + ".txt"));
		writer.appendLine("Full Name: " + fullName + ", Age: " + to_string(age) + ", University: " + university + ", Average grade: " + to_string(averageGrade));
	}
	void readFromFile(int id)
	{
		mtx.lock();
		ifstream file("Student_" + to_string(id) + ".txt");
		string line;
		while (getline(file, line))
		{
			cout << line << endl;
		}
		file.close();
		mtx.unlock();
	}
};


int FileWriter::FileCounter = 0;
mutex FileWriter::mtx;

string fileName1 = "data.txt";

void Write(string& str, const string fn = fileName1)
{
	mtx.lock();
	ofstream file(fn, ios::app);
	for (int i = 0; i < 10; ++i)
	{
		file << str << endl;
	}
	file.close();

	mtx.unlock();
}

void Read(const string fn = fileName1)
{
	mtx.lock();
	ifstream file(fn);
	string str;
	while (getline(file, str))
	{
		cout << str << endl;
	}
	file.close();

	mtx.unlock();
}

int main()
{
	//string fn = "data.txt";

	//ofstream clearFile(fn, ios::trunc);
	//clearFile.close();

	//thread* threads = new thread[5];

	string init;
	cin >> init;

	//for (size_t i = 0; i < 5; i++)
	//{
	//	threads[i] = thread(Write, string("Thread " + i + string(": ") + init));
	//}

	//Sleep(20);
	//thread read(Read);
	//for (size_t i = 0; i < 5; i++)
	//{
	//	threads[i].join();
	//}
	//read.join();

	// 1
	//Student student;
	//student.inputData();
	//student.writeToFile();
	//student.readFromFile(StudentCount);
	// 2
	FileWriter("output.txt").clearFile();
	thread* fileThreads = new thread[5];
	FileWriter writer1("output.txt");
	for (size_t i = 0; i < 5; i++)
	{
		fileThreads[i] = thread(&FileWriter::appendLine, &writer1, init);
	}
	for (size_t i = 0; i < 5; i++)
	{
		fileThreads[i].join();
	}
	cout << "Done" << endl;
	Sleep(20);
	thread fileRead(Read, "output.txt");
	fileRead.join();

	FileWriter("output.txt").clearFile();
	thread* fileThreads2 = new thread[5];
	FileWriter writer2("output2.txt");
	for (size_t i = 0; i < 5; i++)
	{
		fileThreads2[i] = thread(&FileWriter::appendLineUnsafe, &writer2, init);
	}
	for (size_t i = 0; i < 5; i++)
	{
		fileThreads2[i].join();
	}
	cout << "Done" << endl;
	Sleep(20);

	thread fileRead2(Read, "output2.txt");
	fileRead2.join();
	Sleep(10000);
	return 0;
}
