#include <iostream>

int main() {
    // Using for loop
    for (int i = 0; i < 100; i++) {
        std::cout << "Hello World " << i+1 << std::endl;
    }

    // Using while loop
    int count = 0;
    while (count < 100) {
        std::cout << "Hello World " << count+1 << std::endl;
        count++;
    }

    // Using do-while loop
    count = 1;
    do {
        std::cout << "Hello World " << count << std::endl;
        count++;
    } while (count <= 100);
    return 0;
}