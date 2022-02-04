#include "GroupShape.h"
#include "Shape.h"

GroupShape::GroupShape(std::vector<Shape *> shapes, int groupId) : _groupId(groupId), _shapes(shapes)
{
}

GroupShape::GroupShape(const GroupShape &composedShape, int groupId) : _groupId(groupId)
{
    for (Shape *shape : composedShape.getShapes())
        addShape(shape);
}

GroupShape::~GroupShape()
{
    for (Shape *shape : _shapes)
        delete shape;
    _shapes.clear();
}

void GroupShape::addShape(Shape *shape)
{
    _shapes.push_back(shape->clone());
}

void GroupShape::removeShape(Shape *shape)
{
    for (Shape *s : _shapes)
    {
        if ((*s) == (*shape))
        {
            delete s;
            return;
        }
    }
}

GroupShape::operator std::string() const
{
    // TODO @Avan0x
}

GroupShape GroupShape::homothety(const Vecteur2D &origin, double coeff) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->homothety(origin, coeff));

    return GroupShape(shapes, 0);
}

GroupShape GroupShape::translation(const Vecteur2D &v) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->translation(v));

    return GroupShape(shapes, 0);
}

GroupShape GroupShape::rotation(const Vecteur2D &origin, double alpha) const
{
    std::vector<Shape *> shapes;
    for (Shape *shape : _shapes)
        shapes.push_back(shape->rotation(origin, alpha));

    return GroupShape(shapes, 0);
}

double GroupShape::area() const
{
    double area = 0;
    for (Shape *shape : _shapes)
        area += shape->area();

    return area;
}

bool GroupShape::operator==(const GroupShape &shape) const
{
    if (_groupId == shape.getId())
        return true;
    if (_shapes == shape.getShapes())
        return true;
    return false;
}

bool GroupShape::operator!=(const GroupShape &shape) const
{
    return !(*this == shape);
}
