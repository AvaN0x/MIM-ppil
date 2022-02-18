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
    Vector2D(const double &x = 0, const double &y = 0);
    Vector2D(const std::string &s);
    Vector2D *clone() const { return new Vector2D(*this); }

    virtual ~Vector2D() {}

    // ================== METHODS ==================
    double distance(const Vector2D &u) const;
    const Vector2D rotation(const Vector2D &origin, double alpha) const;

    // ================== OPERATORS ==================
    const Vector2D operator+(const Vector2D &u) const;
    const Vector2D &operator+=(const Vector2D &u);
    const Vector2D operator-() const;
    const Vector2D operator-(const Vector2D &u) const;
    const Vector2D &operator-=(const Vector2D &u);
    const Vector2D operator*(const double &a) const;
    const Vector2D &operator*=(const double &a);
    const Vector2D operator/(const double &a) const;
    const Vector2D &operator/=(const double &a);
    operator std::string() const;
    bool operator==(const Vector2D &u) const;
    bool operator!=(const Vector2D &u) const;

    // ================== TOSTRING AND PRINT ==================
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