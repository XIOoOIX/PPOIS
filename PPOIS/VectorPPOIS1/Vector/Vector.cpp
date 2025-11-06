#include "Vector.h"
#include <cmath>

//Базовый конструктор
Vector::Vector()
    : x1(0.0), y1(0.0), z1(0.0),
    x2(0.0), y2(0.0), z2(0.0)
{}

//С параметрами
Vector::Vector(double s_x1, double s_y1, double s_z1,
    double e_x2, double e_y2, double e_z2)
    : x1(s_x1), y1(s_y1), z1(s_z1),
    x2(e_x2), y2(e_y2), z2(e_z2)
{}

//Копированине
Vector::Vector(const Vector& other)
    : x1(other.x1), y1(other.y1), z1(other.z1),
    x2(other.x2), y2(other.y2), z2(other.z2)
{}

//Присваивание
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        z1 = other.z1;
        x2 = other.x2;
        y2 = other.y2;
        z2 = other.z2;
    }
    return *this;
}

//Геттеры
void Vector::getStart(double& x, double& y, double& z) const {
    x = x1;
    y = y1;
    z = z1;
}

void Vector::getEnd(double& x, double& y, double& z) const {
    x = x2;
    y = y2;
    z = z2;
}

//Сеттеры
void Vector::setStart(double x, double y, double z) {
    x1 = x;
    y1 = y;
    z1 = z;
}

void Vector::setEnd(double x, double y, double z) {
    x2 = x;
    y2 = y;
    z2 = z;
}

//Длина вектора
double Vector::length() const {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}

//Сложение
Vector Vector::operator+(const Vector& other) const {
    return Vector(
        x1, y1, z1,
        x2 + (other.x2 - other.x1),
        y2 + (other.y2 - other.y1),
        z2 + (other.z2 - other.z1)
    );
}

Vector& Vector::operator+=(const Vector& other) {
    *this = *this + other;
    return *this;
}

//Вычитание
Vector Vector::operator-(const Vector& other) const {
    return Vector(
        x1, y1, z1,
        x2 - (other.x2 - other.x1),
        y2 - (other.y2 - other.y1),
        z2 - (other.z2 - other.z1)
    );
}

Vector& Vector::operator-=(const Vector& other) {
    *this = *this - other;
    return *this;
}

//Векторное произведение
Vector Vector::operator*(const Vector& other) const {
    double this_x = x2 - x1;
    double this_y = y2 - y1;
    double this_z = z2 - z1;

    double other_x = other.x2 - other.x1;
    double other_y = other.y2 - other.y1;
    double other_z = other.z2 - other.z1;

    double cross_x = this_y * other_z - this_z * other_y;
    double cross_y = this_z * other_x - this_x * other_z;
    double cross_z = this_x * other_y - this_y * other_x;

    return Vector(x1, y1, z1, x1 + cross_x, y1 + cross_y, z1 + cross_z);
}

Vector& Vector::operator*=(const Vector& other) {
    *this = *this * other;
    return *this;
}

//Скалярное произведение
Vector Vector::operator*(double scalar) const {
    double this_x = x2 - x1;
    double this_y = y2 - y1;
    double this_z = z2 - z1;

    return Vector(x1, y1, z1,
        x1 + this_x * scalar,
        y1 + this_y * scalar,
        z1 + this_z * scalar);
}

Vector& Vector::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

//Деление двух векторов
Vector Vector::operator/(const Vector& other) const {
    double this_x = x2 - x1;
    double this_y = y2 - y1;
    double this_z = z2 - z1;

    double other_x = other.x2 - other.x1;
    double other_y = other.y2 - other.y1;
    double other_z = other.z2 - other.z1;

    if (other_x == 0.0 || other_y == 0.0 || other_z == 0.0) {
        throw std::invalid_argument("Division by zero");
    }

    return Vector(x1, y1, z1,
        x1 + this_x / other_x,
        y1 + this_y / other_y,
        z1 + this_z / other_z);
}

Vector& Vector::operator/=(const Vector& other) {
    *this = *this / other;
    return *this;
}

//Косинус
double Vector::operator^(const Vector& other) const {
    double this_x = x2 - x1;
    double this_y = y2 - y1;
    double this_z = z2 - z1;

    double other_x = other.x2 - other.x1;
    double other_y = other.y2 - other.y1;
    double other_z = other.z2 - other.z1;

    double dot = this_x * other_x + this_y * other_y + this_z * other_z;
    double len1 = this->length();
    double len2 = other.length();

    if (len1 == 0.0 || len2 == 0.0) {
        throw std::invalid_argument("Cos can't be calculated with zero-length vector");
    }

    return dot / (len1 * len2);
}

//Сравнение по длине
bool Vector::operator>(const Vector& other) const {
    return this->length() > other.length();
}
bool Vector::operator>=(const Vector& other) const {
    return this->length() >= other.length();
}
bool Vector::operator<(const Vector& other) const {
    return this->length() < other.length();
}
bool Vector::operator<=(const Vector& other) const {
    return this->length() <= other.length();
}

//Операторы ввода и вывода
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x1 << ", " << v.y1 << ", " << v.z1 << ") -> "
        << "(" << v.x2 << ", " << v.y2 << ", " << v.z2 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    double x1, y1, z1, x2, y2, z2;
    is >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    if (is) {
        v.setStart(x1, y1, z1);
        v.setEnd(x2, y2, z2);
    }
    return is;
}
