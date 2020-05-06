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
    int ClassSize;
    Teacher Teacher;
    list<Student> Roster;

    Subject();
    Subject(int CourseId, string CourseName, int ClassTime, int ClassSize);

    void GetSubject(list<Subject> classList, int CourseId);
};

#endif // BUSINESS_H
