#include <string>
#include <iostream>
#include "student.h"
#include "teacher.h"
#include "subject.h"
#include "schoolsubjects.h"

using namespace std;
const int STUDENT_ROSTER_SIZE = 36;
const int TEACHER_ROSTER_SIZE = 8;
const int SUBJECTS_TAUGHT = 4;

string GetFirstName(int Id) {
    string fNameArray[STUDENT_ROSTER_SIZE]
    {
        "Roger",
        "Tina",
        "Frances",
        "Mark",
        "Dorothy",
        "Gregory",
        "Diana",
        "Timothy",
        "Christine",
        "Carol",
        "Phillip",
        "Sarah",
        "Teresa",
        "Peter",
        "Christine",
        "Clarence",
        "Kenneth",
        "Arthur",
        "Lois",
        "Keith",
        "Louis",
        "Donald",
        "Bonnie",
        "Linda",
        "Edward",
        "Diana",
        "Irene",
        "Terry",
        "Howard",
        "Paul",
        "Walter",
        "Billy",
        "Clarence",
        "Eric",
        "Katherine",
        "Albert",
    };

    return fNameArray[Id];
}

string GetLastName(int Id) {
    string lNameArray[STUDENT_ROSTER_SIZE]
    {
        "Wood",
        "Torres",
        "Butler",
        "Jackson",
        "Miller",
        "Bell",
        "Sanchez",
        "Cooper",
        "Howard",
        "Bennett",
        "Butler",
        "Mitchell",
        "Sanchez",
        "Foster",
        "Nelson",
        "Anderson",
        "Baker",
        "Harris",
        "Roberts",
        "Patterson",
        "Lopez",
        "Turner",
        "Collins",
        "Edwards",
        "Cooper",
        "Davis",
        "Howard",
        "Thomas",
        "Stewart",
        "Johnson",
        "Ward",
        "Diaz",
        "Campbell",
        "Bennett",
        "Hall",
        "Thomas",
    };

    return lNameArray[Id];
}

string GetSchoolSubject(int Id) {
    string schoolSubjects[SUBJECTS_TAUGHT] {
        "Business",
        "English",
        "Math",
        "Science",
    };

    return schoolSubjects[Id];
}

// define Business classes and return list of classes
list<Subject> BuildBusinessClasses(list<Subject> classList) {

    Subject BUS111 = Subject(111, "Intro to Business", 90);
    Subject ACC112 = Subject(122, "Intro to Accounting", 90);
    classList.push_back(BUS111);
    classList.push_back(ACC112);

    return classList;
}

// define English classes and return list of classes
list<Subject> BuildEnglishClasses(list<Subject> classList) {

    Subject ENG216 = Subject(216, "English", 90);
    Subject ENG238 = Subject(238, "U.S. History", 90);
    classList.push_back(ENG216);
    classList.push_back(ENG238);

    return classList;
}

// define Math classes and return list of classes
list<Subject> BuildMathClasses(list<Subject> classList) {

    Subject MTH302 = Subject(302, "Algebra", 90);
    Subject MTH341 = Subject(341, "Statistics", 90);
    classList.push_back(MTH302);
    classList.push_back(MTH341);

    return classList;
}

// define Science classes and return list of classes
list<Subject> BuildScienceClasses(list<Subject> classList) {

    Subject SCI421 = Subject(421, "Algebra", 90);
    Subject SCI431 = Subject(431, "Statistics", 90);
    classList.push_back(SCI421);
    classList.push_back(SCI431);

    return classList;
}

list<Subject> AssignTeachers(list<Subject> classList, Teacher arr[], int size) {
    list<Subject> :: iterator it;

    for (it = classList.begin(); it != classList.end(); ++it) {
        for (int i = 0; i < size; ++i) {
            it->Teacher.Id = arr[i].Id;
            it->Teacher.FirstName = arr[i].FirstName;
            it->Teacher.LastName = arr[i].LastName;
            it->Teacher.Subject = arr[i].Subject;
            break;
        }
    }

    return classList;
}

list<Student> GenerateStudents(int size){

    list<Student> studentList;

    // Build semi random list of students
    for(int i = 0; i < size; i++) {
        Student student = Student();
        student.Id = i + 1210;
        student.FirstName = GetFirstName(i);
        student.LastName = GetLastName(i);

        int age = rand() % 18 + 14;
        student.Age = age;

        try {
            if (student.Id == NULL) {
                throw student;
            }
        } catch (Student student) {
            cout << "Invalid Student object." << endl;
        }

        studentList.push_back(student);
    }

    return studentList;
}

list<Teacher> GenerateTeachers(int size) {

    list<Teacher> teacherList;

    // Build random list of teachers
    for (int i = 0; i < size; i++) {
        Teacher teacher = Teacher();
        int randomFirst = rand() % 36;
        int randomLast = rand() % 36;
        int subject = rand() % 5;
        teacher.Id = i + 32;
        teacher.FirstName = GetFirstName(randomFirst);
        teacher.LastName = GetLastName(randomLast);
        teacher.Subject = GetSchoolSubject(subject);

        try {
            if (teacher.Id == NULL) {
                throw teacher;
            }
        } catch (Teacher teacher) {
            cout << "Invalid Teacher object." << endl;
        }

        teacherList.push_back(teacher);
    }

    return teacherList;
}

int main()
{
    //Generate Student and Teacher rosters;
    list<Student> studentList = GenerateStudents(STUDENT_ROSTER_SIZE);
    list<Teacher> teacherList = GenerateTeachers(TEACHER_ROSTER_SIZE);
    Student studentArray[STUDENT_ROSTER_SIZE];
    Teacher teacherArray[TEACHER_ROSTER_SIZE];

    // build master list of school subjects
    list<Subject> masterList;
    masterList = BuildBusinessClasses(masterList);
    masterList = BuildEnglishClasses(masterList);
    masterList = BuildMathClasses(masterList);
    masterList = BuildScienceClasses(masterList);

    // assign a teacher to each one of the subjects
//    masterList = AssignTeachers(masterList, teacherArray, TEACHER_ROSTER_SIZE);

    // CODE LINE ABOVE IS NOT ITERATING THROUGH ALL TEACHERS AND ASSIGNING THEM TO A SUBJECT
    // RESULT 1 TEACHER -> ALL 8 SUBJECTS

    return 0;
}


