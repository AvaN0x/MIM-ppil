#include <iostream>
#include <string>
#include "LoadShapeSegmentTXTCOR.h"
#include "../../simple/Segment.h"

using namespace std;

LoadShapeSegmentTXTCOR::LoadShapeSegmentTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeSegmentTXTCOR::_getShape(const string &s) const
{
    try
    {
        return new shape::Segment(s);
    }
    catch (const std::exception &e)
    {
#ifdef DEBUG_LOAD_SHAPE_COR
        std::cerr << e.what() << std::endl;
#endif
    }

    return NULL;
}
