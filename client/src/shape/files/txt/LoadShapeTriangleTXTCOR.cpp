#include <iostream>
#include <string>
#include "LoadShapeTriangleTXTCOR.h"

using namespace std;

LoadShapeTriangleTXTCOR::LoadShapeTriangleTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeTriangleTXTCOR::_getShape(const string &d) const
{
    cout << "check if triangle" << endl; // TODO

    return NULL;
}
