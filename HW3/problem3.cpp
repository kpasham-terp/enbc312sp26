#include <iostream>

void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + (size - 1);
    int temp;
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int arrayNums[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arrayNums) / sizeof(arrayNums[0]);
    reverseArray(arrayNums, size);
    for(int i = 0; i < size; i++) {
        std::cout << arrayNums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}