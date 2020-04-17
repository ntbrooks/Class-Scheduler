#include "math.h"

Math::Math()
{

}

Math::Math(int CourseId, string CourseName, time_t ClassTime, class Teacher Teacher)
{
    this -> CourseId = CourseId;
    this -> CourseName = CourseName;
    this -> ClassTime = ClassTime;
    this -> Teacher = Teacher;
}

void GetMathClass(int CourseId)
{

}
