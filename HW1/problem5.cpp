#include <iostream>
#include <string>

int main() {
	int value;
    int sum = 0;

    std::cout << "Enter integers. Type any letter when you are done entering numbers." << std::endl;
    while (std::cin >> value) {
        sum = sum + value;
    }
    std::cout << "This is the sum: " << sum << std::endl;
	return 0;
}