#include <iostream>
#include <string>
#include "LoadShapeCircleTXTCOR.h"

using namespace std;

LoadShapeCircleTXTCOR::LoadShapeCircleTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapeCircleTXTCOR::_getShape(const string &d) const
{
    cout << "check if circle" << endl; // TODO

    return NULL;
}
