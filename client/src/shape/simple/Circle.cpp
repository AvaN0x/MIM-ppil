#include "Circle.h"
#define _USE_MATH_DEFINES
#include <sstream>
#include <math.h>

using namespace std;

Circle::Circle(std::vector<Vecteur2D> points, Color color, double radius)
{
    if (points.size() != 1)
        throw std::invalid_argument("You need only 1 point to create a circle");
    if (radius <= 0)
        throw std::invalid_argument("The radius must be positive");

    _radius = radius;
    _points = points;
    _color = color;
}

Circle::Circle(const Circle &shape) : _radius(shape.getRadius())
{
    _points = shape.getPoints();
    _color = shape.getColor();
}

Circle::Circle(const std::string &str)
{
    // TODO @Avan0x
}

Circle::operator std::string() const
{
    ostringstream s;
    s << "Circle|" << SimpleShape::operator std::string() << "|" << _radius;
    return s.str();
}

Shape *Circle::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Circle(points, _color, _radius);
}

Shape *Circle::translation(const Vecteur2D &v) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Circle(points, _color, _radius);
}

Shape *Circle::rotation(const Vecteur2D &origin, double alpha) const
{
    // TODO
}

double Circle::area() const
{
    return _radius * _radius * M_PI;
}

bool Circle::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape) && ((Circle *)shape)->getRadius() == _radius;
}

bool Circle::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
