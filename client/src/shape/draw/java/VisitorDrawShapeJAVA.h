#pragma once

#include "../VisitorDrawShape.h"

class VisitorDrawShapeJAVA : public VisitorDrawShape
{
protected:
    std::string _name;
    int _screen_x = 400;
    int _screen_y = 320;
    int _port = 9111;
    std::string _address = "127.0.0.1";

    VisitorDrawShapeJAVA(const std::string &name) : _name(name) {}

public:
    virtual VisitorDrawShapeJAVA &setWindowSize(int x, int y)
    {
        _screen_x = x;
        _screen_y = y;
        return *this;
    }
    virtual VisitorDrawShapeJAVA &setServer(int port, const std::string &address = "127.0.0.1")
    {
        _port = port;
        _address = address;
        return *this;
    }

    virtual void visit(const shape::Circle *s) const;
    virtual void visit(const shape::Polygon *s) const;
    virtual void visit(const shape::Segment *s) const;
    virtual void visit(const shape::Triangle *s) const;
    virtual void visit(const shape::ComposedShape *s) const;
};