#pragma once

#include <string>

namespace shape
{
    class Shape;
    class Circle;
    class Polygon;
    class Segment;
    class Triangle;
    class ComposedShape;
};

class VisitorDrawShape
{
public:
    virtual void visit(const shape::Circle *s) const = 0;
    virtual void visit(const shape::Polygon *s) const = 0;
    virtual void visit(const shape::Segment *s) const = 0;
    virtual void visit(const shape::Triangle *s) const = 0;
    virtual void visit(const shape::ComposedShape *s) const = 0;
};