#include <iostream>
#include <string>
#include "LoadShapeCircleTXTCOR.h"
#include "../../simple/Circle.h"

using namespace std;

LoadShapeCircleTXTCOR::LoadShapeCircleTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeCircleTXTCOR::_getShape(const string &d) const
{
    try
    {
        return new shape::Circle(d);
    }
    catch (const std::exception &e)
    {
#ifdef DEBUG_LOAD_SHAPE_COR
        std::cerr << e.what() << std::endl;
#endif
    }

    return NULL;
}
