#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Car {
private:
protected:
    int id;
    string name;
    int year;
    string color;
    double dailyRate;
    bool available;
    string renterName;
    string rentStart;
    string rentEnd;

public:
    Car(int id, string name, int year, string color, double dailyRate) : 
    id(id), name(name), year(year), color(color), dailyRate(dailyRate),
    available(true), renterName(""), rentStart(""), rentEnd("") {}

    virtual ~Car() {}

    virtual string getType() const = 0;

    void display() const {
        cout << "Car Stats:" << endl;
        cout << "ID    : " << id << endl;
        cout << "Name  : " << name << endl;
        cout << "Type  : " << getType() << endl;
        cout << "Year  : " << year << "  |  Color: " << color << endl;
        cout << "Rate  : $" << dailyRate << "/day" << endl;
        if (available) {
            cout << "Status: Available" << endl;
        } else {
            cout << "Status: RENTED" << endl;
            cout << "Renter: " << renterName << endl;
            cout << "From  : " << rentStart << "  To: " << rentEnd << endl;
        }
    }

    int getID() { return id; }
    string getName() { return name; }
    bool isAvailable() { return available; }
    string getRentStart() { return rentStart; }
    string getRentEnd() { return rentEnd; }
    string getRenterName() { return renterName; }

    void rentOut(string renter, string start, string end) {
        available  = false;
        renterName = renter;
        rentStart  = start;
        rentEnd    = end;
    }

    void returnCar() {
        available  = true;
        renterName = "";
        rentStart  = "";
        rentEnd    = "";
    }
};

class Sedan : public Car {
private:
    int numDoors;
public:
    Sedan(int id, string name, int year, string color, double dailyRate, int numDoors)
        : Car(id, name, year, color, dailyRate), numDoors(numDoors) {}
    string getType() const override { return "Sedan"; }
    int getNumDoors() const { return numDoors; }
};

class SUV : public Car {
private:
    int seatingCapacity;
public:
    SUV(int id, string name, int year, string color, double dailyRate, int seatingCapacity)
        : Car(id, name, year, color, dailyRate), seatingCapacity(seatingCapacity) {}
    string getType() const override { return "SUV"; }
    int getSeatingCapacity() const { return seatingCapacity; }
};

class Truck : public Car {
private:
    double payloadTons;
public:
    Truck(int id, string name, int year, string color, double dailyRate, double payloadTons)
        : Car(id, name, year, color, dailyRate), payloadTons(payloadTons) {}
    string getType() const override { return "Truck"; }
    double getPayloadTons() const { return payloadTons; }
};

class Motorcycle : public Car {
private:
    bool hasSidecar;
public:
    Motorcycle(int id, string name, int year, string color, double dailyRate, bool hasSidecar)
        : Car(id, name, year, color, dailyRate), hasSidecar(hasSidecar) {}
    string getType() const override { return "Motorcycle"; }
    bool getHasSidecar() const { return hasSidecar; }
};

class Sports_Car : public Car {
private:
    int horsepower;
public:
    Sports_Car(int id, string name, int year, string color, double dailyRate, int horsepower)
        : Car(id, name, year, color, dailyRate), horsepower(horsepower) {}
    string getType() const override { return "Sports Car"; }
    int getHorsepower() const { return horsepower; }
};

vector<Car*> fleet;
int nextID = 1;

Car* findByID(int targetID) {
    for (Car* c : fleet) {
        if (c->getID() == targetID) return c;
    }
    return nullptr;
}

void registerCar() {
    cout << "\nSelect car type:" << endl;
    cout << "  1. Sedan" << endl;
    cout << "  2. SUV" << endl;
    cout << "  3. Truck" << endl;
    cout << "  4. Motorcycle" << endl;
    cout << "  5. Sports Car" << endl;
    cout << "Choice: ";
    int typeChoice;
    cin >> typeChoice;

    if (typeChoice < 1 || typeChoice > 5) {
        cout << "Invalid type." << endl;
        return;
    }

    string name, color;
    int year;
    double dailyRate;

    cin.ignore();
    cout << "Car name/model: ";
    getline(cin, name);
    cout << "Year          : ";
    cin >> year;
    cin.ignore();
    cout << "Color         : ";
    getline(cin, color);
    cout << "Daily rate ($): ";
    cin >> dailyRate;

    int assignedID = nextID++;

    if (typeChoice == 1) {
        int doors;
        cout << "Number of doors: ";
        cin >> doors;
        fleet.push_back(new Sedan(assignedID, name, year, color, dailyRate, doors));
    } else if (typeChoice == 2) {
        int seats;
        cout << "Seating capacity: ";
        cin >> seats;
        fleet.push_back(new SUV(assignedID, name, year, color, dailyRate, seats));
    } else if (typeChoice == 3) {
        double payload;
        cout << "Payload capacity (tons): ";
        cin >> payload;
        fleet.push_back(new Truck(assignedID, name, year, color, dailyRate, payload));
    } else if (typeChoice == 4) {
        int sc;
        cout << "Has sidecar? (1=Yes 0=No): ";
        cin >> sc;
        fleet.push_back(new Motorcycle(assignedID, name, year, color, dailyRate, sc == 1));
    } else {
        int hp;
        cout << "Horsepower: ";
        cin >> hp;
        fleet.push_back(new Sports_Car(assignedID, name, year, color, dailyRate, hp));
    }

    cout << "Car registered with ID: " << assignedID << endl;
}

