#include <iostream>
#include <string>

void computeEquation() {
    int a;
    int b;
    std::cout << "Enter an integer 'a':";
    std::cin >> a;
    std::cout << "Enter an integer 'b':";
    std::cin >> b;
    int output = a * b + 200;
    std::cout << "The output is: " << output << std::endl;
}

int main() {
	for (int i = 0; i < 3; i++) {
 		computeEquation();
	}
	return 0;
}
