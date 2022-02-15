#include <iostream>
#include <fstream>
#include <string>
#include "VisitorSaveFileTXT.h"
#include "../composed/ComposedShape.h"
#include "../simple/Circle.h"
#include "../simple/Segment.h"
#include "../simple/Polygon.h"
#include "../simple/Triangle.h"

using namespace std;
using namespace shape;

void VisitorSaveFileTXT::visit(const Circle *s, const std::string filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const Polygon *s, const std::string filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const Segment *s, const std::string filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const Triangle *s, const std::string filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const ComposedShape *s, const std::string filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}
