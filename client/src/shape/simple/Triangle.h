#pragma once

#include "SimpleShape.h"

namespace shape
{
    class Triangle : public SimpleShape
    {
    public:
        // ==================== CONSTRUCTORS ====================
        /**
         * @brief Construct a new Triangle object
         *
         * @param points The points of the triangle
         * @param color The color of the triangle
         */
        Triangle(std::vector<Vector2D> points, Color color);
        /**
         * @brief Construct a new Triangle object
         *
         * @param shape The triangle to copy
         */
        Triangle(const Triangle &shape);
        /**
         * @brief Construct a new Triangle object
         *
         * @param s The string to use as source
         */
        Triangle(const std::string &s);

        // ==================== CLONE ====================
        Triangle *clone() const { return new Triangle(*this); }

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Triangle *homothety(const Vector2D &origin, double coeff) const;
        Triangle *translation(const Vector2D &v) const;
        Triangle *rotation(const Vector2D &origin, double alpha) const;
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