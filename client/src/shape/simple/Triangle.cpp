#include "Triangle.h"
#include <math.h>

using namespace shape;

Triangle::Triangle(std::vector<Vector2D> points, Color color)
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

Triangle::Triangle(const std::string &s)
{
    if (s.rfind("Triangle", 0) != 0)
        throw std::invalid_argument("The string is not a Triangle");

    size_t firstParenthesis = s.find('(') + 1;
    size_t lastParenthesis = s.find_last_of(')');
    size_t sLength = s.length();
    if (firstParenthesis > lastParenthesis || lastParenthesis > sLength)
        throw std::invalid_argument("The string is not a Triangle");

    string dataStr = s.substr(firstParenthesis, lastParenthesis - firstParenthesis);
    std::string token;
    std::istringstream iss(dataStr);
    // Get vectors
    getline(iss, token, '|');
    {
        std::string vectorString;
        std::istringstream iss(token);

        while (getline(iss, vectorString, ';') && _points.size() <= 3)
            _points.push_back(Vector2D(vectorString));

        if (_points.size() != 3)
            throw std::invalid_argument("You need only 3 points to create a Triangle");
    }

    // Get color
    getline(iss, token, '|');
    _color = Color(token);
}

Triangle::operator std::string() const
{
    return "Triangle(" + SimpleShape::operator std::string() + ")";
}

Shape *Triangle::homothety(const Vector2D &origin, double coeff) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Triangle(points, _color);
}

Shape *Triangle::translation(const Vector2D &v) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Triangle(points, _color);
}

Shape *Triangle::rotation(const Vector2D &origin, double alpha) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point.rotation(origin, alpha));
    }
    return new Triangle(points, _color);
}

double Triangle::area() const
{
    // Source : https://www.cuemath.com/measurement/area-of-triangle/
    double a = _points[0].distance(_points[1]);
    double b = _points[1].distance(_points[2]);
    double c = _points[2].distance(_points[0]);
    double s = (a + b + c) / 2; // Semi perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool Triangle::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape);
}

bool Triangle::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
