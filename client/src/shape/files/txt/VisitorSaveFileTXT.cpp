#include <iostream>
#include <fstream>
#include <string>
#include "VisitorSaveFileTXT.h"
#include "../../composed/ComposedShape.h"
#include "../../simple/Circle.h"
#include "../../simple/Segment.h"
#include "../../simple/Polygon.h"
#include "../../simple/Triangle.h"

#include "LoadShapeCircleTXTCOR.h"
#include "LoadShapeTriangleTXTCOR.h"
#include "LoadShapePolygonTXTCOR.h"
#include "LoadShapeSegmentTXTCOR.h"
#include "LoadShapeComposedShapeTXTCOR.h"

using namespace std;
using namespace shape;

Shape *VisitorSaveFileTXT::loadFile(const std::string &filePath)
{
    ifstream file(filePath, ifstream::in);
    if (!file.is_open())
    {
        throw std::invalid_argument("File not found");
    }

    std::string content = std::string((std::istreambuf_iterator<char>(file)),
                                      (std::istreambuf_iterator<char>()));

    Shape *s = getShapeFromString(content);

    file.close();
    return s;
}

Shape *VisitorSaveFileTXT::getShapeFromString(const std::string &str)
{
    try
    {
        LoadShape *loadShape = new LoadShapeTriangleTXTCOR(
            new LoadShapeCircleTXTCOR(
                new LoadShapePolygonTXTCOR(
                    new LoadShapeSegmentTXTCOR(
                        new LoadShapeComposedShapeTXTCOR(nullptr)))));

        Shape *s = loadShape->getShape(str);
        return s;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}

void VisitorSaveFileTXT::visit(const Circle *s, const std::string &filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const Polygon *s, const std::string &filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const Segment *s, const std::string &filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const Triangle *s, const std::string &filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}

void VisitorSaveFileTXT::visit(const ComposedShape *s, const std::string &filePath) const
{
    ofstream file(filePath);
    file << *s;
    file.close();
}
