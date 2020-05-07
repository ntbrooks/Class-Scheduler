#ifndef TEACHER_H
#define TEACHER_H
#include <string>
using namespace std;

class Teacher
{

public:
    int Id;
    string FirstName;
    string LastName;
    string Degree;

    Teacher();
    Teacher(int Id, string FirstName, string LastName, string Degree);
    void GetTeacher(int Id);
};

#endif // TEACHER_H
