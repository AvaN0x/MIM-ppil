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
	if (typeid(*shape) != typeid(SimpleShape))
		return false;
	return (((SimpleShape *)shape)->getPoints() == _points);
}

bool SimpleShape::operator!=(Shape *shape) const
{
	return !(*this == shape);
}
