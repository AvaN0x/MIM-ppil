#pragma once
#include <string>

namespace shape
{
    class Circle;
    class Polygon;
    class Segment;
    class Triangle;
    class ComposedShape;
};

class VisitorSaveFile
{
public:
    virtual void visit(const shape::Circle *s, const std::string filePath) const = 0;
    virtual void visit(const shape::Polygon *s, const std::string filePath) const = 0;
    virtual void visit(const shape::Segment *s, const std::string filePath) const = 0;
    virtual void visit(const shape::Triangle *s, const std::string filePath) const = 0;
    virtual void visit(const shape::ComposedShape *s, const std::string filePath) const = 0;
};
