#pragma once

#include <string>
#include "LoadShape.h"
#include "../Shape.h"

// #define DEBUG_LOAD_SHAPE_COR 1

using namespace std;

class LoadShapeCOR : public LoadShape
{
    LoadShapeCOR *next;

protected:
    /**
     * @brief Construct a new Load ShapeCOR object
     *
     * @param next
     */
    LoadShapeCOR(LoadShapeCOR *next);

public:
    shape::Shape *getShape(const string &text) const;

protected:
    /**
     * @brief Internal method to get a Shape pointer from a string
     *
     * @param s The string
     * @return shape::Shape* The shape pointer or nullptr
     */
    virtual shape::Shape *_getShape(const string &s) const = 0;
};
