#ifndef BUSINESS_H
#define BUSINESS_H
#include <string>
#include <list>
#include "teacher.h"
#include "student.h"
using namespace std;

class Subject
{
public:
    int CourseId;
    string CourseName;
    int ClassTime;
    Teacher Teacher;
    list<Student> Roster;

    Subject();
    Subject(int CourseId, string CourseName, int ClassTime);
//    Subject(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher);
    void GetSubject(list<Subject> classList, int CourseId);
};

#endif // BUSINESS_H
