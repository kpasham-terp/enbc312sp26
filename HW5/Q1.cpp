#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string brand;
    string model;
    Vehicle(string b, string m) : brand(b), model(m) {}

    virtual void start_engine() {
        cout << brand << " " << model << "'s engine started." << endl;
    }
};

class Car : public Vehicle {
private:
    int num_doors;
public:
    Car(string b, string m, int n) : Vehicle(b, m), num_doors(n) {}
    void start_engine() {
        cout << brand << " " << model << " has " << num_doors << " doors and its engine started." << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool has_sidecar;
public:
    Motorcycle(string b, string m, bool s) : Vehicle(b, m), has_sidecar(s) {}
    void start_engine() {
        if (has_sidecar) {
            cout << brand << " " << model << "has sidecar and its engine started." << endl;
        }
        else {
            cout << brand << " " << model << "has NO sidecar and its engine started." << endl;
        }
    }
};

int main() {
    Vehicle myVehicle("Toyota", "Corolla");
    myVehicle.start_engine();
    Car myCar("Toyota", "Prius", 4);
    myCar.start_engine();
    Motorcycle myMotorcycle("Yamaha", "MX", false);
    myMotorcycle.start_engine();
    return 0;
}

