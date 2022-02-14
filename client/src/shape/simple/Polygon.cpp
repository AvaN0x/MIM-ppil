#include "Polygon.h"

Polygon::Polygon(std::vector<Vecteur2D> points, Color color)
{
    if (points.size() < 3)
        throw std::invalid_argument("You need at least 3 points to create a polygon");
    _points = points;
    _color = color;
}

Polygon::Polygon(const Polygon &shape)
{
    _points = shape.getPoints();
    _color = shape.getColor();
}

Polygon::Polygon(const std::string &str)
{
    // TODO @Avan0x
}

Polygon::operator std::string() const
{
    return "Polygon(" + SimpleShape::operator std::string() + ")";
}

Shape *Polygon::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Polygon(points, _color);
}

Shape *Polygon::translation(const Vecteur2D &v) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Polygon(points, _color);
}

Shape *Polygon::rotation(const Vecteur2D &origin, double alpha) const
{
    // TODO
}

double Polygon::area() const
{
    // TODO
}

bool Polygon::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape);
}

bool Polygon::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
