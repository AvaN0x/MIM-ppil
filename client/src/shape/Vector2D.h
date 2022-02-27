#pragma once

#include <string>
#include <string.h>
#include <sstream>

using namespace std;

class Vector2D
{
public:
    double x, y;

    // ================== CONSTRUCTORS ==================
    // If no explicit, parameters from constructor can be converted implicitly by compiler to Vector2D
    /**
     * @brief Construct a new Vector2D object
     *
     * @param x X coordinate
     * @param y Y coordinate
     */
    Vector2D(const double &x = 0, const double &y = 0);
    /**
     * @brief Construct a new Vector2D object
     *
     * @param s The string to use as source
     */
    Vector2D(const std::string &s);

    virtual ~Vector2D() {}

    // ==================== CLONE ====================
    /**
     * @brief Clone the vector
     * @return The cloned vector
     */
    Vector2D *clone() const { return new Vector2D(*this); }

    // ================== METHODS ==================
    /**
     * @brief Get the distance between two vectors
     *
     * @param u The other vector
     * @return double The distance
     */
    double distance(const Vector2D &u) const;
    /**
     * @brief Apply a rotation to a vector
     *
     * @param origin The originn of the rotation
     * @param alpha The alpha of the rotation
     * @return const Vector2D The result vector
     */
    const Vector2D rotation(const Vector2D &origin, double alpha) const;

    // ================== OPERATORS ==================
    /**
     * @brief Add two vectors
     *
     * @param u The other vector
     * @return const Vector2D The result vector
     */
    const Vector2D operator+(const Vector2D &u) const;
    /**
     * @brief Add two vectors
     *
     * @param u The other vector
     * @return const Vector2D & The current object
     */
    const Vector2D &operator+=(const Vector2D &u);
    /**
     * @brief Negate a vector
     *
     * @return const Vector2D The result vector
     */
    const Vector2D operator-() const;
    /**
     * @brief Subtract two vectors
     *
     * @param u The other vector
     * @return const Vector2D The result vector
     */
    const Vector2D operator-(const Vector2D &u) const;
    /**
     * @brief Substract two vectors
     *
     * @param u The other vector
     * @return const Vector2D & The current object
     */
    const Vector2D &operator-=(const Vector2D &u);
    /**
     * @brief Multiply a vector by a double
     *
     * @param c The double
     * @return const Vector2D The result vector
     */
    const Vector2D operator*(const double &a) const;
    /**
     * @brief Multiply a vector by a double
     *
     * @param c The double
     * @return const Vector2D & The current object
     */
    const Vector2D &operator*=(const double &a);
    /**
     * @brief Divide a vector by a double
     *
     * @param c The double
     * @return const Vector2D The result vector
     */
    const Vector2D operator/(const double &a) const;
    /**
     * @brief Divide a vector by a double
     *
     * @param c The double
     * @return const Vector2D & The current object
     */
    const Vector2D &operator/=(const double &a);
    /**
     * @brief Get the string representation of the shape
     * @return The string representation of the shape
     */
    operator std::string() const;
    /**
     * @brief Compare two vectors for equality
     *
     * @param u The other vector
     * @return bool Vectors are equal
     */
    bool operator==(const Vector2D &u) const;
    /**
     * @brief Compare two vectors for non equality
     *
     * @param u The other vector
     * @return bool Vectors are not equal
     */
    bool operator!=(const Vector2D &u) const;

    // ================== TOSTRING AND PRINT ==================
    /**
     * @brief Get the string representation of the vector
     * @return The string representation of the vector
     */
    std::string toString() const
    {
        return (std::string) * this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Vector2D &u);
};

inline std::ostream &operator<<(std::ostream &os, const Vector2D &u)
{
    return os << u.toString();
}