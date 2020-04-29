#ifndef MATH_H
#define MATH_H
#include <string>
#include <ctime>
#include <list>
#include "student.h"
#include "teacher.h"
using namespace std;

class Math
{

public:
    int CourseId;
    string CourseName;
    time_t ClassTime;
    Teacher Teacher;
    list<Student> Roster;

    Math();
    Math(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher);
    void GetMathClass(list<Math> classList, int CourseId);
};

#endif // MATH_H
