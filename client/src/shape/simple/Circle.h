#pragma once

#include "SimpleShape.h"

class Circle : public SimpleShape
{
    // ==================== CONSTRUCTORS ====================
    Circle(std::vector<Vecteur2D> points, Color color);
    Circle(const Circle &shape);
    Circle(const std::string &str);

    // ==================== CLONE ====================
    Shape *clone() const { return new Circle(*this); }

    // ==================== OPERATIONS ====================
    SimpleShape *homothety(const Vecteur2D &origin, double coeff) const;
    SimpleShape *translation(const Vecteur2D &v) const;
    SimpleShape *rotation(const Vecteur2D &origin, double alpha) const;
    double area() const;

    // ==================== OPERATORS ====================
    bool operator==(Shape *shape) const;
    bool operator!=(Shape *shape) const;
};