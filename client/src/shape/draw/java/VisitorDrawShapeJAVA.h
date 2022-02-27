#pragma once

#include "../VisitorDrawShape.h"

class VisitorDrawShapeJAVA : public VisitorDrawShape
{
protected:
    std::string _name;
    int _screenX = 400;
    int _screenY = 320;
    int _port = 9111;
    std::string _address = "127.0.0.1";

    /**
     * @brief Construct a new VisitorDrawShapeJAVA object
     *
     * @param name The name of the drawing library
     */
    VisitorDrawShapeJAVA(const std::string &name) : _name(name) {}

public:
    /**
     * @brief Set the Window Size object
     *
     * @param x X coordinate of the window
     * @param y Y coordinate of the window
     * @return VisitorDrawShapeJAVA& this
     */
    virtual VisitorDrawShapeJAVA &setWindowSize(int x, int y)
    {
        _screenX = x;
        _screenY = y;
        return *this;
    }

    /**
     * @brief Set the Server variables
     *
     * @param port The port
     * @param address The address
     * @return VisitorDrawShapeJAVA& this
     */
    virtual VisitorDrawShapeJAVA &setServer(int port, const std::string &address = "127.0.0.1")
    {
        _port = port;
        _address = address;
        return *this;
    }

    virtual void visit(const shape::Circle *s, ConnectionHandler *connection, WorldToScreen *wts) const;
    virtual void visit(const shape::Polygon *s, ConnectionHandler *connection, WorldToScreen *wts) const;
    virtual void visit(const shape::Segment *s, ConnectionHandler *connection, WorldToScreen *wts) const;
    virtual void visit(const shape::Triangle *s, ConnectionHandler *connection, WorldToScreen *wts) const;
    virtual void visit(const shape::ComposedShape *s, ConnectionHandler *connection, WorldToScreen *wts) const;
};