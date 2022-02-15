#include <iostream>
#include <string>
#include "LoadShapeSegmentTXTCOR.h"

using namespace std;

LoadShapeSegmentTXTCOR::LoadShapeSegmentTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeSegmentTXTCOR::_getShape(const string &d) const
{
    cout << "check if segment" << endl; // TODO

    return NULL;
}
