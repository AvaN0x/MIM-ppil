#pragma once

#include "SimpleShape.h"

class Triangle : public SimpleShape
{
public:
    // ==================== CONSTRUCTORS ====================
    Triangle(std::vector<Vecteur2D> points, Color color);
    Triangle(const Triangle &shape);
    Triangle(const std::string &str);

    // ==================== CLONE ====================
    Shape *clone() const { return new Triangle(*this); }

    // ==================== STRING ====================
    operator std::string() const;

    // ==================== OPERATIONS ====================
    Shape *homothety(const Vecteur2D &origin, double coeff) const;
    Shape *translation(const Vecteur2D &v) const;
    Shape *rotation(const Vecteur2D &origin, double alpha) const;
    double area() const;

    // ==================== OPERATORS ====================
    bool operator==(Shape *shape) const;
    bool operator!=(Shape *shape) const;
};