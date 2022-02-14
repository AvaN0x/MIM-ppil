#pragma once

#include "SimpleShape.h"

namespace shape
{
    class Circle : public SimpleShape
    {
    private:
        double _radius;

    public:
        // ==================== CONSTRUCTORS ====================
        Circle(std::vector<Vector2D> points, Color color, double radius);
        Circle(const Circle &shape);
        Circle(const std::string &str);

        // ==================== CLONE ====================
        Shape *clone() const { return new Circle(*this); }

        // ==================== GETTERS ====================
        double getRadius() const { return _radius; }

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Shape *homothety(const Vector2D &origin, double coeff) const;
        Shape *translation(const Vector2D &v) const;
        Shape *rotation(const Vector2D &origin, double alpha) const;
        double area() const;

        // ==================== OPERATORS ====================
        bool operator==(Shape *shape) const;
        bool operator!=(Shape *shape) const;
    };
} // namespace shape