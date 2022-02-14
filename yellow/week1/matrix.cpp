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
        Reset(rows, cols);
    }

    int At(int numRow, int numCol) const {
        return m_elements.at(numRow).at(numCol);
    }

    int& At(int numRow, int numCol) {
        return m_elements.at(numRow).at(numCol);
    }

    int GetNumRows() const {
        return num_rows;
    }

    int GetNumColumns() const {
        return num_cols;
    }

    std::vector<std::vector<int>> getElements() const {
        return m_elements;
    }

    void Reset(int rows, int cols) {
        if (rows < 0)
            throw std::out_of_range("num_rows must be >= 0");
        if (cols < 0)
            throw std::out_of_range("num_cols must be >= 0");
        if (rows == 0 or cols == 0) {
            rows = 0;
            cols = 0;
        }
        num_rows = rows;
        num_cols = cols;
        m_elements.assign(rows, std::vector<int>(cols));
    }

private:
    int num_rows;
    int num_cols;

    std::vector<std::vector<int>> m_elements;
};

// * оператор ввода для класса Matrix из потока istream
std::istream& operator >> (std::istream& stream, Matrix& matrix) {
    int rows = 0;
    int cols = 0;
    stream >> rows >> cols;

    matrix.Reset(rows, cols);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            stream >> matrix.At(row, col);
        }
    }

    return stream;
}

// * оператор вывода класса Matrix в поток ostream
std::ostream& operator << (std::ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << std::endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int col = 0; col < matrix.GetNumColumns(); ++col) {
            if (col > 0)
                stream << ' ';
            stream << matrix.At(row, col);
        }
        stream << std::endl;
    }
    return stream;
}

// * оператор проверки на равенство двух объектов класса Matrix
bool operator == (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows())
        return false;
    if (lhs.GetNumColumns() != rhs.GetNumColumns())
        return false;

    for (int row = 0; row < lhs.GetNumRows(); ++row) {
        for (int col = 0; col < lhs.GetNumColumns(); ++col) {
            if (lhs.At(row, col) != rhs.At(row, col)) {
                return false;
            }
        }
    }
    return true;
}

// * оператор сложения двух объектов класса Matrix
Matrix operator + (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows())
        throw std::invalid_argument("Mismatched number of rows");
    if (lhs.GetNumColumns() != rhs.GetNumColumns())
        throw std::invalid_argument("Mismatched number of columns");

    Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int col = 0; col < result.GetNumColumns(); ++col) {
            result.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
            }
        }
    return result;
}

int main() {
    Matrix one;
    Matrix two;

    std::cin >> one >> two;
    std::cout << one + two << std::endl;

    return 0;
}
