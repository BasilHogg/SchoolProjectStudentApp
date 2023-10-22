#pragma once
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

class Roster{
public:
	string getStudentID(int id);
	Student* classRosterArray[5];
	void parse(string obj);
	void add(string studentID,
		string first,
		string last,
		string email,
		int age,
		int numOfDays1,
		int numOfDays2,
		int numOfDays3,
		DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};