#include <iostream>

void calculateGrade() {
    int grade;
    std::cout << "Enter the numerical grade of the student:" << std::endl;
    std::cin >> grade;
    if(grade >= 90) {
        std::cout << "The student's grade is an A." << std::endl;
    }
    else if (grade >= 80) {
        std::cout << "The student's grade is a B." << std::endl;
    }
    else if (grade >= 70) {
        std::cout << "The student's grade is a C." << std::endl;
    }
    else if (grade >= 60) {
        std::cout << "The student's grade is a D." << std::endl;
    }
    else {
        std::cout << "The student's grade is an F." << std::endl;
    }
}

int main() {
    calculateGrade();
    return 0;
}