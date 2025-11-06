#pragma once
#include <iostream>

/**
 * @class Vector
 * @brief Class representing a three-dimensional vector.
 *
 * A vector is defined by its start and end coordinates in 3D space.
 * Supports addition, subtraction, scalar and vector multiplication,
 * length calculation, and cosine of the angle between vectors.
 */
class Vector {
public:
    /**
     * @brief Default constructor.
     *
     * Creates a vector with both start and end points at (0, 0, 0).
     */
    Vector();

    /**
     * @brief Parameterized constructor.
     *
     * @param x1 X coordinate of the start point.
     * @param y1 Y coordinate of the start point.
     * @param z1 Z coordinate of the start point.
     * @param x2 X coordinate of the end point.
     * @param y2 Y coordinate of the end point.
     * @param z2 Z coordinate of the end point.
     */
    Vector(double x1, double y1, double z1,
        double x2, double y2, double z2);

    /**
     * @brief Copy constructor.
     *
     * @param other Vector to copy from.
     */
    Vector(const Vector& other);

    /**
     * @brief Assignment operator.
     *
     * @param other Vector to copy from.
     * @return Reference to the current object.
     */
    Vector& operator=(const Vector& other);

    /**
     * @brief Get the start coordinates of the vector.
     *
     * @param x Reference to store X coordinate.
     * @param y Reference to store Y coordinate.
     * @param z Reference to store Z coordinate.
     */
    void getStart(double& x, double& y, double& z) const;

    /**
     * @brief Get the end coordinates of the vector.
     *
     * @param x Reference to store X coordinate.
     * @param y Reference to store Y coordinate.
     * @param z Reference to store Z coordinate.
     */
    void getEnd(double& x, double& y, double& z) const;

    /**
     * @brief Set the start coordinates of the vector.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @param z Z coordinate.
     */
    void setStart(double x, double y, double z);

    /**
     * @brief Set the end coordinates of the vector.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     * @param z Z coordinate.
     */
    void setEnd(double x, double y, double z);

    /**
     * @brief Calculate the length of the vector.
     * @return Length of the vector.
     */
    double length() const;

    /**
     * @brief Add two vectors.
     * @param other Second vector.
     * @return Resulting vector.
     */
    Vector operator+(const Vector& other) const;

    /**
     * @brief Add another vector to this vector.
     * @param other Second vector.
     * @return Reference to the current object.
     */
    Vector& operator+=(const Vector& other);

    /**
     * @brief Subtract two vectors.
     * @param other Second vector.
     * @return Resulting vector.
     */
    Vector operator-(const Vector& other) const;

    /**
     * @brief Subtract another vector from this vector.
     * @param other Second vector.
     * @return Reference to the current object.
     */
    Vector& operator-=(const Vector& other);

    /**
     * @brief Vector (cross) product.
     * @param other Second vector.
     * @return Resulting vector.
     */
    Vector operator*(const Vector& other) const;

    /**
     * @brief Vector (cross) product with assignment.
     * @param other Second vector.
     * @return Reference to the current object.
     */
    Vector& operator*=(const Vector& other);

    /**
     * @brief Multiply vector by a scalar.
     * @param scalar Scalar value.
     * @return New scaled vector.
     */
    Vector operator*(double scalar) const;

    /**
     * @brief Multiply vector by a scalar with assignment.
     * @param scalar Scalar value.
     * @return Reference to the current object.
     */
    Vector& operator*=(double scalar);

    /**
     * @brief Element-wise division of two vectors.
     * @param other Second vector.
     * @return Resulting vector.
     */
    Vector operator/(const Vector& other) const;

    /**
     * @brief Element-wise division with assignment.
     * @param other Second vector.
     * @return Reference to the current object.
     */
    Vector& operator/=(const Vector& other);

    /**
     * @brief Cosine of the angle between two vectors.
     * @param other Second vector.
     * @return Cosine value.
     */
    double operator^(const Vector& other) const;

    /**
     * @brief Comparison by length (greater than).
     */
    bool operator>(const Vector& other) const;

    /**
     * @brief Comparison by length (greater than or equal to).
     */
    bool operator>=(const Vector& other) const;

    /**
     * @brief Comparison by length (less than).
     */
    bool operator<(const Vector& other) const;

    /**
     * @brief Comparison by length (less than or equal to).
     */
    bool operator<=(const Vector& other) const;

    /**
     * @brief Output vector to a stream.
     * @param os Output stream.
     * @param v Vector to output.
     * @return Reference to the output stream.
     *
     * Format: (x1, y1, z1) -> (x2, y2, z2)
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    /**
     * @brief Input vector from a stream.
     * @param is Input stream.
     * @param v Vector to read into.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>(std::istream& is, Vector& v);

private:
    double x1; ///< X coordinate of the start point.
    double y1; ///< Y coordinate of the start point.
    double z1; ///< Z coordinate of the start point.
    double x2; ///< X coordinate of the end point.
    double y2; ///< Y coordinate of the end point.
    double z2; ///< Z coordinate of the end point.
};


