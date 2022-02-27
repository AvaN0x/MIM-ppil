#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeCircleTXTCOR : public LoadShapeCOR
{
public:
    /**
     * @brief Construct a new LoadShapeCircleTXTCOR object
     *
     * @param next Next LoadShapeCOR in chain
     */
    LoadShapeCircleTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
