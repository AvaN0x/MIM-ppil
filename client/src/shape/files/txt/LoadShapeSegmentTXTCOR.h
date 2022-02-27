#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapeSegmentTXTCOR : public LoadShapeCOR
{
public:
    /**
     * @brief Construct a new LoadShapeSegmentTXTCOR object
     *
     * @param next Next LoadShapeCOR in chain
     */
    LoadShapeSegmentTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
