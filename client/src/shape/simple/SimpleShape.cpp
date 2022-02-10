#include "SimpleShape.h"
#include <sstream>

using namespace std;

SimpleShape::operator std::string() const
{
    ostringstream s;
    s << "";
    bool isFirst = true;
    for (const Vecteur2D &point : _points)
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
