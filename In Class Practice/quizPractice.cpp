#include <iostream>
#include <string>

void func1(int arr[]) {
    std::cout << "Hello World" << std::endl;
    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    func1(arr);
    return 0;
}