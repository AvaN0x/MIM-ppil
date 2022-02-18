#include <sstream>
#include <math.h>
#include "Vector2D.h"

Vector2D::Vector2D(const double &x, const double &y) : x(x), y(y)
{
}

Vector2D::Vector2D(const std::string &s)
{
    if (s.rfind("Vector2D(", 0) != 0)
        throw std::invalid_argument("The string is not a Vector2D");

    std::istringstream iss(s.substr(9, s.length() - 1));
    if (!(iss >> x &&
          iss.get() == ',' &&
          iss >> y))
        throw std::invalid_argument("The string is not a Vector2D");
}

double Vector2D::distance(const Vector2D &u) const
{
    return sqrt(pow(x - u.x, 2) + pow(y - u.y, 2));
}

const Vector2D Vector2D::operator+(const Vector2D &u) const
{
    return Vector2D(x + u.x, y + u.y);
}

const Vector2D &Vector2D::operator+=(const Vector2D &u)
{
    x += u.x;
    y += u.y;
    return *this;
}

const Vector2D Vector2D::operator-() const
{
    return Vector2D(-x, -y);
}

const Vector2D Vector2D::operator-(const Vector2D &u) const
{
    return Vector2D(x - u.x, y - u.y);
}

const Vector2D &Vector2D::operator-=(const Vector2D &u)
{
    x -= u.x;
    y -= u.y;
    return *this;
}

const Vector2D Vector2D::operator*(const double &a) const
{
    return Vector2D(x * a, y * a);
}

const Vector2D &Vector2D::operator*=(const double &a)
{
    x *= a;
    y *= a;
    return *this;
}

const Vector2D Vector2D::operator/(const double &a) const
{
    return Vector2D(x / a, y / a);
}

const Vector2D &Vector2D::operator/=(const double &a)
{
    x /= a;
    y /= a;
    return *this;
}

Vector2D::operator std::string() const
{
    std::ostringstream os;
    os << "Vector2D(" << x << "," << y << ")";
    return os.str();
}

bool Vector2D::operator==(const Vector2D &u) const
{
    return x == u.x && y == u.y;
}

bool Vector2D::operator!=(const Vector2D &u) const
{
    return !(*this == u);
}
