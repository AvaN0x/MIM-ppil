#include <iostream>
#include <string>
#include "LoadShapeTriangleTXTCOR.h"
#include "../../simple/Triangle.h"

using namespace std;

LoadShapeTriangleTXTCOR::LoadShapeTriangleTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeTriangleTXTCOR::_getShape(const string &d) const
{
    try
    {
        return new shape::Triangle(d);
    }
    catch (const std::exception &e)
    {
#ifdef DEBUG_LOAD_SHAPE_COR
        std::cerr << e.what() << std::endl;
#endif
    }

    return NULL;
}
