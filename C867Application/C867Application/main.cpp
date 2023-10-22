#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <print>

using namespace std;
int main()
{
    int numOfStudents = 5;
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Bailey,Hogg,bhogg3@wgu.edu,23,7,12,4,SOFTWARE"
    };

    /*
    F.  Demonstrate the program’s required functionality by adding a
        main() function in main.cpp, which will contain the required
        function calls to achieve the following results:
    1.  Print out to the screen, via your application, the course title,
        the programming language used, your WGU student ID, and your
        name.
    */
    cout << "C867 Scripting and Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 011047043" << endl;
    cout << "Name: Bailey Hogg" << endl;
    cout << "\t\t" << endl;
        

    /*
    2.  Create an instance of the Roster class called classRoster.
    3.  Add each student to classRoster.
    */
    Roster* classRoster = new Roster;
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };
    /*
    4.  Convert the following pseudo code to complete the rest of the
        main() function:
    classRoster.printAll();
    classRoster.printInvalidEmails();
    */
   
    cout << "Displaying all students:" << endl;
    classRoster->printAll();

    classRoster->printInvalidEmails();


    
    //loop through classRosterArray and for each element:
    //classRoster->printAverageDaysInCourse();

        for (int i = 0; i < 5; i++) {
            classRoster->printAverageDaysInCourse(classRoster->getStudentID(i));
        }
        cout << endl;
     
    
    //classRoster->printAverageDaysInCourse(classRoster->getStudentID(0));


   
    /*
    Note: For the current_object's student id, use an accessor 
    (i.e., getter) for the classRosterArray to access the student id.
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    */



    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");




    /*
    classRoster.printAll();
    classRoster.remove("A3");
    */




    classRoster->printAll();
    cout << endl;
    cout << "Removing A3 again" << endl;
    cout << endl;
    classRoster->remove("A3");



    /*
    //expected: the above line should print a message saying 
    such a student with this ID was not found.
    5.  Implement the destructor to release the memory that was 
    allocated dynamically in Roster.
    */



    classRoster->~Roster(); 
   
}