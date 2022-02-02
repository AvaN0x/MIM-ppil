#pragma once

#include "Color.h"

class Shape
{
private:
    Color color;

    void test()
    {
        Color::addAllColors();
        color = Color::getColor(Color.BLUE);
    }
    // black:(0, 0, 0), blue:(0, 0, 255), red:(255, 0, 0), green:(0, 255, 0), yellow:(255, 255, 0), cyan:(0, 255, 255)
};