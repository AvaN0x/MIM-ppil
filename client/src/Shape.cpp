#include "Shape.h"

Shape::Shape(std::vector<Vecteur2D> points, Color color, GroupShape *group) : _points(points), _color(color), _group(group) {}

Shape::Shape(const Shape &shape) : _points(shape.getPoints()), _color(shape.getColor())
{
}

Shape::Shape(const std::string &str)
{
	// TODO @Avan0x
}

Shape::operator std::string() const
{
	return "";
	// TODO @Avan0x
}