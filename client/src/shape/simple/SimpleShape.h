#pragma once

#include <vector>
#include <string>

#include "../Shape.h"

namespace shape
{
    class SimpleShape : public Shape
    {
    protected:
        std::vector<Vector2D> _points;

    public:
        // ==================== DESTRUCTORS ====================
        virtual ~SimpleShape() {}

        // ==================== CLONE ====================
        virtual Shape *clone() const = 0;

        // ==================== GETTERS ====================
        /**
         * @brief Get the Points object
         *
         * @return std::vector<Vector2D> The Points object
         */
        virtual std::vector<Vector2D> getPoints() const { return _points; }
        virtual Vector2D getBottomLeft() const;
        virtual Vector2D getTopRight() const;

        // ==================== SETTERS ====================
        /**
         * @brief Set the Points object
         *
         * @param points The new Points object
         */
        virtual void setPoints(std::vector<Vector2D> points) { _points = points; }

        // ==================== STRING ====================
        virtual operator std::string() const;

        // ==================== OPERATIONS ====================
        virtual SimpleShape *homothety(const Vector2D &origin, double coeff) const = 0;
        virtual SimpleShape *translation(const Vector2D &v) const = 0;
        virtual SimpleShape *rotation(const Vector2D &origin, double alpha) const = 0;
        virtual double area() const = 0;

        virtual void saveFile(const VisitorSaveFile *v, const std::string &filePath) const = 0;

        // ==================== OPERATORS ====================
        virtual bool operator==(Shape *shape) const;
        virtual bool operator!=(Shape *shape) const;
    };
} // namespace shape