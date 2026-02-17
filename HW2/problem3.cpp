#include <iostream>
#include <string>
#include <algorithm>
void MostCommonLetter(std::string text) {
    int freq[256] = {0};
    for (char c : text) {
        freq[(unsigned char)c]++;
    }
    int* maxPointer = std::max_element(freq, freq + 256);
    char maxChar = (char)(maxPointer - freq);
    int maxCount = *maxPointer;

    std::cout << "The character '" << maxChar << "' appears " << maxCount << " times, which is the highest frequency in the string." << std::endl;
}

int main() {
    std::string text;
    std::cout << "Enter a string to find out which character is repeated the most:" << std::endl;
    std::cin >> text;
    MostCommonLetter(text);
    return 0;
}