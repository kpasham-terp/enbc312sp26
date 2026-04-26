#include <iostream>
#include <string>
#include <vector>

class Person {
protected:
    std::string name;
    std::string email;

public:
    Person(std::string n, std::string e) : name(n), email(e) {}
    virtual ~Person() {}

    virtual std::string to_string() const {
        return "Name: " + name + ", Email: " + email;
    }
};

class Student : public Person {
private:
    std::string student_id;
    std::string major;

public:
    Student(std::string n, std::string e, std::string s_id, std::string m) 
        : Person(n, e), student_id(s_id), major(m) {}

    std::string to_string() const override {
        return "[Student] - " + Person::to_string() + 
               ", Student ID: " + student_id + ", Major: " + major;
    }
};

class Professor : public Person {
private:
    std::string employee_id;
    std::string department;

public:
    Professor(std::string n, std::string e, std::string e_id, std::string dept) 
        : Person(n, e), employee_id(e_id), department(dept) {}

    std::string to_string() const override {
        return "[Professor] - " + Person::to_string() + ", Employee ID: " + employee_id + ", Dept: " + department;
    }
};

int main() {
    std::vector<Person*> directory;

    directory.push_back(new Student("Alice Smith", "alice@uni.edu", "S10293", "Computer Science"));
    directory.push_back(new Professor("Dr. Bob Jones", "bjones@uni.edu", "P99482", "Mathematics"));

    for (const Person* person : directory) {
        std::cout << person->to_string() << std::endl;
    }

    for (Person* person : directory) {
        delete person;
    }

    return 0;
}