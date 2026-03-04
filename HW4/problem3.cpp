#include <string>
#include <iostream>
using namespace std;

class Animal {
    private:
        string species;
    public:
        void setSpecies(string spc) {
            species = spc;
        }
        void printSpecies() {
            cout << species;
        }
};

class Dog : public Animal {
    private:
        string breed;
    public:
        void setBreed(string brd) {
            breed = brd;
        }
        void printBreed() {
            cout << breed << "." << endl;
        }
};

int main() {
    Dog myDog;
    myDog.setSpecies("Mammal");
    myDog.setBreed("Labrador");
    cout << "The species and breed of the dog are: ";
    myDog.printSpecies();
    cout << " & ";
    myDog.printBreed();
    return 0;
}