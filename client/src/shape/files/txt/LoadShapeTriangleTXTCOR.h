#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeTriangleTXTCOR : public LoadShapeCOR
{
public:
    /**
     * @brief Construct a new LoadShapeTriangleTXTCOR object
     *
     * @param next Next LoadShapeCOR in chain
     */
    LoadShapeTriangleTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
