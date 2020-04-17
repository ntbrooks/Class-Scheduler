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
    string Subject;

    Teacher();
    Teacher(int Id, string FirstName, string LastName, string Subject);
    void GetTeacher(int Id);
};

#endif // TEACHER_H
