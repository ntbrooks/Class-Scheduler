#include "student.h"
#include <iostream>
#include <iterator>

Student::Student()
{

}

Student::Student(int Id, string FirstName, string LastName, int Age, string Gender)
{
    this -> Id = Id;
    this -> FirstName = FirstName;
    this -> LastName = LastName;
    this -> Age = Age;
    this -> Gender = Gender;
}

void Student::GetStudent(list<Student> studentList, int Id)
{
    list<Student> :: iterator it;

    for (it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->Id == Id) {
            cout << "ID: " << it->Id << endl;
            cout << "Name: " << it->FirstName << " " << it->LastName << endl;
            cout << "Age: " << it->Age << " Gender: " << it->Gender << endl;
        }
    }
}
