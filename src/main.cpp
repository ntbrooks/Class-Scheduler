#include <string>
#include <iostream>
#include "student.h"
#include "teacher.h"

using namespace std;

int main()
{
    const int STUDENT_ROSTER_SIZE = 36;
    const int TEACHER_ROSTER_SIZE = 8;
    const int SUBJECTS_TAUGHT = 4;
    Student* studentArray[STUDENT_ROSTER_SIZE];
    Teacher* teacherArray[TEACHER_ROSTER_SIZE];
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
    string schoolSubjects[SUBJECTS_TAUGHT] {
        "Business",
        "English",
        "Math",
        "Science",
    };

    // Build semi random list of students
    for(int i = 0; i < STUDENT_ROSTER_SIZE; i++) {
        Student* student = new Student();
        student -> Id = i + 1210;
        student -> FirstName = fNameArray[i];
        student -> LastName = lNameArray[i];

        int age = rand() % 18 + 14;
        student -> Age = age;

        try {
            if (!student) {
                throw student;
            }
        } catch (Student student) {
            cout << "Invalid Student object." << endl;
        }

        studentArray[i] = student;
    }

    cout << "Hello" << endl;

    // Build random list of teachers
    for (int i = 0; i < TEACHER_ROSTER_SIZE; i++) {
        Teacher* teacher = new Teacher();
        int randomFirst = rand() % 36;
        int randomLast = rand() % 36;
        int subject = rand() % 5;
        teacher -> Id = i + 32;
        teacher -> FirstName = fNameArray[randomFirst];
        teacher -> LastName = lNameArray[randomLast];
        teacher -> Subject = schoolSubjects[subject];

        try {
            if (!teacher) {
                throw teacher;
            }
        } catch (Teacher teacher) {
            cout << "Invalid Student object." << endl;
        }

        teacherArray[i] = teacher;
    }



    return 0;
}
