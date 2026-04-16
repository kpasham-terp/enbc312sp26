#include <iostream>
using namespace std;
#include <vector>

int main() {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(25);
    numbers.push_back(30);
    numbers.push_back(15);
    numbers.push_back(5);
    int sum = 0;
    int maxVal = 0;
    std::cout << "Numbers in vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
        sum += num;
        if(maxVal < num) {
            maxVal = num;
        }
    }
    std::cout << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Maximum value: " << maxVal << std::endl;

    return 0;
}