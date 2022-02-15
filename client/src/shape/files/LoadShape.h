#pragma once

#include <fstream>
#include "../Shape.h"

class LoadShape
{
public:
    virtual shape::Shape *getShape(const string &op) const = 0;
};
