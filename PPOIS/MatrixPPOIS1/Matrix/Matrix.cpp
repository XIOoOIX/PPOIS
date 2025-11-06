#include "Matrix.h"
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//По умолчанию
Matrix::Matrix()
    : rowCount(0), columnCount(0), dataMatrix()
{}

//С размерами
Matrix::Matrix(std::size_t rowCount, std::size_t columnCount)
    : rowCount(rowCount), columnCount(columnCount),
    dataMatrix(rowCount, std::vector<double>(columnCount, 0.0))
{}

//Копирование
Matrix::Matrix(const Matrix& other)
    : rowCount(other.rowCount), columnCount(other.columnCount),
    dataMatrix(other.dataMatrix)
{}

//Присваивание
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rowCount = other.rowCount;
        columnCount = other.columnCount;
        dataMatrix = other.dataMatrix;
    }
    return *this;
}

//Получить число строк
std::size_t Matrix::getRowCount() const {
    return rowCount;
}

//Получить число столбцов
std::size_t Matrix::getColumnCount() const {
    return columnCount;
}

//Получить элемент
double Matrix::getElement(std::size_t row, std::size_t col) const {
    if (row >= rowCount || col >= columnCount) {
        throw std::out_of_range("Row or column index out of range");
    }
    return dataMatrix[row][col];
}

//Установить элемент
void Matrix::setElement(std::size_t row, std::size_t col, double value) {
    if (row >= rowCount || col >= columnCount) {
        throw std::out_of_range("Row or column index out of range");
    }
    dataMatrix[row][col] = value;
}

//Изменить размер
Matrix Matrix::resize(int newRowCount, int newColumnCount) const {
    if (newRowCount <= 0 || newColumnCount <= 0) {
        throw std::invalid_argument("Matrix sizes must be positive.");
    }
    Matrix newMatrix(newRowCount, newColumnCount);
    for (int i = 0; i < rowCount && i < newRowCount; ++i) {
        for (int j = 0; j < columnCount && j < newColumnCount; ++j) {
            newMatrix.dataMatrix[i][j] = dataMatrix[i][j];
        }
    }
    return newMatrix;
}

//Подматрица
Matrix Matrix::getSubmatrix(int startRow, int startCol, int subRows, int subCols) const {
    if (startRow < 0 || startCol < 0 || subRows <= 0 || subCols <= 0) {
        throw std::invalid_argument("Submatrix sizes must be positive.");
    }
    if (startRow + subRows > rowCount || startCol + subCols > columnCount) {
        throw std::out_of_range("Submatrix exceeds matrix boundaries.");
    }

    Matrix submatrix(subRows, subCols);
    for (int i = 0; i < subRows; ++i) {
        for (int j = 0; j < subCols; ++j) {
            submatrix.dataMatrix[i][j] = dataMatrix[startRow + i][startCol + j];
        }
    }

    return submatrix;
}

Matrix Matrix::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file.");
    }

    std::string line;
    std::size_t rows = 0, cols = 0;
    if (!std::getline(file, line)) {
        throw std::runtime_error("File is empty.");
    }

    {
        std::istringstream size_stream(line);
        if (!(size_stream >> rows >> cols)) {
            throw std::runtime_error("Invalid format");
        }
    }

    if (rows == 0 || cols == 0) {
        throw std::runtime_error("The matrix dimensions must be positive.");
    }

    Matrix result(rows, cols);

    std::size_t current_row = 0;
    while (std::getline(file, line) && current_row < rows) {
        if (line.empty()) {
            continue;
        }
        std::istringstream data_stream(line);
        double value;
        std::size_t current_col = 0;
        while (data_stream >> value && current_col < cols) {
            result.dataMatrix[current_row][current_col] = value;
            ++current_col;
        }
        if (current_col != cols) {
            throw std::runtime_error("Not enough data in the row");
        }
        ++current_row;
    }

    if (current_row != rows) {
        throw std::runtime_error("Not enough rows.");
    }

    file.close();
    return result;
}


//Характеристики матрицы
bool Matrix::isSquare() const {
    return rowCount == columnCount;
}

