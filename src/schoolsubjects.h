#ifndef SCHOOLSUBJECTS_H
#define SCHOOLSUBJECTS_H
#include "subject.h"

class SchoolSubjects : public Subject
{
private:
    Subject subject;
public:

    SchoolSubjects();
    SchoolSubjects(Subject subject);
};

#endif // SCHOOLSUBJECTS_H
