#include "math.h"
#include "teacher.h"
#include <iostream>

using namespace std;

Math::Math()
{

}

Math::Math(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher)
{
    this -> CourseId = CourseId;
    this -> CourseName = CourseName;
    this -> ClassTime = ClassTime;
    this -> Teacher = Teacher;
}

void GetMathClass(list<Math> classList, int Id)
{
    list<Math> :: iterator it;

    for (it = classList.begin(); it != classList.end(); ++it) {
        if (it->CourseId == Id) {
            cout << "Class ID: " << it->CourseId << endl;
            cout << "Class Name: " << it->CourseName << endl;
            cout << "Class Length: " << it->ClassTime << endl;
            cout << "Teacher: " << it->Teacher.FirstName << " " << it->Teacher.LastName << endl;

            list<Student> :: iterator lit;
            for(lit = it->Roster.begin(); lit != it->Roster.end(); ++lit) {
                cout << "Students: ID-" << lit->Id << " Name-" << lit->FirstName << " " << lit->LastName << "Age-" << lit->Age << endl;
            }
        }
    }
}
