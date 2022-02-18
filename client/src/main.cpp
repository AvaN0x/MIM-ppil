#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include "ConnectionHandler.h"

#include "test.h"

#include "utils/Color.h"
#include "shape/Vector2D.h"
#include "shape/composed/ComposedShape.h"
#include "shape/simple/Circle.h"
#include "shape/simple/Segment.h"
#include "shape/simple/Polygon.h"
#include "shape/simple/Triangle.h"
#include "shape/files/txt/VisitorSaveFileTXT.h"

using namespace std;
using namespace shape;

int main(int argc, char *argv[])
{
    mainTests();
}
