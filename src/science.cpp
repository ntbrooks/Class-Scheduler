#include "science.h"

Science::Science()
{

}

Science::Science(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher)
{
    this -> CourseId = CourseId;
    this -> CourseName = CourseName;
    this -> ClassTime = ClassTime;
    this -> Teacher = Teacher;
}

void GetScienceClass(int CourseId)
{

}
