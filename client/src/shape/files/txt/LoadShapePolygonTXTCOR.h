#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapePolygonTXTCOR : public LoadShapeCOR
{
public:
    LoadShapePolygonTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
