#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <regex>
using namespace std;
/*
E.  Create a Roster class (roster.cpp) by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the
	data provided in the “studentData Table.”
*/
int numOfStudents = 5;
int i = 0;

string Roster::getStudentID(int id)
{
	string studentID = classRosterArray[id]->getStudentID();
	return studentID;
}
//DegreeProgram stringToEnum(const string& str) {
//	if (str == "SECURITY") {
//		return DegreeProgram::SECURITY;
//	}
//	else if (str == "NETWORK") {
//		return DegreeProgram::NETWORK;
//	}
//	else if (str == "SOFTWARE") {
//		return DegreeProgram::SOFTWARE;
//	}
//}
int temp = 0;
void Roster::parse(string studentData) {

	DegreeProgram degreeProgram;
	if (temp < 5) {
		classRosterArray[temp] = new Student();
		int i = studentData.find(",");
		string studentID = studentData.substr(0, i);
		classRosterArray[temp]->setStudentID(studentID);
		
		int j = i + 1;
		i = studentData.find(",", j);
		string first = studentData.substr(j, i - j);
		classRosterArray[temp]->setFirst(first);

		j = i + 1;
		i = studentData.find(",", j);
		string last = studentData.substr(j, i - j);
		classRosterArray[temp]->setLast(last);

		j = i + 1;
		i = studentData.find(",", j);
		string email = studentData.substr(j, i - j);
		classRosterArray[temp]->setEmail(email);

		j = i + 1;
		i = studentData.find(",", j);
		int age = stoi(studentData.substr(j, i - j));
		classRosterArray[temp]->setAge(age);

		j = i + 1;
		i = studentData.find(",", j);
		int numOfDays1 = stoi(studentData.substr(j, i - j));

		j = i + 1;
		i = studentData.find(",", j);
		int numOfDays2 = stoi(studentData.substr(j, i - j));

		j = i + 1;
		i = studentData.find(",", j);
		int numOfDays3 = stoi(studentData.substr(j, i - j));
		classRosterArray[temp]->setNumOfDays(numOfDays1, numOfDays2, numOfDays3);

		j = i + 1;
		i = studentData.find(",", j);
		string degree = studentData.substr(j, i - j);
		if (degree == "SOFTWARE") {
			classRosterArray[temp]->setDegreeProgram(SOFTWARE);
		}
		else if (degree == "SECURITY") {
			classRosterArray[temp]->setDegreeProgram(SECURITY);
		}
		else if (degree == "NETWORK") {
			classRosterArray[temp]->setDegreeProgram(NETWORK);
		} 
		add(studentID, first, last, email, age, numOfDays1, numOfDays2, numOfDays3, classRosterArray[temp]->getDegreeProgram());
		temp++;
	}
}

/*
2.  Create a student object for each student in the data table
	and populate classRosterArray.
a.  Parse each set of data identified in the “studentData 
	Table.”
b.  Add each student object to classRosterArray.
3.  Define the following functions:
a.  public void add(string studentID, string firstName, string 
	lastName, string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
*/
void Roster::add(string studentID,
	string first,
	string last,
	string email,
	int age,
	int numOfDays1,
	int numOfDays2,
	int numOfDays3,
	DegreeProgram degreeProgram) 
{
		int numOfDays[3] = { numOfDays1, numOfDays2, numOfDays3 };
		classRosterArray[numOfStudents] = new Student(studentID, first, last, email, age, numOfDays, degreeProgram);
	
}
/*
b.  public void remove(string studentID)  that removes students from 
	the roster by student ID. If the student ID does not exist,
	the function prints an error message indicating that the student
	was not found.
*/
void Roster::remove(string studentID) {
	//int temp = 0;
	bool located = false;
	for (int i = 0; i <= numOfStudents; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (studentID == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			located = true;
			break;
		}
		//if (classRosterArray[i]->getStudentID() == studentID) {
		//	located = true;

		//	//temp = i;
		//	//delete classRosterArray[temp];
		//	classRosterArray[i] = nullptr;
		//	numOfStudents--;
		//	/*if (i < numOfStudents - 1) {
		//		Student* temp = classRosterArray[i];
		//		classRosterArray[i] = classRosterArray[numOfStudents - 1];
		//		classRosterArray[numOfStudents - 1] = temp;
		//	}
		//	numOfStudents--;*/
		//	break;
		//}
		
	}
	/*delete classRosterArray[temp];*/

	if (located) {
		cout << endl;
		cout << "Removing " << studentID << ":" << endl;
		//this->printAll();
	}
	if (!located) {
		cout << "The student with the ID: " << studentID << " was not found" << endl;
	}

};

