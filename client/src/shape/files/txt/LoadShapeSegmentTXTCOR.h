#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeSegmentTXTCOR : public LoadShapeCOR
{
public:
    LoadShapeSegmentTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
