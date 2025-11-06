#include "Matrix.h"
#include <gtest/gtest.h>

//Тест конструктора по умолчанию
TEST(MatrixTest, DefaultConstructor) {
    Matrix m;
    EXPECT_EQ(m.getRowCount(), 0);
    EXPECT_EQ(m.getColumnCount(), 0);
}

//Тест с размерами
TEST(MatrixTest, ParameterizedConstructor) {
    Matrix m(2, 3);
    EXPECT_EQ(m.getRowCount(), 2);
    EXPECT_EQ(m.getColumnCount(), 3);
    for (size_t i = 0; i < 2; ++i)
        for (size_t j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(m.getElement(i, j), 0);
}

//Тест копирования и присваивания
TEST(MatrixTest, CopyAndAssignment) {
    Matrix m1(2, 2);
    m1.setElement(0, 0, 1);
    Matrix m2(m1);
    Matrix m3;
    m3 = m1;
    EXPECT_DOUBLE_EQ(m2.getElement(0, 0), 1);
    EXPECT_DOUBLE_EQ(m3.getElement(0, 0), 1);
}

//Тест сеттеров и геттеров
TEST(MatrixTest, SetAndGetElement) {
    Matrix m(2, 2);
    m.setElement(0, 1, 3.5);
    EXPECT_DOUBLE_EQ(m.getElement(0, 1), 3.5);
}

//Тест изменения размера
TEST(MatrixTest, Resize) {
    Matrix m(2, 2);
    m.setElement(0, 0, 1);
    Matrix m2 = m.resize(3, 3);
    EXPECT_EQ(m2.getRowCount(), 3);
    EXPECT_EQ(m2.getColumnCount(), 3);
    EXPECT_DOUBLE_EQ(m2.getElement(0, 0), 1);
    EXPECT_DOUBLE_EQ(m2.getElement(2, 2), 0);
}

//Тест подматрицы
TEST(MatrixTest, Submatrix) {
    Matrix m(3, 3);
    m.setElement(0, 0, 1);
    m.setElement(1, 1, 2);
    Matrix sub = m.getSubmatrix(0, 0, 2, 2);
    EXPECT_EQ(sub.getRowCount(), 2);
    EXPECT_EQ(sub.getColumnCount(), 2);
    EXPECT_DOUBLE_EQ(sub.getElement(1, 1), 2);
}

//Тест транспонирования
TEST(MatrixTest, Transpose) {
    Matrix m(2, 3);
    m.setElement(0, 1, 5);
    m.transpose();
    EXPECT_EQ(m.getRowCount(), 3);
    EXPECT_EQ(m.getColumnCount(), 2);
    EXPECT_DOUBLE_EQ(m.getElement(1, 0), 5);
}

//Тест арифметики матриц
TEST(MatrixTest, MatrixArithmetic) {
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    m1.setElement(0, 0, 1); m2.setElement(0, 0, 2);
    Matrix m3 = m1 + m2;
    EXPECT_DOUBLE_EQ(m3.getElement(0, 0), 3);
    m1 += m2;
    EXPECT_DOUBLE_EQ(m1.getElement(0, 0), 3);

    m3 = m1 - m2;
    EXPECT_DOUBLE_EQ(m3.getElement(0, 0), 1);
    m1 -= m2;
    EXPECT_DOUBLE_EQ(m1.getElement(0, 0), 1);
}

//Тест произведения 
TEST(MatrixTest, MatrixMultiplication) {
    Matrix m1(2, 3);
    Matrix m2(3, 2);
    for (size_t i = 0; i < 2; ++i)
        for (size_t j = 0; j < 3; ++j)
            m1.setElement(i, j, 1);
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 2; ++j)
            m2.setElement(i, j, 2);
    Matrix m3 = m1 * m2;
    EXPECT_EQ(m3.getRowCount(), 2);
    EXPECT_EQ(m3.getColumnCount(), 2);
    EXPECT_DOUBLE_EQ(m3.getElement(0, 0), 6);
    m1 *= m2;
    EXPECT_DOUBLE_EQ(m1.getElement(0, 0), 6);
}

//Тест скалярных операций
TEST(MatrixTest, ScalarOperations) {
    Matrix m(2, 2);
    m.setElement(0, 0, 2);
    Matrix m2 = m + 3;
    EXPECT_DOUBLE_EQ(m2.getElement(0, 0), 5);
    m += 3;
    EXPECT_DOUBLE_EQ(m.getElement(0, 0), 5);

    m2 = m - 2;
    EXPECT_DOUBLE_EQ(m2.getElement(0, 0), 3);
    m -= 2;
    EXPECT_DOUBLE_EQ(m.getElement(0, 0), 3);

    m2 = m * 2;
    EXPECT_DOUBLE_EQ(m2.getElement(0, 0), 6);
    m *= 2;
    EXPECT_DOUBLE_EQ(m.getElement(0, 0), 6);

    m2 = m / 2;
    EXPECT_DOUBLE_EQ(m2.getElement(0, 0), 3);
    m /= 2;
    EXPECT_DOUBLE_EQ(m.getElement(0, 0), 3);
}

//Тест детерминанта
TEST(MatrixTest, Determinant) {
    Matrix m(2, 2);
    m.setElement(0, 0, 1); m.setElement(0, 1, 2);
    m.setElement(1, 0, 3); m.setElement(1, 1, 4);
    EXPECT_DOUBLE_EQ(m.determinant(), -2);
}

//Тест нормы
TEST(MatrixTest, Norm) {
    Matrix m(2, 2);
    m.setElement(0, 0, 3); m.setElement(0, 1, 4);
    EXPECT_DOUBLE_EQ(m.norm(), 5);
}

//Тест проверки свойств матриц
TEST(MatrixTest, MatrixProperties) {
    Matrix m(2, 2);
    m.setElement(0, 0, 1); m.setElement(1, 1, 1);
    EXPECT_TRUE(m.isSquare());
    EXPECT_TRUE(m.isDiagonal());
    EXPECT_FALSE(m.isZero());
    EXPECT_TRUE(m.isIdentity());
    EXPECT_TRUE(m.isSymmetric());
    EXPECT_TRUE(m.isUpperTriangular());
    EXPECT_TRUE(m.isLowerTriangular());
    auto props = m.getMatrixProperties();
    EXPECT_EQ(props.size(), 7);
}

//Тест матрица из файла
TEST(MatrixTest, LoadFromFile) {

    // Загружаем матрицу
    Matrix m = Matrix::loadFromFile("C:/Users/Dasha/CLionProjects/MatrixPPOIS1/test.txt");

    // Проверяем размеры
    EXPECT_EQ(m.getRowCount(), 3);
    EXPECT_EQ(m.getColumnCount(), 3);

    // Проверяем содержимое
    EXPECT_DOUBLE_EQ(m.getElement(0, 0), 1);
    EXPECT_DOUBLE_EQ(m.getElement(0, 1), 2);
    EXPECT_DOUBLE_EQ(m.getElement(0, 2), 3);
    EXPECT_DOUBLE_EQ(m.getElement(1, 0), 4);
    EXPECT_DOUBLE_EQ(m.getElement(1, 1), 5);
    EXPECT_DOUBLE_EQ(m.getElement(1, 2), 6);
    EXPECT_DOUBLE_EQ(m.getElement(2, 0), 7);
    EXPECT_DOUBLE_EQ(m.getElement(2, 1), 8);
    EXPECT_DOUBLE_EQ(m.getElement(2, 2), 9);

}