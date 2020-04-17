#ifndef STUDENT_H
#define STUDENT_H
#include <list>
#include <string>
using namespace std;


class Student
{

public:
    int Id;
    string FirstName;
    string LastName;
    int Age;
    string Gender;

    Student();
    Student(int Id, string FirstName, string LastName, int Age, string Gender);
    void GetStudent(list<Student> studentList, int Id);

};

#endif // STUDENT_H
