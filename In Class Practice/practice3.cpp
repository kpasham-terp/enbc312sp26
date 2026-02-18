#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ofstream fout;
    fout.open("example.txt");

    if (fout.is_open()) {
        fout << "Hello World";
        fout.close();
    }
    return 0;
}