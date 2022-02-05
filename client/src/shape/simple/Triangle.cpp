#include "Triangle.h"

Triangle::Triangle(std::vector<Vecteur2D> points, Color color)
{
    if (points.size() != 3)
        throw std::invalid_argument("You need only 3 points to create a triangle");
    _points = points;
    _color = color;
}

Triangle::Triangle(const Triangle &shape)
{
    _points = shape.getPoints();
    _color = shape.getColor();
}

Triangle::Triangle(const std::string &str)
{
    // TODO @Avan0x
}

Triangle::operator std::string() const
{
    // TODO
}

Shape *Triangle::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Triangle(points, _color);
}

Shape *Triangle::translation(const Vecteur2D &v) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Triangle(points, _color);
}

Shape *Triangle::rotation(const Vecteur2D &origin, double alpha) const
{
    // TODO
}

double Triangle::area() const
{
    // TODO
}

bool Triangle::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape);
}

bool Triangle::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
