// ReSharper disable CommentTypo
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

// * класс Matrix
class Matrix {
public:
    Matrix() {
        num_rows = 10;
        num_cols = 10;
        Reset(num_rows, num_cols);
    }

    Matrix(int rows, int cols) {
        num_rows = rows;
        num_cols = cols;
        Reset(num_rows, num_cols);
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
    void Reset(int rows, int cols) {
	    if (rows < 0)
            throw std::out_of_range("num_rows must be >= 0");
        if (cols < 0)
            throw std::out_of_range("num_rows must be >= 0");
        if (rows == 0 and cols == 0) {
            num_rows = 0;
            num_cols = 0;
        }
        m_elements.assign(num_rows, std::vector<int>(num_cols));
    }

    int num_rows;
    int num_cols;

    std::vector<std::vector<int>> m_elements;
};

// * оператор ввода для класса Matrix из потока istream
std::istream& operator >> (std::istream& stream, Matrix& matrix);

// * оператор вывода класса Matrix в поток ostream
std::ostream& operator << (std::ostream& stream, const Matrix& matrix) {
    for (int col = 0; col < matrix.getRows(); ++col) {
        for (int row = 0; row < matrix.getCols(); ++row) {
            stream << matrix.getElements()[col][row];
            if (row > 0)
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

    // std::cin >> one >> two;
    std::cout << one << std::endl;
    system("pause");
    return 0;
}
