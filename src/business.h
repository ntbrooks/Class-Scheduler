#ifndef BUSINESS_H
#define BUSINESS_H
#include <string>
#include <ctime>
#include <list>
#include "teacher.h"
#include "student.h"
using namespace std;

class Business
{
public:
    int CourseId;
    string CourseName;
    time_t ClassTime;
    Teacher Teacher;
    list<Student> roster;

    Business();
    Business(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher);
    void GetBusinessClass(int CourseId);
};

#endif // BUSINESS_H
