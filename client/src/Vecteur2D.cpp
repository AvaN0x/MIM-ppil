#include <sstream>
#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(const double &x, const double &y) : x(x), y(y)
{
}

Vecteur2D::Vecteur2D(const std::string &s)
{
    // TODO @Avan0x
}

const Vecteur2D Vecteur2D::operator+(const Vecteur2D &u) const
{
    return Vecteur2D(x + u.x, y + u.y);
}

const Vecteur2D &Vecteur2D::operator+=(const Vecteur2D &u)
{
    x += u.x;
    y += u.y;
    return *this;
}

const Vecteur2D Vecteur2D::operator-() const
{
    return Vecteur2D(-x, -y);
}

const Vecteur2D Vecteur2D::operator-(const Vecteur2D &u) const
{
    return Vecteur2D(x - u.x, y - u.y);
}

const Vecteur2D &Vecteur2D::operator-=(const Vecteur2D &u)
{
    x -= u.x;
    y -= u.y;
    return *this;
}

const Vecteur2D Vecteur2D::operator*(const double &a) const
{
    return Vecteur2D(x * a, y * a);
}

const Vecteur2D &Vecteur2D::operator*=(const double &a)
{
    x *= a;
    y *= a;
    return *this;
}

const Vecteur2D Vecteur2D::operator/(const double &a) const
{
    return Vecteur2D(x / a, y / a);
}

const Vecteur2D &Vecteur2D::operator/=(const double &a)
{
    x /= a;
    y /= a;
    return *this;
}

Vecteur2D::operator std::string() const
{
    std::ostringstream os;
    os << "Vecteur2D(" << x << ", " << y << ")";
    return os.str();
}

bool Vecteur2D::operator==(const Vecteur2D &u) const
{
    return x == u.x && y == u.y;
}

bool Vecteur2D::operator!=(const Vecteur2D &u) const
{
    return !(*this == u);
}
