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
    /**
     * @brief Construct a new WorldToScreen object
     *
     * @param P1World The first point in the world
     * @param P2World The second point in the world
     * @param screenX The x coordinate size of the screen
     * @param screenY The y coordinate size of the screen
     */
    WorldToScreen(Vector2D P1World, Vector2D P2World, int screenX, int screenY);

    /**
     * @brief Get the Lambda, used to calculate screen coordinates
     *
     * @return double
     */
    double getLambda() const { return _lambda; }
    /**
     * @brief Get E1 double, used to calculate screen coordinates
     *
     * @return double
     */
    double getE1() const { return _E1; }
    /**
     * @brief Get E2 double, used to calculate screen coordinates
     *
     * @return double
     */
    double getE2() const { return _E2; }
    /**
     * @brief Get A double, used to calculate screen coordinates
     *
     * @return double
     */
    double getA() const { return _a; }
    /**
     * @brief Get B double, used to calculate screen coordinates
     *
     * @return double
     */
    double getB() const { return _b; }

    /**
     * @brief Converts a world coordinate to a screen coordinate
     * @param PWorld World coordinate
     * @return Screen coordinate
     */
    Vector2D toScreen(Vector2D PWorld) const;

    /**
     * @brief Get the Lambda double, used to calculate screen coordinates
     *
     * @param P1World The first point in the world
     * @param P2World The second point in the world
     * @param P1Screen The first point in the screen
     * @param P2Screen The second point in the screen
     * @return double The lambda
     */
    static double getLambda(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    /**
     * @brief Get the E1 double, used to calculate screen coordinates
     *
     * @param P1World The first point in the world
     * @param P2World The second point in the world
     * @param P1Screen The first point in the screen
     * @param P2Screen The second point in the screen
     * @return double The E1
     */
    static double getE1(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    /**
     * @brief Get the E2 double, used to calculate screen coordinates
     *
     * @param P1World The first point in the world
     * @param P2World The second point in the world
     * @param P1Screen The first point in the screen
     * @param P2Screen The second point in the screen
     * @return double The E2
     */
    static double getE2(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen);
    /**
     * @brief Get the A double, used to calculate screen coordinates
     *
     * @param P1World The first point in the world
     * @param P2World The second point in the world
     * @param P1Screen The first point in the screen Vector2D(0, screenY)
     * @param P2Screen The second point in the screen Vector2D(screenX, 0)
     * @param lambda The lambda
     * @param E1 The E1
     * @return double The A
     */
    static double getA(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double lambda, double E1);
    /**
     * @brief Get the B double, used to calculate screen coordinates
     *
     * @param P1World The first point in the world
     * @param P2World The second point in the world
     * @param P1Screen The first point in the screen Vector2D(0, screenY)
     * @param P2Screen The second point in the screen Vector2D(screenX, 0)
     * @param lambda The lambda
     * @param E2 The E2
     * @return double The B
     */
    static double getB(const Vector2D &P1World, const Vector2D &P2World, const Vector2D &P1Screen, const Vector2D &P2Screen, double lambda, double E2);
};