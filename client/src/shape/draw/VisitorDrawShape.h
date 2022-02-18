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
    virtual void visit(const shape::Circle *s, int port, const std::string &address) const = 0;
    virtual void visit(const shape::Polygon *s, int port, const std::string &address) const = 0;
    virtual void visit(const shape::Segment *s, int port, const std::string &address) const = 0;
    virtual void visit(const shape::Triangle *s, int port, const std::string &address) const = 0;
    virtual void visit(const shape::ComposedShape *s, int port, const std::string &address) const = 0;
};