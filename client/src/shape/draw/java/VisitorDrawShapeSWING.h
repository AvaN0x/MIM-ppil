#pragma once

#include "VisitorDrawShapeJAVA.h"

class VisitorDrawShapeSWING : public VisitorDrawShapeJAVA
{
public:
    /**
     * @brief Construct a new Visitor DrawShapeSWING object
     */
    VisitorDrawShapeSWING() : VisitorDrawShapeJAVA("SWING") {}
};