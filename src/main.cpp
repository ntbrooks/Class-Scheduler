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

// list of first names
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

// list of last names
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

// list of school subjects
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

    int size = (STUDENT_ROSTER_SIZE / 2);
    Subject BUS111 = Subject(111, "Intro to Business", 90, size);
    Subject ACC112 = Subject(122, "Intro to Accounting", 90, size);
    classList.push_back(BUS111);
    classList.push_back(ACC112);

    return classList;
}

// define English classes and return list of classes
list<Subject> BuildEnglishClasses(list<Subject> classList) {

    int size = (STUDENT_ROSTER_SIZE / 2);
    Subject ENG216 = Subject(216, "English", 90, size);
    Subject ENG238 = Subject(238, "U.S. History", 90, size);
    classList.push_back(ENG216);
    classList.push_back(ENG238);

    return classList;
}

// define Math classes and return list of classes
list<Subject> BuildMathClasses(list<Subject> classList) {

    int size = (STUDENT_ROSTER_SIZE / 2);
    Subject MTH302 = Subject(302, "Algebra", 90, size);
    Subject MTH341 = Subject(341, "Statistics", 90, size);
    classList.push_back(MTH302);
    classList.push_back(MTH341);

    return classList;
}

// define Science classes and return list of classes
list<Subject> BuildScienceClasses(list<Subject> classList) {

    int size = (STUDENT_ROSTER_SIZE / 2);
    Subject SCI421 = Subject(421, "Biology", 90, size);
    Subject SCI431 = Subject(431, "Chemistry", 90, size);
    classList.push_back(SCI421);
    classList.push_back(SCI431);

    return classList;
}

// Assign a teacher to each one of the classes available
list<Subject> AssignTeachersToClass(list<Subject> classList, list<Teacher> teacherList) {
    list<Subject> :: iterator it;
    list<Teacher> :: iterator lit;
    Teacher teacherArr[teacherList.size()];
    int i = 0;

    for(lit = teacherList.begin(); lit != teacherList.end(); ++lit) {
        teacherArr[i].Id = lit->Id;
        teacherArr[i].FirstName = lit->FirstName;
        teacherArr[i].LastName = lit->LastName;
        teacherArr[i].Subject = lit->Subject;
        ++i;
    }

    i = 0;
    for (it = classList.begin(); it != classList.end(); ++it) {
            it->Teacher.Id = teacherArr[i].Id;
            it->Teacher.FirstName = teacherArr[i].FirstName;
            it->Teacher.LastName = teacherArr[i].LastName;
            it->Teacher.Subject = teacherArr[i].Subject;
            ++i;
    }

    return classList;
}

// Distribute the students evenly between each subject
list<Subject> AssignStudentsToClass(list<Subject> classList, list<Student> studentList) {
    list<Subject> :: iterator it;
    list<Student> :: iterator lit;
    int size = (studentList.size() / 2);
    Student studentClass1[size];
    Student studentClass2[size];
    int i = 0;
    int k = 0;

    for(lit = studentList.begin(); lit != studentList.end(); ++lit) {

        if (i < size) {
            studentClass1[i].Id = lit->Id;
            studentClass1[i].FirstName = lit->FirstName;
            studentClass1[i].LastName = lit->LastName;
            studentClass1[i].Age = lit->Age;
            ++i;
        } else {

            if (k == size) {
                break;
            }

            studentClass2[k].Id = lit->Id;
            studentClass2[k].FirstName = lit->FirstName;
            studentClass2[k].LastName = lit->LastName;
            studentClass2[k].Age = lit->Age;
            ++k;
        }
    }

    int counter = 0;
    for (it = classList.begin(); it != classList.end(); ++it) {

            if (counter % 2 == 0) {
                for (int i = 0; i < size; ++i) {
                   it->Roster.push_back(studentClass1[i]);
                }
            } else {
                for (int k = 0; k < size; ++k) {
                    it->Roster.push_back(studentClass2[k]);
                }
            }

        ++counter;
    }

    // I know this method is ugly, C++ is not my forte.
    return classList;
}

// randomly generate students from list of names
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

// randomly generate teachers from list of names
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

// run at startup to build objects of students/teachers/school subjects
list<Subject> StartUp() {

    //Generate Student and Teacher rosters;
    list<Student> studentList = GenerateStudents(STUDENT_ROSTER_SIZE);
    list<Teacher> teacherList = GenerateTeachers(TEACHER_ROSTER_SIZE);

    // build master list of school subjects
    list<Subject> masterList;
    masterList = BuildBusinessClasses(masterList);
    masterList = BuildEnglishClasses(masterList);
    masterList = BuildMathClasses(masterList);
    masterList = BuildScienceClasses(masterList);

    // assign a teacher to each one of the subjects
    masterList = AssignTeachersToClass(masterList, teacherList);

    // assign students to each on of the classes
    masterList = AssignStudentsToClass(masterList, studentList);

    return masterList;
}

void PrintClassInfo(list<Subject> masterList) {
    list<Subject> :: iterator it;
    list<Student> :: iterator lit;

    for (it = masterList.begin(); it != masterList.end(); ++it) {
        cout << "-------- Course Info -------" << endl;
        cout << "Id: " << it->CourseId << endl;
        cout << "Name: " << it->CourseName << endl;
        cout << "Length: " << it->ClassTime << "minutes" << endl;
        cout << "Roster Size: " << it->ClassSize << endl;

        cout << "" << endl;
        cout << "-------- Teacher Info --------" << endl;
        cout << "Id: " << it->Teacher.Id << endl;
        cout << "Name: " << it->Teacher.FirstName << " " << it->Teacher.LastName << endl;
        cout << "Subject Taught: " << it->Teacher.Subject << endl;

        cout << "" << endl;
        cout << "-------- Student Info --------" << endl;
        for (lit = it->Roster.begin(); lit != it->Roster.end(); ++lit) {
            cout << "Id: " << lit->Id << " Name: " << lit->FirstName << " " << lit->LastName << " Age: " << lit->Age << endl;
        }
        cout << "" << endl;
    }
}

int main()
{
    list<Subject> masterList = StartUp();

    PrintClassInfo(masterList);

    return 0;
}


