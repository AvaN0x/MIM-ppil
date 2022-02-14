#include <stdexcept>
#include "ComposedShape.h"

ComposedShape::ComposedShape()
{
}

ComposedShape::ComposedShape(std::vector<Shape *> shapes)
{
    if (shapes.size() > 0)
        for (Shape *shape : shapes)
            addShape(shape);
}

ComposedShape::ComposedShape(const ComposedShape &composedShape)
{
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

void ComposedShape::addShape(Shape *shape)
{
    if (shape == nullptr)
        throw std::invalid_argument("shape is NULL");
    _shapes.push_back(shape->clone());
}

void ComposedShape::removeShape(Shape *shape)
{
    if (shape == nullptr)
        throw std::invalid_argument("shape is NULL");
    for (Shape *s : _shapes)
    {
        if ((*s) == shape)
        {
            delete s;
            return;
        }
    }
}

ComposedShape::operator std::string() const
{
    // TODO @Avan0x
}

Shape *ComposedShape::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->homothety(origin, coeff));

    return new ComposedShape(shapes);
}

Shape *ComposedShape::translation(const Vecteur2D &v) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->translation(v));

    return new ComposedShape(shapes);
}

Shape *ComposedShape::rotation(const Vecteur2D &origin, double alpha) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->rotation(origin, alpha));

    return new ComposedShape(shapes);
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
    return (((ComposedShape *)shape)->getShapes() == _shapes);
}

bool ComposedShape::operator!=(Shape *shape) const
{
    return !(*this == shape);
}
