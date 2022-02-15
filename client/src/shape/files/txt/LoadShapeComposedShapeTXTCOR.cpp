#include <iostream>
#include <string>
#include "LoadShapeComposedShapeTXTCOR.h"

using namespace std;

LoadShapeComposedShapeTXTCOR::LoadShapeComposedShapeTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeComposedShapeTXTCOR::_getShape(const string &d) const
{
    cout << "check if composed shape" << endl; // TODO

    return NULL;
}
