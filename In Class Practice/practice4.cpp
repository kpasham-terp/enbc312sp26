#include <iostream>
using namespace std;

struct child {
    int age;
    string name;
    string mother;
    string father;
};

int main(void) {
    child c1;

    c1.age = 5;
    c1.name = "Bobby";
    c1.mother = "Mary";
    c1.father = "Robert";

    cout << "age: " << c1.age << ", name: " << c1.name << ", mother: " << c1.mother << ", father: " <<c1.father << endl;
}