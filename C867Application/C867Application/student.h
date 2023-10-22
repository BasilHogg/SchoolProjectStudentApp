#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

/*
D1. Create the class Student in the files student.h and
student.cpp, which includes each of the following
variables:
• student ID
• first name
• last name
• email address
• age
• array of number of days to complete each course
• degree program
*/
class Student{
// made private from instuction in D2.c
private:
	string studentID;
	string first;
	string last;
	string email;
	int age;
	int numOfDays[3];
	DegreeProgram degreeProgram;

/*
D2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the 
	Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/

// D2.a: getters
public:
string getStudentID();
string getFirst();
string getLast();
string getEmail();
int getAge();
int* getNumOfDays();
DegreeProgram getDegreeProgram();

// D2.b setters
void setStudentID(string StudentID);
void setFirst(string first);
void setLast(string last);
void setEmail(string email);
void setAge(int age);
void setNumOfDays(int numOfDays1, int numOfDays2, int numOfDays3);
void setDegreeProgram(DegreeProgram degreeProgram);


// D2.d constructor using all table elements as input

Student(string studentID, string first, string last, string email,
	int age, int NumOfDays[], DegreeProgram degreeProgram);

Student();
// D2.e create print method
void print();
};