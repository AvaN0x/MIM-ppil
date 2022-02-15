#include <iostream>
#include <string>
#include "VisitorSaveFilePPIL.h"
#include "../composed/ComposedShape.h"
#include "../simple/Circle.h"
#include "../simple/Segment.h"
#include "../simple/Polygon.h"
#include "../simple/Triangle.h"

using namespace std;
using namespace shape;

void VisitorSaveFilePPIL::visit(const Circle *s, const std::string filePath) const
{
    cout << "save file Circle ppil" << endl;
    // TODO AvaN0x
}

void VisitorSaveFilePPIL::visit(const Polygon *s, const std::string filePath) const
{
    cout << "save file Polygon ppil" << endl;
    // TODO AvaN0x
}

void VisitorSaveFilePPIL::visit(const Segment *s, const std::string filePath) const
{
    cout << "save file Segment ppil" << endl;
    // TODO AvaN0x
}

void VisitorSaveFilePPIL::visit(const Triangle *s, const std::string filePath) const
{
    cout << "save file Triangle ppil" << endl;
    // TODO AvaN0x
}

void VisitorSaveFilePPIL::visit(const ComposedShape *s, const std::string filePath) const
{
    cout << "save file ComposedShapes ppil" << endl;
    // TODO AvaN0x
}
