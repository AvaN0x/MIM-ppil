#include "Circle.h"
#define _USE_MATH_DEFINES
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;
using namespace shape;

Circle::Circle(std::vector<Vector2D> points, Color color, double radius)
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

Circle::Circle(const std::string &s)
{
    if (s.rfind("Circle", 0) != 0)
        throw std::invalid_argument("The string is not a circle");

    size_t firstParenthesis = s.find('(') + 1;
    size_t lastParenthesis = s.find_last_of(')');
    size_t sLength = s.length();
    if (firstParenthesis > lastParenthesis || lastParenthesis > sLength)
        throw std::invalid_argument("The string is not a circle");

    string dataStr = s.substr(firstParenthesis, lastParenthesis - firstParenthesis);
    std::string token;
    std::istringstream iss(dataStr);
    // Get vector
    getline(iss, token, '|');
    _points.push_back(Vector2D(token));

    // Get color
    getline(iss, token, '|');
    _color = Color(token);

    // Get Radius
    getline(iss, token, '|');
    _radius = stod(token);
}

Vector2D Circle::getBottomLeft() const
{
    return Vector2D(_points[0].x - _radius, _points[0].y - _radius);
}

Vector2D Circle::getTopRight() const
{
    return Vector2D(_points[0].x + _radius, _points[0].y + _radius);
}

void Circle::setRadius(double radius)
{
    if (radius <= 0)
        throw std::invalid_argument("The radius must be positive");
    _radius = radius;
}

Circle::operator std::string() const
{
    ostringstream s;
    s << "Circle(" << SimpleShape::operator std::string() << "|" << _radius << ")";
    return s.str();
}

Circle *Circle::homothety(const Vector2D &origin, double coeff) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Circle(points, _color, _radius * coeff);
}

Circle *Circle::translation(const Vector2D &v) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Circle(points, _color, _radius);
}

Circle *Circle::rotation(const Vector2D &origin, double alpha) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point.rotation(origin, alpha));
    }
    return new Circle(points, _color, _radius);
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
