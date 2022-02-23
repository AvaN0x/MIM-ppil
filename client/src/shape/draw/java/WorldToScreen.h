#pragma once

#include "../../Vector2D.h"

class WorldToScreen
{
private:
    double _lambda;
    double _E1;
    double _E2;
    double _a;
    double _b;

public:
    WorldToScreen(Vector2D P1World, Vector2D P2World, int screenX, int screenY);

    double getLambda() const { return _lambda; }
    double getE1() const { return _E1; }
    double getE2() const { return _E2; }
    double getA() const { return _a; }
    double getB() const { return _b; }

    /**
     * @brief Converts a world coordinate to a screen coordinate
     * @param PWorld World coordinate
     * @return Screen coordinate
     */
    Vector2D toScreen(Vector2D PWorld);

    static double getLambda(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    static double getE1(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    static double getE2(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    static double getA(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double alpha, double E1);
    static double getB(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double alpha, double E2);
};