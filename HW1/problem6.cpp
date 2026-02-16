#include <iostream>
#include <string>

void printNumbers() {
    int a;
    int b;
    std::cout << "Enter an integer 'a':";
    std::cin >> a;
    std::cout << "Enter an integer 'b':";
    std::cin >> b;
    if (a >= b) {
        std::cout << "Error: b must be greater than a." << std::endl;
    }
    else {
        a++;
        while (a < b) {
            std::cout << a << std::endl;
            a++;
        }
    }
}

int main() {
 	printNumbers();
	return 0;
}