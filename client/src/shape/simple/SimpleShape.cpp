#include "SimpleShape.h"
#include <sstream>

using namespace std;
using namespace shape;

Vector2D SimpleShape::getBottomLeft() const
{
    double minX = _points[0].x;
    double minY = _points[0].y;

    for (unsigned int i = 1; i < _points.size(); i++)
    {
        if (_points[i].x < minX)
            minX = _points[i].x;
        if (_points[i].y < minY)
            minY = _points[i].y;
    }
    return Vector2D(minX, minY);
}

Vector2D SimpleShape::getTopRight() const
{
    double maxX = _points[0].x;
    double maxY = _points[0].y;

    for (unsigned int i = 1; i < _points.size(); i++)
    {
        if (_points[i].x > maxX)
            maxX = _points[i].x;
        if (_points[i].y > maxY)
            maxY = _points[i].y;
    }
    return Vector2D(maxX, maxY);
}

SimpleShape::operator std::string() const
{
    ostringstream s;
    s << "";
    bool isFirst = true;
    for (const Vector2D &point : _points)
    {
        if (isFirst)
            isFirst = false;
        else
            s << ";";
        s << point;
    }
    s << "|" << _color;
    return s.str();
}

bool SimpleShape::operator==(Shape *shape) const
{
    if (shape == nullptr)
        return false;
    if (typeid(*shape) != typeid(*this))
        return false;
    if (shape->getColor() != _color)
        return false;
    return (((SimpleShape *)shape)->getPoints() == _points);
}

bool SimpleShape::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
