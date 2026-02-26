#include <iostream>
using namespace std;
void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int input1;
    int input2;
    cout << "Enter the first number: " << endl;
    cin >> input1;
    cout << "Enter the second number: " << endl;
    cin >> input2;
    cout << "Before running the method, a is: " << input1 << " and b is: " << input2 << "." << endl;
    swapNumbers(&input1, &input2);
    cout << "After running the method, a is: " << input1 << " and b is: " << input2 << "." << endl;
    return 0;
}