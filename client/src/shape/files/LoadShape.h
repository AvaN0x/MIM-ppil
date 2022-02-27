#pragma once

#include <fstream>
#include "../Shape.h"

class LoadShape
{
public:
    /**
     * @brief Get a Shape pointer from a string
     *
     * @param op The string
     * @return shape::Shape* The shape pointer or nullptr
     */
    virtual shape::Shape *getShape(const string &op) const = 0;
};
