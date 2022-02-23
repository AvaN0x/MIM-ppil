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

class ConnectionHandler;
class WorldToScreen;

class VisitorDrawShape
{
public:
    virtual void visit(const shape::Circle *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    virtual void visit(const shape::Polygon *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    virtual void visit(const shape::Segment *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    virtual void visit(const shape::Triangle *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    virtual void visit(const shape::ComposedShape *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
};