bool Matrix::isDiagonal() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < columnCount; ++j) {
            if (i != j && dataMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isZero() const {
    for (const auto& row : dataMatrix) {
        for (double value : row) {
            if (value != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isIdentity() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < columnCount; ++j) {
            if ((i == j && dataMatrix[i][j] != 1) || (i != j && dataMatrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetric() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = i + 1; j < columnCount; ++j) {
            if (dataMatrix[i][j] != dataMatrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isUpperTriangular() const {
    if (!isSquare()) return false;
    for (int i = 1; i < rowCount; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dataMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isLowerTriangular() const {
    if (!isSquare()) return false;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = i + 1; j < columnCount; ++j) {
            if (dataMatrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

std::vector<bool> Matrix::getMatrixProperties() const {
    return {
        isSquare(),
        isDiagonal(),
        isZero(),
        isIdentity(),
        isSymmetric(),
        isUpperTriangular(),
        isLowerTriangular()
    };
}

//Транспонирование
void Matrix::transpose() {
    std::vector<std::vector<double>> transposed(columnCount, std::vector<double>(rowCount));

    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            transposed[j][i] = dataMatrix[i][j];
        }
    }

    dataMatrix = std::move(transposed);
    std::swap(rowCount, columnCount);
}

//Операции всякие
Matrix Matrix::operator+(const Matrix& other) const {
    if (rowCount != other.rowCount || columnCount != other.columnCount) {
        throw std::invalid_argument("Matrices dimensions must match for addition");
    }
    Matrix result(rowCount, columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            result.dataMatrix[i][j] = dataMatrix[i][j] + other.dataMatrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rowCount != other.rowCount || columnCount != other.columnCount) {
        throw std::invalid_argument("Matrices dimensions must match for subtraction");
    }
    Matrix result(rowCount, columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            result.dataMatrix[i][j] = dataMatrix[i][j] - other.dataMatrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (columnCount != other.rowCount) {
        throw std::invalid_argument("Number of columns of the first matrix must equal number of rows of the second matrix");
    }
    Matrix result(rowCount, other.columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < other.columnCount; ++j) {
            result.dataMatrix[i][j] = 0;
            for (std::size_t k = 0; k < columnCount; ++k) {
                result.dataMatrix[i][j] += dataMatrix[i][k] * other.dataMatrix[k][j];
            }
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rowCount != other.rowCount || columnCount != other.columnCount) {
        throw std::invalid_argument("Matrices dimensions must match for addition");
    }
    return *this = *this + other;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rowCount != other.rowCount || columnCount != other.columnCount) {
        throw std::invalid_argument("Matrices dimensions must match for subtraction");
    }
    return *this = *this - other;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (columnCount != other.rowCount) {
        throw std::invalid_argument("Number of columns of the first matrix must equal number of rows of the second matrix");
    }
    return *this = *this * other;
}

Matrix Matrix::operator+(double value) const {
    Matrix result(rowCount, columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            result.dataMatrix[i][j] = dataMatrix[i][j] + value;
        }
    }
    return result;
}

Matrix Matrix::operator-(double value) const {
    Matrix result(rowCount, columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            result.dataMatrix[i][j] = dataMatrix[i][j] - value;
        }
    }
    return result;
}

Matrix Matrix::operator*(double value) const {
    Matrix result(rowCount, columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            result.dataMatrix[i][j] = dataMatrix[i][j] * value;
        }
    }
    return result;
}

Matrix Matrix::operator/(double value) const {
    if (value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    Matrix result(rowCount, columnCount);
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            result.dataMatrix[i][j] = dataMatrix[i][j] / value;
        }
    }
    return result;
}

Matrix& Matrix::operator+=(double value) {
    return *this = *this + value;
}

Matrix& Matrix::operator-=(double value) {
    return *this = *this - value;
}

Matrix& Matrix::operator*=(double value) {
    return *this = *this * value;
}

Matrix& Matrix::operator/=(double value) {
    if (value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return *this = *this / value;
}

//Детерминант
double Matrix::determinant() const {
    if (rowCount != columnCount) {
        throw std::invalid_argument("Matrix must be square to compute determinant");
    }
    if (rowCount == 1) {
        return dataMatrix[0][0];
    }
    if (rowCount == 2) {
        return dataMatrix[0][0] * dataMatrix[1][1] - dataMatrix[0][1] * dataMatrix[1][0];
    }
    double det = 0;
    for (std::size_t i = 0; i < rowCount; ++i) {
        Matrix submatrix(rowCount - 1, columnCount - 1);
        for (std::size_t j = 1; j < rowCount; ++j) {
            std::size_t subCol = 0;
            for (std::size_t k = 0; k < columnCount; ++k) {
                if (k == i) continue;
                submatrix.dataMatrix[j - 1][subCol++] = dataMatrix[j][k];
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * dataMatrix[0][i] * submatrix.determinant();
    }
    return det;
}

//Норма
double Matrix::norm() const {
    double sum = 0;
    for (std::size_t i = 0; i < rowCount; ++i) {
        for (std::size_t j = 0; j < columnCount; ++j) {
            sum += dataMatrix[i][j] * dataMatrix[i][j];
        }
    }
    return std::sqrt(sum);
}

//Вывод матрицы
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (size_t i = 0; i < matrix.rowCount; ++i) {
        os << "[ ";
        for (size_t j = 0; j < matrix.columnCount; ++j) {
            os << matrix.dataMatrix[i][j] << " ";
        }
        os << "]" << std::endl;
    }
    return os;
}
