// ReSharper disable CommentTypo
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

// * класс Matrix
class Matrix {
public:
    Matrix() {
        num_rows = 0;
        num_cols = 0;
    }

    Matrix(int rows, int cols) {
        num_rows = rows;
        num_cols = cols;
    }

    int getRows() const {
        return num_rows;
    }

    int getCols() const {
        return num_cols;
    }
    
    std::vector<std::vector<int>> getElements() const {
        return m_elements;
    }
private:
    int num_rows;
    int num_cols;

    std::vector<std::vector<int>> m_elements;
};

// * оператор ввода для класса Matrix из потока istream
std::istream& operator >> (std::istream& stream, Matrix& matrix);

// * оператор вывода класса Matrix в поток ostream
std::ostream& operator << (std::ostream& stream, const Matrix& matrix) {
    for (const auto& entry : matrix.getElements()) {
        for (const auto& item : entry) {
            stream << item;
            if (item != entry.back())
				stream << ' ';
        }
        stream << std::endl;
    }
    return stream;
}

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
