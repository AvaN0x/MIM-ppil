#pragma once

#include "VisitorDrawShapeJAVA.h"

class VisitorDrawShapeAWT : public VisitorDrawShapeJAVA
{
public:
    VisitorDrawShapeAWT() : VisitorDrawShapeJAVA("AWT") {}
};