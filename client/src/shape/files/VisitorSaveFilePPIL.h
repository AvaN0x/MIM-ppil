#pragma once
#include <string>
#include "VisitorSaveFile.h"

class VisitorSaveFilePPIL : public VisitorSaveFile
{
public:
    virtual void visit(const shape::Circle *s, const std::string filePath) const;
    virtual void visit(const shape::Polygon *s, const std::string filePath) const;
    virtual void visit(const shape::Segment *s, const std::string filePath) const;
    virtual void visit(const shape::Triangle *s, const std::string filePath) const;
    virtual void visit(const shape::ComposedShape *s, const std::string filePath) const;
};
