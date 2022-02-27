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
    /**
     * @brief Visitor to draw a Circle
     *
     * @param s The Circle
     * @param connection The connection handler
     * @param wts The world to screen object
     */
    virtual void visit(const shape::Circle *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    /**
     * @brief Visitor to draw a Polygon
     *
     * @param s The Polygon
     * @param connection The connection handler
     * @param wts The world to screen object
     */
    virtual void visit(const shape::Polygon *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    /**
     * @brief Visitor to draw a Segment
     *
     * @param s The Segment
     * @param connection The connection handler
     * @param wts The world to screen object
     */
    virtual void visit(const shape::Segment *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    /**
     * @brief Visitor to draw a Triangle
     *
     * @param s The Triangle
     * @param connection The connection handler
     * @param wts The world to screen object
     */
    virtual void visit(const shape::Triangle *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
    /**
     * @brief Visitor to draw a ComposedShape
     *
     * @param s The ComposedShape
     * @param connection The connection handler
     * @param wts The world to screen object
     */
    virtual void visit(const shape::ComposedShape *s, ConnectionHandler *connection, WorldToScreen *wts) const = 0;
};