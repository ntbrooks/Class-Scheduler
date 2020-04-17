#include <QtTest>
#include "student.h"

// add necessary includes here

class schedulerTest : public QObject
{
    Q_OBJECT

public:
    schedulerTest();
    ~schedulerTest();

private slots:
    void test_case1();

};

schedulerTest::schedulerTest()
{

}

schedulerTest::~schedulerTest()
{

}

void schedulerTest::test_case1()
{
    Student stud;
    Student student1(1, "Matt", "Holiday", 14, "Male");
    Student student2(2, "Jenny", "Smith", 15, "Female");
    list<Student> studentList;
    studentList.push_back(student1);
    studentList.push_back(student2);

    int id = 2;
    stud.GetStudent(studentList, id);

    QVERIFY(student2.Id == id);

}

QTEST_APPLESS_MAIN(schedulerTest)

#include "tst_schedulertest.moc"
