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
        /**
         * @brief Construct a new Circle object
         *
         * @param points The points of the circle
         * @param color The color of the circle
         * @param radius The radius of the circle
         */
        Circle(std::vector<Vector2D> points, Color color, double radius);
        /**
         * @brief Construct a new Circle object
         *
         * @param shape The circle to copy
         */
        Circle(const Circle &shape);
        /**
         * @brief Construct a new Circle object
         *
         * @param s The string to use as source
         */
        Circle(const std::string &s);

        // ==================== CLONE ====================
        Circle *clone() const { return new Circle(*this); }

        // ==================== GETTERS ====================
        /**
         * @brief Get the radius of the circle
         *
         * @return double The radius of the circle
         */
        double getRadius() const { return _radius; }
        /**
         * @brief Get the Center object
         *
         * @return Vector2D The center point of the circle
         */
        Vector2D getCenter() const { return _points.at(0); }
        virtual Vector2D getBottomLeft() const;
        virtual Vector2D getTopRight() const;

        // ==================== SETTERS ====================
        /**
         * @brief Set the radius of the circle
         *
         * @param radius The new radius of the circle
         */
        void setRadius(double radius);

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