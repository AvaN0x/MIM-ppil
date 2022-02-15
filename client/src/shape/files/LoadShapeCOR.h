#pragma once

#include <string>
#include "LoadShape.h"
#include "../Shape.h"

using namespace std;

class LoadShapeCOR : public LoadShape
{
    LoadShapeCOR *next;

protected:
    LoadShapeCOR(LoadShapeCOR *next);

public:
    shape::Shape *getShape(const string &text) const;

protected:
    virtual shape::Shape *_getShape(const string &text) const = 0;
};
