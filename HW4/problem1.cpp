#include <string>
#include <iostream>

class Car {
    public:
        std::string brand;
        int year;
    
        void setBrand(std::string str) {
            brand = str;
        }
        void setYear(int yr) {
            year = yr;
        }
};

int main() {
    Car car1;
    car1.setBrand("Toyota");
    car1.setYear(2020);
    std::cout << "Brand of car: " << car1.brand << ". Year of car: " << car1.year << "." << std::endl;
    return 0;
}