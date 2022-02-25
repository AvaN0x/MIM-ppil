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
        Circle(const std::string &s);

        // ==================== CLONE ====================
        Circle *clone() const { return new Circle(*this); }

        // ==================== GETTERS ====================
        double getRadius() const { return _radius; }
        Vector2D getCenter() const { return _points.at(0); }
        virtual Vector2D getBottomLeft() const;
        virtual Vector2D getTopRight() const;

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Circle *homothety(const Vector2D &origin, double coeff) const;
        Circle *translation(const Vector2D &v) const;
        Circle *rotation(const Vector2D &origin, double alpha) const;
        double area() const;

        // ==================== VISITORS ====================
        virtual void saveFile(const VisitorSaveFile *v, const std::string &filePath) const
        {
            return v->visit(this, filePath);
        };

        virtual void draw(const VisitorDrawShape *v, ConnectionHandler *connection = nullptr, WorldToScreen *wts = nullptr) const
        {
            return v->visit(this, connection, wts);
        };

        // ==================== OPERATORS ====================
        bool operator==(Shape *shape) const;
        bool operator!=(Shape *shape) const;
    };
} // namespace shape