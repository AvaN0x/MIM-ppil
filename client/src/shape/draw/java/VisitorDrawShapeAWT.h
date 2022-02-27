#pragma once

#include "VisitorDrawShapeJAVA.h"

class VisitorDrawShapeAWT : public VisitorDrawShapeJAVA
{
public:
    /**
     * @brief Construct a new Visitor VisitorDrawShapeAWT object
     */
    VisitorDrawShapeAWT() : VisitorDrawShapeJAVA("AWT") {}
};