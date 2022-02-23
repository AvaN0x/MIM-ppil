#include <stdexcept>
#include <sstream>
#include "ComposedShape.h"

using namespace shape;

ComposedShape::ComposedShape()
{
}

ComposedShape::ComposedShape(Color color)
{
    _color = color;
}

ComposedShape::ComposedShape(std::vector<Shape *> shapes, Color color)
{
    _color = color;
    if (shapes.size() > 0)
        for (Shape *shape : shapes)
            addShape(shape);
}

ComposedShape::ComposedShape(const ComposedShape &composedShape)
{
    _color = composedShape.getColor();
    if (composedShape.getShapes().size() > 0)
        for (Shape *shape : composedShape.getShapes())
            addShape(shape);
}

ComposedShape::~ComposedShape()
{
    for (Shape *shape : _shapes)
        delete shape;
    _shapes.clear();
}

void ComposedShape::setColor(Color color)
{
    _color = color;
    for (Shape *shape : _shapes)
        shape->setColor(color);
}

Shape *ComposedShape::addShape(Shape *shape)
{
    if (shape == nullptr)
        throw std::invalid_argument("shape is NULL");
    Shape *temp = shape->clone();
    temp->setColor(_color);
    _shapes.push_back(temp);
    return temp;
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

Vector2D ComposedShape::getBottomLeft() const
{
    Vector2D bottomLeft = _shapes[0]->getBottomLeft();
    for (unsigned int i = 1; i < _shapes.size(); i++)
    {
        Vector2D temp = _shapes[i]->getBottomLeft();
        if (temp.x < bottomLeft.x)
            bottomLeft.x = temp.x;
        if (temp.y < bottomLeft.y)
            bottomLeft.y = temp.y;
    }
    return bottomLeft;
}

Vector2D ComposedShape::getTopRight() const
{
    Vector2D topRight = _shapes[0]->getTopRight();
    for (unsigned int i = 1; i < _shapes.size(); i++)
    {
        Vector2D temp = _shapes[i]->getTopRight();
        if (temp.x > topRight.x)
            topRight.x = temp.x;
        if (temp.y > topRight.y)
            topRight.y = temp.y;
    }
    return topRight;
}

ComposedShape::operator std::string() const
{
    ostringstream s;
    s << "ComposedShape[" << std::endl;
    for (Shape *shape : _shapes)
        s << "\t" << *shape << "/" << std::endl;
    s << "]";
    return s.str();
}

Shape *ComposedShape::homothety(const Vector2D &origin, double coeff) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->homothety(origin, coeff));

    return new ComposedShape(shapes, _color);
}

Shape *ComposedShape::translation(const Vector2D &v) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->translation(v));

    return new ComposedShape(shapes, _color);
}

Shape *ComposedShape::rotation(const Vector2D &origin, double alpha) const
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
