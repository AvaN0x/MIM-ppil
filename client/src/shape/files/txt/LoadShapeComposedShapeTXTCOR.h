#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeComposedShapeTXTCOR : public LoadShapeCOR
{
public:
    /**
     * @brief Construct a new LoadShapeComposedShapeTXTCOR object
     *
     * @param next Next LoadShapeCOR in chain
     */
    LoadShapeComposedShapeTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
