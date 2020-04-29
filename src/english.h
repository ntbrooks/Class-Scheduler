#ifndef ENGLISH_H
#define ENGLISH_H
#include <string>
#include <ctime>
#include <list>
#include "student.h"
#include "teacher.h"
using namespace std;

class English
{

public:
    int CourseId;
    string CourseName;
    time_t ClassTime;
    Teacher Teacher;
    list<Student> Roster;

    English();
    English(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher);
    void GetEnglishClass(list<English> classList, int CourseId);
};

#endif // ENGLISH_H
