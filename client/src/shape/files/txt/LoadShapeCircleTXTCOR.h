#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeCircleTXTCOR : public LoadShapeCOR
{
public:
    LoadShapeCircleTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
