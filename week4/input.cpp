#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ifs;
    std::string line;

    ifs.open("input.txt");

    if (ifs.is_open()) {
        while(std::getline(ifs, line)) {
            std::cout << line << std::endl;

        }
    } else {
        throw std::runtime_error("Error! Can't open input file!");
    }
    ifs.close();
    return 0;
}
