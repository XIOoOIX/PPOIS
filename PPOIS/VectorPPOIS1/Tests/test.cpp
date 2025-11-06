#include "Vector.h"
#include <gtest/gtest.h>

//Тест конструктора по умолчанию
TEST(VectorTest, DefaultConstructor) {
    Vector v;
    double x, y, z;
    v.getStart(x, y, z);
    EXPECT_DOUBLE_EQ(x, 0);
    EXPECT_DOUBLE_EQ(y, 0);
    EXPECT_DOUBLE_EQ(z, 0);
    v.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 0);
    EXPECT_DOUBLE_EQ(y, 0);
    EXPECT_DOUBLE_EQ(z, 0);
}

//Тест конструктора с параметрами
TEST(VectorTest, ParameterizedConstructor) {
    Vector v(1, 2, 3, 4, 5, 6);
    double x, y, z;
    v.getStart(x, y, z);
    EXPECT_DOUBLE_EQ(x, 1);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 3);
    v.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 4);
    EXPECT_DOUBLE_EQ(y, 5);
    EXPECT_DOUBLE_EQ(z, 6);
}

//Тест копирования и присваивания
TEST(VectorTest, CopyAndAssignment) {
    Vector v1(1, 2, 3, 4, 5, 6);
    Vector v2(v1);
    Vector v3;
    v3 = v1;

    double x, y, z;
    v2.getStart(x, y, z);
    EXPECT_DOUBLE_EQ(x, 1);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 3);
    v3.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 4);
    EXPECT_DOUBLE_EQ(y, 5);
    EXPECT_DOUBLE_EQ(z, 6);
}

//Тест сеттеров и геттеров
TEST(VectorTest, Setters) {
    Vector v;
    v.setStart(1, 2, 3);
    v.setEnd(4, 5, 6);
    double x, y, z;
    v.getStart(x, y, z);
    EXPECT_DOUBLE_EQ(x, 1);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 3);
    v.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 4);
    EXPECT_DOUBLE_EQ(y, 5);
    EXPECT_DOUBLE_EQ(z, 6);
}

//Тест длины вектора
TEST(VectorTest, Length) {
    Vector v(0, 0, 0, 3, 4, 12);
    EXPECT_DOUBLE_EQ(v.length(), 13);
}

//Тест арифметических операций
TEST(VectorTest, AdditionAndSubtraction) {
    Vector v1(0, 0, 0, 1, 2, 3);
    Vector v2(0, 0, 0, 4, 5, 6);

    Vector v3 = v1 + v2;
    double x, y, z;
    v3.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 5);
    EXPECT_DOUBLE_EQ(y, 7);
    EXPECT_DOUBLE_EQ(z, 9);

    v1 += v2;
    v1.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 5);
    EXPECT_DOUBLE_EQ(y, 7);
    EXPECT_DOUBLE_EQ(z, 9);

    Vector v4 = v1 - v2;
    v4.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 1);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 3);

    v1 -= v2;
    v1.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 1);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 3);
}

//Тест скалярного произведения
TEST(VectorTest, ScalarMultiplication) {
    Vector v(0, 0, 0, 1, 2, 3);
    Vector v2 = v * 2;
    double x, y, z;
    v2.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 2);
    EXPECT_DOUBLE_EQ(y, 4);
    EXPECT_DOUBLE_EQ(z, 6);

    v *= 3;
    v.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 3);
    EXPECT_DOUBLE_EQ(y, 6);
    EXPECT_DOUBLE_EQ(z, 9);
}

//Тест векторного произведения
TEST(VectorTest, CrossProduct) {
    Vector v1(0, 0, 0, 1, 0, 0);
    Vector v2(0, 0, 0, 0, 1, 0);
    Vector v3 = v1 * v2;
    double x, y, z;
    v3.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 0);
    EXPECT_DOUBLE_EQ(y, 0);
    EXPECT_DOUBLE_EQ(z, 1);

    v1 *= v2;
    v1.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(z, 1);
}

//Тест деления
TEST(VectorTest, ComponentDivision) {
    Vector v1(0, 0, 0, 2, 4, 6);
    Vector v2(0, 0, 0, 1, 2, 3);
    Vector v3 = v1 / v2;
    double x, y, z;
    v3.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 2);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 2);

    v1 /= v2;
    v1.getEnd(x, y, z);
    EXPECT_DOUBLE_EQ(x, 2);
    EXPECT_DOUBLE_EQ(y, 2);
    EXPECT_DOUBLE_EQ(z, 2);
}

//Тест косинуса
TEST(VectorTest, CosineAngle) {
    Vector v1(0, 0, 0, 1, 0, 0);
    Vector v2(0, 0, 0, 0, 1, 0);
    double cosAngle = v1 ^ v2;
    EXPECT_DOUBLE_EQ(cosAngle, 0);
}

//Тест операторов сравнения
TEST(VectorTest, ComparisonOperators) {
    Vector v1(0, 0, 0, 1, 0, 0);
    Vector v2(0, 0, 0, 2, 0, 0);

    EXPECT_TRUE(v2 > v1);
    EXPECT_TRUE(v1 < v2);
    EXPECT_TRUE(v2 >= v1);
    EXPECT_TRUE(v1 <= v2);
    EXPECT_FALSE(v1 > v2);
    EXPECT_FALSE(v2 < v1);
}

