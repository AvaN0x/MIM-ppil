#include <iostream>
#include <string>
#include "LoadShapePolygonTXTCOR.h"
#include "../../simple/Polygon.h"

using namespace std;

LoadShapePolygonTXTCOR::LoadShapePolygonTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapePolygonTXTCOR::_getShape(const string &s) const
{
    try
    {
        return new shape::Polygon(s);
    }
    catch (const std::exception &e)
    {
#ifdef DEBUG_LOAD_SHAPE_COR
        std::cerr << e.what() << std::endl;
#endif
    }

    return NULL;
}
