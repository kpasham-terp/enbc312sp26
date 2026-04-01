#include <iostream>
using namespace std;

class Person {
private:
    string ssn;
protected:
    string name;
    int age;
public:
    Person(string social, int personAge, string personName) {
        ssn = social;
        age = personAge;
        name = personName;
    }
    void display() {
        cout << ssn << age << name << endl;
    }
};

class Student : public Person {
private:
    int studentID;
protected:
    string major;
public:
    Student(string social, int personAge, string personName, string personMajor, int ID) : Person(social, personAge, personName) {
        major = personMajor;
        studentID = ID;
    }
    void display() {
        Person::display();
        cout << major << studentID << endl;
    }
};

class Teacher : public Person {
private:
    double salary;
protected:
    string subject;
public:
    Teacher(string social, int personAge, string personName, double teachSalary, string teachSubject) : Person(social, personAge, personName) {
        salary = teachSalary;
        subject = teachSubject;
    }
    void display() {
        Person::display();
        cout << salary << subject << endl;
    }
};