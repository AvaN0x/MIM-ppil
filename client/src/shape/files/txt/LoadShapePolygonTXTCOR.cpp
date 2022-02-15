#include <iostream>
#include <string>
#include "LoadShapePolygonTXTCOR.h"

using namespace std;

LoadShapePolygonTXTCOR::LoadShapePolygonTXTCOR(LoadShapeCOR *next) : LoadShapeCOR(next) {}

shape::Shape *LoadShapePolygonTXTCOR::_getShape(const string &d) const
{
    cout << "check if polygon" << endl; // TODO

    return NULL;
}
