#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int placeholder = arr[1];
    *(arr+1) = arr[3];
    *(arr+3) = placeholder;
    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}