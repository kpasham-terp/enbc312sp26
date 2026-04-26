#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(25);
    v.push_back(15);
    for (int x : v) {
        cout << x << endl;
    }
    cout << v.size() << endl;
    return 0;
}