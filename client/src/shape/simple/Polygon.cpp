#include <vector>
#include "../../utils/Color.h"
#include "Polygon.h"
#include "Triangle.h"

using namespace shape;

Polygon::Polygon(std::vector<Vector2D> points, Color color)
{
    if (points.size() <= 3)
        throw std::invalid_argument("You need at least 3 points to create a polygon");
    _points = points;
    _color = color;
}

Polygon::Polygon(const Polygon &shape)
{
    _points = shape.getPoints();
    _color = shape.getColor();
}

Polygon::Polygon(const std::string &s)
{
    if (s.rfind("Polygon", 0) != 0)
        throw std::invalid_argument("The string is not a Polygon");

    size_t firstParenthesis = s.find('(') + 1;
    size_t lastParenthesis = s.find_last_of(')');
    size_t sLength = s.length();
    if (firstParenthesis > lastParenthesis || lastParenthesis > sLength)
        throw std::invalid_argument("The string is not a Polygon");

    string dataStr = s.substr(firstParenthesis, lastParenthesis - firstParenthesis);
    std::string token;
    std::istringstream iss(dataStr);
    // Get vectors
    getline(iss, token, '|');
    {
        std::string vectorString;
        std::istringstream iss(token);

        while (getline(iss, vectorString, ';'))
            _points.push_back(Vector2D(vectorString));

        if (_points.size() <= 3)
            throw std::invalid_argument("You need at least 3 points to create a polygon");
    }

    // Get color
    getline(iss, token, '|');
    _color = Color(token);
}

Polygon::operator std::string() const
{
    return "Polygon(" + SimpleShape::operator std::string() + ")";
}

Polygon *Polygon::homothety(const Vector2D &origin, double coeff) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Polygon(points, _color);
}

Polygon *Polygon::translation(const Vector2D &v) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Polygon(points, _color);
}

Polygon *Polygon::rotation(const Vector2D &origin, double alpha) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point.rotation(origin, alpha));
    }
    return new Polygon(points, _color);
}

double Polygon::area() const
{
    // Verified with https://www.omnicalculator.com/math/irregular-polygon-area
    Vector2D g;
    for (const Vector2D &point : _points)
        g += point;
    g /= _points.size();

    double area = 0;
    for (size_t i = 0; i < _points.size(); i++)
        area += shape::Triangle(std::vector<Vector2D>({_points[i], _points[(i + 1) % _points.size()], g}), Color::BLACK).area();
    return area;
}

bool Polygon::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape);
}

bool Polygon::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
