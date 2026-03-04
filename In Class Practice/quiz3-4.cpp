#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        int age;
        void secretMethod() {
            cout << "This is a private method." << endl;
        }
    protected:
        string name;
    public:
        string gender;
        void setAge(int a) {
            age = a;
        }
        void setName(string n) {
            name = n;
        }
        void display() {
            cout << "Name: " << name << ". Age: " << age << ". Gender: " << gender << "." << endl;
        }
};

class Student : public Person {
    public:
        void changeName(string newName) {
            name = newName;
        }
        // void changeAge(int num) {
        //     age = num;
        //     // This type of variable change is deemed inaccessible (as it is a private int).
        // }
};

int main() {
    Student s;
    s.setName("John");
    s.setAge(20);
    s.gender = "Male";
    s.display();

    //Added these after compilation - errors thrown for public/private data types.
    // cout << s.name << endl;
    // cout << s.age << endl;
    // s.secretMethod();
    return 0;
}