#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Woof" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Meow" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); 
    a2->speak(); 

    vector<Animal*> animals;

    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (Animal* a : animals) {
        a->speak();
    }
    return 0;
}