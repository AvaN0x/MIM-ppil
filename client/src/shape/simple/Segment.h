#pragma once

#include "SimpleShape.h"

namespace shape
{
    class Segment : public SimpleShape
    {
    public:
        // ==================== CONSTRUCTORS ====================
        Segment(std::vector<Vector2D> points, Color color);
        Segment(const Segment &shape);
        Segment(const std::string &s);

        // ==================== CLONE ====================
        Shape *clone() const { return new Segment(*this); }

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Shape *homothety(const Vector2D &origin, double coeff) const;
        Shape *translation(const Vector2D &v) const;
        Shape *rotation(const Vector2D &origin, double alpha) const;
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