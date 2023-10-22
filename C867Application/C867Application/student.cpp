#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

Student::Student() {
    this->studentID = "";
    this->first = "";
    this->last = "";
    this->email = "";
    this->age = 0;
    this->numOfDays[0] = 0;
    this->numOfDays[1] = 0;
    this->numOfDays[2] = 0;
    this->degreeProgram;
};
Student::Student(string studentID, string first, string last, string email,
    int age, int NumOfDays[], DegreeProgram degreeProgram) 
{
    this->studentID = studentID;
    this->first = first;
    this->last = last;
    this->email = email;
    this->age = age;
    this->numOfDays[0] = NumOfDays[0];
    this->numOfDays[1] = NumOfDays[1];
    this->numOfDays[2] = NumOfDays[2];
    this->degreeProgram = degreeProgram;
}

//getters
string Student::getStudentID() {
    return studentID;
}
string Student::getFirst() {
    return first;
}
string Student::getLast() {
    return last;
}
string Student::getEmail() {
    return email;
}
int Student::getAge() {
    return age;
}
int* Student::getNumOfDays() {
    return numOfDays;
}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

//setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirst(string first) {
    this->first = first;
}
void Student::setLast(string last) {
    this->last = last;
}
void Student::setEmail(string email) {
    this->email = email;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setNumOfDays(int numOfDays1, int numOfDays2, int numOfDays3) {
    this->numOfDays[0] = numOfDays1;
    this->numOfDays[1] = numOfDays2;
    this->numOfDays[2] = numOfDays3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}


DegreeProgram getDegreeProgram()
{
    return DegreeProgram();
}

void Student::print()
{
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

    cout << studentID + "\t" << first + "\t" << last << "\t\t"
        << age << "\t\t" << "{" << numOfDays[0] << ", " << numOfDays[1] << ", " << numOfDays[2] 
        << "}" << "\t" << degree << endl;
    return;
 
};
