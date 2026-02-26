#include <iostream>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* p2 = arr + 1;
    int* p4 = arr + 3;

    int temp = *p2;
    *p2 = *p4;
    *p4 = temp;
    
    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}