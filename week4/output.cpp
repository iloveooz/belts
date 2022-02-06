#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ifs;
    std::ofstream ofs;

    std::string line;

    ifs.open("input.txt");
    ofs.open("output.txt");

    if (ifs.is_open() && ofs.is_open()) {
        while(std::getline(ifs, line)) {
            ofs << line << std::endl;

        }
    } else {
        throw std::runtime_error("Error! Can't open input or output file!");
    }
    ifs.close();
    ofs.close();

    return 0;
}
