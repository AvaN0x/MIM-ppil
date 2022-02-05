#include "Circle.h"

Circle::Circle(std::vector<Vecteur2D> points, Color color)
{
    _points = points;
    _color = color;
}

Circle::Circle(const Circle &shape)
{
    _points = shape.getPoints();
    _color = shape.getColor();
}

Circle::Circle(const std::string &str)
{
    // TODO @Avan0x
}

SimpleShape *Circle::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Circle(points, _color);
}

SimpleShape *Circle::translation(const Vecteur2D &v) const
{
    std::vector<Vecteur2D> points;
    for (const Vecteur2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Circle(points, _color);
}

SimpleShape *Circle::rotation(const Vecteur2D &origin, double alpha) const
{
    // TODO
}

double Circle::area() const
{
    // TODO
}
