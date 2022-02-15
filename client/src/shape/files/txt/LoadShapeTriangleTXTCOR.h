#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeTriangleTXTCOR : public LoadShapeCOR
{
public:
    LoadShapeTriangleTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &d) const;
};
