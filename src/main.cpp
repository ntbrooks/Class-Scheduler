#include <string>
#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    Student student(1, "Matt", "Holiday", 14, "Male");

    cout << "ID: " << student.Id << endl;
    cout << "Name: " << student.FirstName << " " << student.LastName << endl;
    cout << "Age: " << student.Age << " Gender: " << student.Gender << endl;

    return 0;
}
