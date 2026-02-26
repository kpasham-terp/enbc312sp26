#include <iostream>
using namespace std;
int main() {
    int arr[2] = {};
    int sum = 0;
    cout << "Enter the first number: " << endl;
    cin >> arr[0];
    cout << "Enter the second number: " << endl;
    cin >> arr[1];
    //cout << arr[0] << arr[1] << endl;
    int* ptr = arr;
    for(int i = 0; i < 2; i++) {
        sum += *(ptr + i);
    }
    cout << "This is the sum of the two integers you have asked for: " << sum << endl;
    return 0;
}