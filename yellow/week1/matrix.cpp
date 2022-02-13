#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

// * класс Matrix
class Matrix {

};

// * оператор ввода для класса Matrix из потока istream
std::istream& operator >> (std::istream& stream, Matrix& matrix);

// * оператор вывода класса Matrix в поток ostream
std::ostream& operator << (std::ostream& stream, const Matrix& matrix);

// * оператор проверки на равенство двух объектов класса Matrix
bool operator == (const Matrix& lhs, const Matrix& rhs);

// * оператор сложения двух объектов класса Matrix
Matrix operator + (const Matrix& lhs, const Matrix& rhs);

int main() {
    Matrix one;
    Matrix two;

    std::cin >> one >> two;
    std::cout << one + two << std::endl;
    return 0;
}
