#include <iostream>
using namespace std;

void printValues(int n) {
    int* myArray = new int[n];
    for (int i = 0; i < n; i++) {
        myArray[i] = i+1;
    }

    for (int i = 0; i < n; i++) {
        cout << myArray[i] << " ";
    }
    cout << "" << endl;
    delete[] myArray;
}

int main() {
    int input;
    cout << "enter a number to be used for printing" << endl;
    cin >> input;
    printValues(input);
    return 0;
}