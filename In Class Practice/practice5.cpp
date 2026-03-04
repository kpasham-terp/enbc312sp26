#include <string>
#include <iostream>

class MyClass {
    public:
        int var1 = 0;
    private:
        int var2 = 1;
};

int main() {
    MyClass class1;
    std::cout << class1.var1 << std::endl;
    // std::cout << class1.var2 << std::endl;
    return 0;
}