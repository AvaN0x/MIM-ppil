#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeComposedShapeTXTCOR : public LoadShapeCOR
{
public:
    LoadShapeComposedShapeTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
