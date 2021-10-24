#include <iostream>
#include <vector>

class Matrix {
public:
	Matrix() {
		m_numRows = 0;
		m_numCols = 0;
	}

	Matrix(int num_rows, int num_columns) {
	    Reset(num_rows, num_columns);
	  }

	void Reset(int numRows, int numCols) {
		if (numRows < 0)
			throw std::out_of_range("numRows must be >= 0!");
		if (numCols < 0)
			throw std::out_of_range("numCols must be >= 0!");

		m_numRows = numRows;
		m_numCols = numCols;
		m_elements.assign(numRows, std::vector<int>(numCols));
	}

	int& At(int row, int col) {
		return m_elements.at(row).at(col);
	}

	int At(int row, int col) const {
		return m_elements.at(row).at(col);
	}

	int getRows() const {
		return m_numRows;
	}

	int getCols() const {
		return m_numCols;
	}

private:
	int m_numRows;
	int m_numCols;

	std::vector<std::vector<int>> m_elements;
};

bool operator == (const Matrix& one, const Matrix& two) {
	if (one.getRows() != two.getRows()) {
		return false;
	}
	if (one.getCols() != two.getCols()) {
		return false;
	}

	for (int row = 0; row < one.getRows(); ++row) {
		for (int col = 0; col < one.getCols(); ++col) {
			if (one.At(row, col) != two.At(row, col))
				return false;
		}
	}

	return true;
}

Matrix operator + (const Matrix& one, const Matrix& two) {
	if (one.getRows() != two.getRows())
		throw std::invalid_argument("Mismatched number of rows");
	if (one.getCols() != two.getCols())
		throw std::invalid_argument("Mismatched number of cols");

	Matrix result(one.getRows(), one.getCols());

	for (int row = 0; row < result.getRows(); ++row) {
		for (int col = 0; col < result.getCols(); ++col) {
			result.At(row, col) = one.At(row, col) + two.At(row, col);
		}
	}

	return result;
}

std::istream& operator >> (std::istream& input, Matrix& matrix) {
	int num_rows = 0;
	int num_cols = 0;

	input >> num_rows >> num_cols;
	matrix.Reset(num_cols, num_cols);

	for (int row = 0; row < num_rows; ++row) {
		for (int col = 0; col < num_cols; ++col) {
			input >> matrix.At(row, col);
		}
	}
	return input;
}

std::ostream& operator << (std::ostream& output, const Matrix& matrix) {
	output << matrix.getRows() << " " << matrix.getCols() << std::endl;

	for (int row = 0; row < matrix.getRows(); ++row) {
		for (int column = 0; column < matrix.getCols(); ++column) {
			if (column > 0) {
				output << " ";
			}
				output << matrix.At(row, column);
			}
		output << std::endl;
	}

	return output;
}

int main(int argc, char **argv) {
	Matrix one;
	Matrix two;

	std::cout << "Enter first matrix: ";
	std::cin >> one;
	std::cout << "Enter second matrix: ";
	std::cin >> two;

	Matrix three = one + two;

	std::cout << three;
	return 0;
}
