#include "Segment.h"

using namespace shape;

Segment::Segment(std::vector<Vector2D> points, Color color)
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

Segment::Segment(const std::string &s)
{
    if (s.rfind("Segment", 0) != 0)
        throw std::invalid_argument("The string is not a Segment");

    size_t firstParenthesis = s.find('(') + 1;
    size_t lastParenthesis = s.find_last_of(')');
    size_t sLength = s.length();
    if (firstParenthesis > lastParenthesis || lastParenthesis > sLength)
        throw std::invalid_argument("The string is not a Segment");

    string dataStr = s.substr(firstParenthesis, lastParenthesis - firstParenthesis);
    std::string token;
    std::istringstream iss(dataStr);
    // Get vectors
    getline(iss, token, '|');
    {
        std::string vectorString;
        std::istringstream iss(token);

        while (getline(iss, vectorString, ';') && _points.size() <= 2)
            _points.push_back(Vector2D(vectorString));

        if (_points.size() != 2)
            throw std::invalid_argument("You need only 2 points to create a Segment");
    }

    // Get color
    getline(iss, token, '|');
    _color = Color(token);
}

Segment::operator std::string() const
{
    return "Segment(" + SimpleShape::operator std::string() + ")";
}

Shape *Segment::homothety(const Vector2D &origin, double coeff) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point * coeff + origin * (1 - coeff));
    }
    return new Segment(points, _color);
}

Shape *Segment::translation(const Vector2D &v) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point + v);
    }
    return new Segment(points, _color);
}

Shape *Segment::rotation(const Vector2D &origin, double alpha) const
{
    std::vector<Vector2D> points;
    for (const Vector2D &point : _points)
    {
        points.push_back(point.rotation(origin, alpha));
    }
    return new Segment(points, _color);
}

double Segment::area() const
{
    return 0.0;
}

bool Segment::operator==(Shape *shape) const
{
    return SimpleShape::operator==(shape);
}

bool Segment::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
