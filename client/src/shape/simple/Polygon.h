#pragma once

#include "SimpleShape.h"

namespace shape
{
    class Polygon : public SimpleShape
    {
    public:
        // ==================== CONSTRUCTORS ====================
        /**
         * @brief Construct a new Polygon object
         *
         * @param points The points of the polygon
         * @param color The color of the polygon
         */
        Polygon(std::vector<Vector2D> points, Color color);
        /**
         * @brief Construct a new Polygon object
         *
         * @param shape The polygon to copy
         */
        Polygon(const Polygon &shape);
        /**
         * @brief Construct a new Polygon object
         *
         * @param s The string to use as source
         */
        Polygon(const std::string &s);

        // ==================== CLONE ====================
        Polygon *clone() const { return new Polygon(*this); }

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Polygon *homothety(const Vector2D &origin, double coeff) const;
        Polygon *translation(const Vector2D &v) const;
        Polygon *rotation(const Vector2D &origin, double alpha) const;
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