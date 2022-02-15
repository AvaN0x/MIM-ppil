#pragma once
#include "Vector2D.h"
#include "../utils/Color.h"
#include "files/VisitorSaveFile.h"

namespace shape
{
    class Shape
    {
    protected:
        Color _color;

    public:
        // ==================== DESTRUCTORS ====================
        virtual ~Shape() {}

        // ==================== CLONE ====================
        virtual Shape *clone() const = 0;

        // ==================== GETTERS ====================
        virtual Color getColor() const { return _color; }

        // ==================== SETTERS ====================
        virtual void setColor(Color color) { _color = color; }

        // ==================== STRING ====================
        virtual operator std::string() const = 0;
        friend std::ostream &operator<<(std::ostream &os, const Shape &s);

        // ==================== OPERATIONS ====================
        virtual Shape *homothety(const Vector2D &origin, double coeff) const = 0;
        virtual Shape *translation(const Vector2D &v) const = 0;
        virtual Shape *rotation(const Vector2D &origin, double alpha) const = 0;
        virtual double area() const = 0;

        virtual void saveFile(const VisitorSaveFile *v, const std::string filePath) const = 0;

        // ==================== OPERATORS ====================
        virtual bool operator==(Shape *shape) const = 0;
        virtual bool operator!=(Shape *shape) const = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Shape &s)
    {
        return os << (std::string)s;
    }
} // namespace shape

// virtual void saveToFile(visitor idk) const = 0; // TODO @AvaN0x
// in the visitor have something like Shape visitor::getShapeFromFile(std::string fileName) const;
