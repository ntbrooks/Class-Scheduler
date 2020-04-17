#include "business.h"

Business::Business()
{

}

Business::Business(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher)
{
    this -> CourseId = CourseId;
    this -> CourseName = CourseName;
    this -> ClassTime = ClassTime;
    this -> Teacher = Teacher;
}

void GetBusinessClass(int CourseId)
{

}
