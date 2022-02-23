#include <cstdlib>
#include <algorithm>
#include "WorldToScreen.h"

#include <iostream> // FIXME remove

WorldToScreen::WorldToScreen(Vector2D P1World, Vector2D P2World, int screenX, int screenY)
{
    std::cout << "P1World : " << P1World << std::endl;
    std::cout << "P2World : " << P2World << std::endl;

    // Get coordinates of the screen
    Vector2D P1Screen(0, screenY);
    Vector2D P2Screen(screenX, 0);

    // Calculate needed values
    _lambda = WorldToScreen::getLambda(P1World, P2World, P1Screen, P2Screen);
    _E1 = WorldToScreen::getE1(P1World, P2World, P1Screen, P2Screen);
    _E2 = WorldToScreen::getE2(P1World, P2World, P1Screen, P2Screen);
    _a = WorldToScreen::getA(P1World, P2World, P1Screen, P2Screen, _lambda, _E1);
    _b = WorldToScreen::getB(P1World, P2World, P1Screen, P2Screen, _lambda, _E2);
}

Vector2D WorldToScreen::toScreen(Vector2D PWorld)
{
    return Vector2D(
        _lambda * _E1 * PWorld.x + _a,
        _lambda * _E2 * PWorld.y + _b);
}

double WorldToScreen::getLambda(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen)
{
    return std::min(
        (std::abs(P2Screen.x - P1Screen.x) / std::abs(P2World.x - P1World.x)),
        (std::abs(P2Screen.y - P1Screen.y) / std::abs(P2World.y - P1World.y)));
}

double WorldToScreen::getE1(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen)
{
    return (P2World.x - P1World.x) * (P2Screen.x - P1Screen.x) < 0 ? -1 : 1;
}

double WorldToScreen::getE2(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen)
{
    return (P2World.y - P1World.y) * (P2Screen.y - P1Screen.y) < 0 ? -1 : 1;
}

double WorldToScreen::getA(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double alpha, double E1)
{
    return (P1Screen.x + P2Screen.x) / 2 -
           (E1 * alpha) * ((P1World.x + P2World.x) / 2);
}

double WorldToScreen::getB(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double alpha, double E2)
{
    return (P1Screen.y + P2Screen.y) / 2 -
           (E2 * alpha) * ((P1World.y + P2World.y) / 2);
}
