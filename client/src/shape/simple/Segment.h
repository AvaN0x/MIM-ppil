#pragma once

#include "SimpleShape.h"

namespace shape
{
    class Segment : public SimpleShape
    {
    public:
        // ==================== CONSTRUCTORS ====================
        /**
         * @brief Construct a new Segment object
         *
         * @param points The points of the segment
         * @param color The color of the segment
         */
        Segment(std::vector<Vector2D> points, Color color);
        /**
         * @brief Construct a new Segment object
         *
         * @param shape The segment to copy
         */
        Segment(const Segment &shape);
        /**
         * @brief Construct a new Segment object
         *
         * @param s The string to use as source
         */
        Segment(const std::string &s);

        // ==================== CLONE ====================
        Segment *clone() const { return new Segment(*this); }

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        Segment *homothety(const Vector2D &origin, double coeff) const;
        Segment *translation(const Vector2D &v) const;
        Segment *rotation(const Vector2D &origin, double alpha) const;
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