#include <iostream>
#include <string>
using namespace std;
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* p1 = arr;
    int* p4 = arr + 3;

    int temp = *p1;
    *p1 = *p4;
    *p4 = temp;
    
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    string arr2[5] = {"H", "E", "L", "L", "O"};
    string* p1 = arr2;
    string* p4 = arr2 + 3;

    int temp = *p1;
    *p1 = *p4;
    *p4 = temp;
    
    for(int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}