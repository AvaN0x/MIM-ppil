#include <stdexcept>
#include <sstream>
#include "ComposedShape.h"

using namespace shape;

ComposedShape::ComposedShape(Color color)
{
    _color = color;
}

ComposedShape::ComposedShape(std::vector<Shape *> shapes, Color color)
{
    if (shapes.size() > 0)
        for (Shape *shape : shapes)
            addShape(shape);
    _color = color;
}

ComposedShape::ComposedShape(const ComposedShape &composedShape)
{
    if (composedShape.getShapes().size() > 0)
        for (Shape *shape : composedShape.getShapes())
            addShape(shape);
    _color = composedShape.getColor();
}

ComposedShape::~ComposedShape()
{
    for (Shape *shape : _shapes)
        delete shape;
    _shapes.clear();
}

void ComposedShape::addShape(Shape *shape)
{
    if (shape == nullptr)
        throw std::invalid_argument("shape is NULL");
    Shape *temp = shape->clone();
    temp->setColor(_color);
    _shapes.push_back(temp);
}

void ComposedShape::removeShape(Shape *shape)
{
    if (shape == nullptr)
        throw std::invalid_argument("shape is NULL");
    for (std::vector<Shape *>::iterator it = _shapes.begin(); it != _shapes.end();)
    {
        if (**it == shape)
            it = _shapes.erase(it);
        else
            ++it;
    }
}

ComposedShape::operator std::string() const
{
    ostringstream s;
    s << "ComposedShape(" << std::endl;
    for (Shape *shape : _shapes)
        s << "\t" << *shape << std::endl;
    s << ")";
    return s.str();
}

Shape *ComposedShape::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->homothety(origin, coeff));

    return new ComposedShape(shapes, _color);
}

Shape *ComposedShape::translation(const Vecteur2D &v) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->translation(v));

    return new ComposedShape(shapes, _color);
}

Shape *ComposedShape::rotation(const Vecteur2D &origin, double alpha) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->rotation(origin, alpha));

    return new ComposedShape(shapes, _color);
}

double ComposedShape::area() const
{
    double area = 0;
    for (Shape *shape : _shapes)
        area += shape->area();

    return area;
}

bool ComposedShape::operator==(Shape *shape) const
{
    if (shape == nullptr)
        return false;
    if (typeid(*shape) != typeid(ComposedShape))
        return false;
    return (((ComposedShape *)shape)->getColor() == _color && ((ComposedShape *)shape)->getShapes() == _shapes);
}

bool ComposedShape::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
