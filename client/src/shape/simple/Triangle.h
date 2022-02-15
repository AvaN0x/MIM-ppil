#pragma once

#include "SimpleShape.h"

namespace shape
{
    class Triangle : public SimpleShape
    {
    public:
        // ==================== CONSTRUCTORS ====================
        Triangle(std::vector<Vector2D> points, Color color);
        Triangle(const Triangle &shape);
        Triangle(const std::string &str);

        // ==================== CLONE ====================
        Shape *clone() const { return new Triangle(*this); }

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Shape *homothety(const Vector2D &origin, double coeff) const;
        Shape *translation(const Vector2D &v) const;
        Shape *rotation(const Vector2D &origin, double alpha) const;
        double area() const;

        virtual void saveFile(const VisitorSaveFile *v, const std::string filePath) const
        {
            return v->visit(this, filePath);
        };

        // ==================== OPERATORS ====================
        bool operator==(Shape *shape) const;
        bool operator!=(Shape *shape) const;
    };
} // namespace shape