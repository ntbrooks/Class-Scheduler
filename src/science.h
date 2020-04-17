#ifndef SCIENCE_H
#define SCIENCE_H
#include <string>
#include <ctime>
#include <list>
#include "student.h"
#include "teacher.h"
using namespace std;

class Science
{

public:
    int CourseId;
    string CourseName;
    time_t ClassTime;
    Teacher Teacher;
    list<Student> roster;

    Science();
    Science(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher);
    void GetScienceClass(int CourseId);
};

#endif // SCIENCE_H
