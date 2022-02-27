#pragma once

#include <string>
#include "../LoadShapeCOR.h"

class LoadShapePolygonTXTCOR : public LoadShapeCOR
{
public:
    /**
     * @brief Construct a new LoadShapePolygonTXTCOR object
     *
     * @param next Next LoadShapeCOR in chain
     */
    LoadShapePolygonTXTCOR(LoadShapeCOR *next);

protected:
    virtual shape::Shape *_getShape(const string &s) const;
};
