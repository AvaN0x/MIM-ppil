#pragma once

#include "../../Vector2D.h"

class WorldToScreen
{
public:
    static double getLambda(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    static double getE1(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    static double getE2(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    static double getA(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double alpha, double E1);
    static double getB(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double alpha, double E2);
};