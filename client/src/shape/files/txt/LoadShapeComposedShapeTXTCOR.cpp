#include <iostream>
#include <string>
#include "LoadShapeComposedShapeTXTCOR.h"
#include "../../composed/ComposedShape.h"

using namespace std;

LoadShapeComposedShapeTXTCOR::LoadShapeComposedShapeTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeComposedShapeTXTCOR::_getShape(const string &d) const
{
    try
    {
        return new shape::ComposedShape(d);
    }
    catch (const std::exception &e)
    {
#ifdef DEBUG_LOAD_SHAPE_COR
        std::cerr << e.what() << std::endl;
#endif
    }

    return NULL;
}
