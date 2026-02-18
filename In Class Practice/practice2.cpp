#include <iostream>

int main() {
    int arr[5] = {400, 20, 5, -1, 2};
    int max = arr[0];
    for(int i = 1; i < 5; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    std::cout << "The largest number in the array is: " << max << std::endl;
}