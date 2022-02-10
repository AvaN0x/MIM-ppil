#include "SimpleShape.h"

SimpleShape::operator std::string() const
{
    return "";
    // TODO @Avan0x
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