void deregisterCar() {
    cout << "\nEnter Car ID to deregister: ";
    int targetID;
    cin >> targetID;

    for (int i = 0; i < (int)fleet.size(); i++) {
        if (fleet[i]->getID() == targetID) {
            delete fleet[i];
            fleet.erase(fleet.begin() + i);
            cout << "Car deregistered successfully." << endl;
            return;
        }
    }
    cout << "Car ID not found." << endl;
}

void rentCar() {
    cout << "\nEnter Car ID to rent: ";
    int targetID;
    cin >> targetID;

    Car* car = findByID(targetID);
    if (!car) {
        cout << "Car ID not found." << endl;
        return;
    }
    if (!car->isAvailable()) {
        cout << "Car is already rented out." << endl;
        return;
    }

    string renter, start, end;
    cin.ignore();
    cout << "Renter name                  : ";
    getline(cin, renter);
    cout << "Rent start date  (YYYY-MM-DD): ";
    cin >> start;
    cout << "Rent return date (YYYY-MM-DD): ";
    cin >> end;

    car->rentOut(renter, start, end);
    cout << "Car successfully rented to " << renter << "." << endl;
}

void returnCar() {
    cout << "\nEnter Car ID to return: ";
    int targetID;
    cin >> targetID;

    Car* car = findByID(targetID);
    if (!car) {
        cout << "Car ID not found." << endl;
        return;
    }
    if (car->isAvailable()) {
        cout << "Car is not currently rented." << endl;
        return;
    }

    car->returnCar();
    cout << "Car returned successfully." << endl;
}

void listCars() {
    if (fleet.empty()) {
        cout << "\nNo cars registered." << endl;
        return;
    }
    cout << "\n========== All Cars ==========" << endl;
    for (Car* car : fleet) {
        car->display();
    }
    cout << "-----------------------------------" << endl;
}

void sortCars() {
    if (fleet.empty()) {
        cout << "\nNo cars to sort." << endl;
        return;
    }

    cout << "\nSort by:" << endl;
    cout << "  1. Rent Start Date" << endl;
    cout << "  2. Rent Return Date" << endl;
    cout << "  3. Car Name" << endl;
    cout << "  4. Car Type" << endl;
    cout << "Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        sort(fleet.begin(), fleet.end(), [](Car* a, Car* b) {
            return a->getRentStart() < b->getRentStart();
        });
        cout << "Sorted by rent start date." << endl;
    } else if (choice == 2) {
        sort(fleet.begin(), fleet.end(), [](Car* a, Car* b) {
            return a->getRentEnd() < b->getRentEnd();
        });
        cout << "Sorted by rent return date." << endl;
    } else if (choice == 3) {
        sort(fleet.begin(), fleet.end(), [](Car* a, Car* b) {
            return a->getName() < b->getName();
        });
        cout << "Sorted by car name." << endl;
    } else if (choice == 4) {
        sort(fleet.begin(), fleet.end(), [](Car* a, Car* b) {
            return a->getType() < b->getType();
        });
        cout << "Sorted by car type." << endl;
    } else {
        cout << "Invalid sort option." << endl;
        return;
    }

    listCars();
}

int main() {
    int choice;

    while (true) {
        cout << "    Car Rental Management System\n" << endl;
        cout << "  1. Register a Car" << endl;
        cout << "  2. Deregister a Car" << endl;
        cout << "  3. Rent a Car" << endl;
        cout << "  4. Return a Car" << endl;
        cout << "  5. List All Cars" << endl;
        cout << "  6. Sort Cars" << endl;
        cout << "  0. Exit\n" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerCar();   break;
            case 2: deregisterCar(); break;
            case 3: rentCar();       break;
            case 4: returnCar();     break;
            case 5: listCars();      break;
            case 6: sortCars();      break;
            case 0:
                for (Car* c : fleet) delete c;
                fleet.clear();
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }
}
