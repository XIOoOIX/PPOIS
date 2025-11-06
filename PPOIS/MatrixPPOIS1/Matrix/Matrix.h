#pragma once
#include <iostream>
#include <vector>

/**
 * @class Matrix
 * @brief Class representing a mathematical matrix.
 *
 * The Matrix class supports creation, element access and modification,
 * resizing, submatrix extraction, file loading, and various matrix operations
 * such as addition, subtraction, multiplication, scalar operations,
 * determinant calculation, transposition, and norm calculation.
 * It also provides checks for matrix properties like square, diagonal,
 * zero, identity, symmetric, upper or lower triangular.
 */
class Matrix {
public:
    /**
     * @brief Default constructor.
     *
     * Creates an empty matrix of size 0×0.
     */
    Matrix();

    /**
     * @brief Constructor with specified size.
     *
     * Creates a matrix with given number of rows and columns, initialized to zero.
     *
     * @param rowCount Number of rows.
     * @param columnCount Number of columns.
     */
    Matrix(std::size_t rowCount, std::size_t columnCount);

    /**
     * @brief Copy constructor.
     *
     * @param other Matrix to copy from.
     */
    Matrix(const Matrix& other);

    /**
     * @brief Assignment operator.
     *
     * @param other Matrix to copy from.
     * @return Reference to the current object.
     */
    Matrix& operator=(const Matrix& other);

    /**
     * @brief Get the number of rows.
     * @return Number of rows in the matrix.
     */
    std::size_t getRowCount() const;

    /**
     * @brief Get the number of columns.
     * @return Number of columns in the matrix.
     */
    std::size_t getColumnCount() const;

    /**
     * @brief Get an element at specified row and column.
     *
     * @param row Row index (0-based).
     * @param col Column index (0-based).
     * @return Value of the element.
     */
    double getElement(std::size_t row, std::size_t col) const;

    /**
     * @brief Set an element at specified row and column.
     *
     * @param row Row index (0-based).
     * @param col Column index (0-based).
     * @param value Value to set.
     */
    void setElement(std::size_t row, std::size_t col, double value);

    /**
     * @brief Resize the matrix.
     *
     * Returns a new matrix with the specified size. Existing elements
     * are preserved as much as possible.
     *
     * @param newRowCount New number of rows.
     * @param newColumnCount New number of columns.
     * @return Resized matrix.
     */
    Matrix resize(int newRowCount, int newColumnCount) const;

    /**
     * @brief Extract a submatrix.
     *
     * @param startRow Starting row index (0-based).
     * @param startCol Starting column index (0-based).
     * @param subRows Number of rows in the submatrix.
     * @param subCols Number of columns in the submatrix.
     * @return Submatrix as a new Matrix object.
     */
    Matrix getSubmatrix(int startRow, int startCol, int subRows, int subCols) const;

    /**
     * @brief Output matrix to a stream.
     * @param os Output stream.
     * @param matrix Matrix to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    /**
     * @brief Load a matrix from a file.
     *
     * @param filename Path to the file.
     * @return Loaded matrix.
     */
    static Matrix loadFromFile(const std::string& filename);

    /**
     * @brief Check if the matrix is square.
     * @return True if the matrix is square, false otherwise.
     */
    bool isSquare() const;

    /**
     * @brief Check if the matrix is diagonal.
     * @return True if the matrix is diagonal, false otherwise.
     */
    bool isDiagonal() const;

    /**
     * @brief Check if the matrix is a zero matrix.
     * @return True if all elements are zero.
     */
    bool isZero() const;

    /**
     * @brief Check if the matrix is an identity matrix.
     * @return True if the matrix is identity.
     */
    bool isIdentity() const;

    /**
     * @brief Check if the matrix is symmetric.
     * @return True if symmetric.
     */
    bool isSymmetric() const;

    /**
     * @brief Check if the matrix is upper triangular.
     * @return True if upper triangular.
     */
    bool isUpperTriangular() const;

    /**
     * @brief Check if the matrix is lower triangular.
     * @return True if lower triangular.
     */
    bool isLowerTriangular() const;

    /**
     * @brief Get an array of boolean flags representing matrix properties.
     * @return Vector of booleans indicating various matrix properties.
     */
    std::vector<bool> getMatrixProperties() const;

    /**
     * @brief Transpose the matrix in place.
     */
    void transpose();

    // ----- Matrix operations -----

    /**
     * @brief Matrix addition.
     * @param other Matrix to add.
     * @return Resulting matrix.
     */
    Matrix operator+(const Matrix& other) const;

    /**
     * @brief Matrix addition with assignment.
     * @param other Matrix to add.
     * @return Reference to the current object.
     */
    Matrix& operator+=(const Matrix& other);

    /**
     * @brief Matrix subtraction.
     * @param other Matrix to subtract.
     * @return Resulting matrix.
     */
    Matrix operator-(const Matrix& other) const;

    /**
     * @brief Matrix subtraction with assignment.
     * @param other Matrix to subtract.
     * @return Reference to the current object.
     */
    Matrix& operator-=(const Matrix& other);

    /**
     * @brief Matrix multiplication.
     * @param other Matrix to multiply.
     * @return Resulting matrix.
     */
    Matrix operator*(const Matrix& other) const;

    /**
     * @brief Matrix multiplication with assignment.
     * @param other Matrix to multiply.
     * @return Reference to the current object.
     */
    Matrix& operator*=(const Matrix& other);

    // ----- Scalar operations -----

    Matrix operator+(double value) const;
    Matrix& operator+=(double value);
    Matrix operator-(double value) const;
    Matrix& operator-=(double value);
    Matrix operator*(double value) const;
    Matrix& operator*=(double value);
    Matrix operator/(double value) const;
    Matrix& operator/=(double value);

    /**
     * @brief Compute the determinant of the matrix.
     * @return Determinant value.
     */
    double determinant() const;

    /**
     * @brief Compute the norm of the matrix.
     * @return Norm value.
     */
    double norm() const;

private:
    std::size_t rowCount; ///< Number of rows in the matrix.
    std::size_t columnCount; ///< Number of columns in the matrix.
    std::vector<std::vector<double>> dataMatrix; ///< Matrix data stored as a vector of vectors.
};