/*
c. public void printAll() that prints a complete tab-separated list 
	of student data in the provided format: A1 [tab] 
	First Name: John [tab] Last Name: Smith [tab] Age: 20 
	[tab]daysInCourse: {35, 40, 55} Degree Program: Security. The 
	printAll() function should loop through all the students in
	classRosterArray and call the print() function for each student.
*/
void Roster::printAll()
{
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	/*cout << classRosterArray[0]->getStudentID() << endl;
	cout << "first student" << endl;
	cout << classRosterArray[0]->getStudentID() << endl;
	cout << "second student" << endl;
	cout << classRosterArray[2]->getStudentID() << endl;
	cout << "third student" << endl;
	cout << classRosterArray[1]->getStudentID() << endl;
	cout << "fourth student" << endl;
	cout << classRosterArray[0]->getStudentID() << endl;
	cout << "fifth student" << endl;*/
		/*cout << classRosterArray[i]->getStudentID() << endl;
		cout << classRosterArray[i]->getFirst() << endl;
		cout << classRosterArray[i]->getLast() << endl;
		cout << classRosterArray[i]->getEmail() << endl;
		cout << classRosterArray[i]->getAge() << endl;
		cout << classRosterArray[i]->getNumOfDays()[0] << endl;
		cout << classRosterArray[i]->getNumOfDays()[1] << endl;
		cout << classRosterArray[i]->getNumOfDays()[2] << endl;*/
	}
};

/*
d.  public void printAverageDaysInCourse(string studentID)  that 
	correctly prints a student’s average number of days in the three
	courses. The student is identified by the studentID parameter.
*/
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			cout << "Student ID: " << classRosterArray[i]->getStudentID()
				<< ", average days in course is: " <<
				((classRosterArray[i]->getNumOfDays()[0] +
				  classRosterArray[i]->getNumOfDays()[1] +
				  classRosterArray[i]->getNumOfDays()[2]) / 3) << endl;
		}
	} 
};

/*
e.  public void printInvalidEmails() that verifies student email 
	addresses and displays all invalid email addresses to the user.
*/
void Roster::printInvalidEmails() {
	regex pattern("^[^@\\s]+@[^\\.\\s]+\\.[^\\s]+$");
	cout << endl;
	cout << "Displaying invalid emails: " << endl;
	cout << endl;
	for (int i = 0; i < numOfStudents; ++i) {
		string email = classRosterArray[i]->getEmail();
		if (!regex_match(email, pattern)) {
			cout << classRosterArray[i]->getEmail(); cout << " - is invalid." << endl;
		}
	}
	cout << endl;
};

/*
Note: A valid email should include an at sign ('@') and period ('.')
and should not include a space (' ').
*/

/*
f.  public void printByDegreeProgram(DegreeProgram degreeProgram) 
	that prints out student information for a degree program specified
	by an enumerated type.
*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degree = "";
	if (degreeProgram == 0) {
		degree = "SECURITY";
	}
	else if (degreeProgram == 1) {
		degree = "NETWORK";
	}
	else if (degreeProgram == 2) {
		degree = "SOFTWARE";
	}
	cout << "Showing students in degree program: " << degree << endl;
	cout << endl;
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}


};

Roster::~Roster() {
	for (int i = 0; i < numOfStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	};
};