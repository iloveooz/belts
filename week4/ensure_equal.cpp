#include <iostream>
#include <exception>

void EnsureEqual(const std::string& str1, const std::string& str2) {
    if (str1 != str2)
        throw std::runtime_error(str1 + " != " + str2);
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
