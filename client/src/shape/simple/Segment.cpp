#include "Segment.h"

using namespace shape;

Segment::Segment(std::vector<Vecteur2D> points, Color color)
{
    if (points.size() != 2)
        throw std::invalid_argument("You need only 2 points to create a segment");
    _points = points;
    _color = color;
}

Segment::Segment(const Segment &shape)
{
    _points = shape.getPoints();
    _color = shape.getColor();
}

Segment::Segment(const std::string &str)
{
    // TODO @Avan0x
}

Segment::operator std::string() const
{
    return "Segment(" + SimpleShape::operator std::string() + ")";
}

Shape *Segment::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Segment(points, _color);
}

Shape *Segment::translation(const Vecteur2D &v) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Segment(points, _color);
}

Shape *Segment::rotation(const Vecteur2D &origin, double alpha) const
{
    // TODO
}

double Segment::area() const
{
    return 0.0; // TODO @Fentomee I guess area of segment is 0 ?
}

bool Segment::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape);
}

bool Segment::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
