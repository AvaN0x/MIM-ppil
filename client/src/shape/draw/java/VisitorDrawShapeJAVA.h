#pragma once

#include "../VisitorDrawShape.h"

class VisitorDrawShapeJAVA : public VisitorDrawShape
{
protected:
    std::string _name;
    VisitorDrawShapeJAVA(const std::string &name) : _name(name) {}

public:
    virtual void visit(const shape::Circle *s, int port, const std::string &address) const;
    virtual void visit(const shape::Polygon *s, int port, const std::string &address) const;
    virtual void visit(const shape::Segment *s, int port, const std::string &address) const;
    virtual void visit(const shape::Triangle *s, int port, const std::string &address) const;
    virtual void visit(const shape::ComposedShape *s, int port, const std::string &address) const;
};