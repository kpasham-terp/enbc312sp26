#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream fin;
    fin.open("example.txt");
    string line;

    if(fin.is_open()) {
        while (getline(fin, line)) cout << line << endl;
        fin.close();
    }
    return 0;
}