#pragma once
#include "Vector2D.h"
#include "../utils/Color.h"
#include "files/VisitorSaveFile.h"
#include "draw/VisitorDrawShape.h"

class ConnectionHandler;
class WorldToScreen;

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
        /**
         * @brief Clone the shape
         * @return The cloned shape
         */
        virtual Shape *clone() const = 0;

        // ==================== GETTERS ====================
        /**
         * @brief Get the color of the shape
         * @return The color of the shape
         */
        virtual Color getColor() const { return _color; }
        /**
         * @brief Get the extrem bottom left vector of the shape
         * @return The extrem bottom left vector of the shape
         */
        virtual Vector2D getBottomLeft() const = 0;
        /**
         * @brief Get the extrem top right vector of the shape
         * @return The extrem top right vector of the shape
         */
        virtual Vector2D getTopRight() const = 0;

        // ==================== SETTERS ====================
        /**
         * @brief Set the color of the shape
         * @param color The new color of the shape
         */
        virtual void setColor(Color color) { _color = color; }

        // ==================== STRING ====================
        /**
         * @brief Get the string representation of the shape
         * @return The string representation of the shape
         */
        virtual operator std::string() const = 0;
        friend std::ostream &operator<<(std::ostream &os, const Shape &s);

        // ==================== OPERATIONS ====================
        /**
         * @brief Apply homothety to the shape
         *
         * @param origin The origin of the homothety
         * @param coeff The coefficient of the homothety
         * @return Shape* A new shape pointer
         */
        virtual Shape *homothety(const Vector2D &origin, double coeff) const = 0;
        /**
         * @brief Apply a translation to the shape
         *
         * @param v The translation vector
         * @return Shape* A new shape pointer
         */
        virtual Shape *translation(const Vector2D &v) const = 0;
        /**
         * @brief Apply rotation to the shape
         *
         * @param origin The origin of the rotation
         * @param alpha The alpha of the rotation
         * @return Shape* A new shape pointer
         */
        virtual Shape *rotation(const Vector2D &origin, double alpha) const = 0;
        /**
         * @brief Calculate the area of the shape
         *
         * @return double Area of the shape
         */
        virtual double area() const = 0;

        // ==================== VISITORS ====================
        /**
         * @brief Visitor to draw the shape
         *
         * @param v The visitor
         * @param connection The connection handler
         * @param wts The world to screen object
         */
        virtual void draw(const VisitorDrawShape *v, ConnectionHandler *connection = nullptr, WorldToScreen *wts = nullptr) const = 0;
        /**
         * @brief Visitor to save the shape
         *
         * @param v The visitor
         * @param filePath The file path
         */
        virtual void saveFile(const VisitorSaveFile *v, const std::string &filePath) const = 0;

        // ==================== OPERATORS ====================
        /**
         * @brief Compare two shapes for equality
         *
         * @param u The other shape
         * @return bool Shapes are equal
         */
        virtual bool operator==(Shape *shape) const = 0;
        /**
         * @brief Compare two shapes for non equality
         *
         * @param u The other shape
         * @return bool Shapes are not equal
         */
        virtual bool operator!=(Shape *shape) const = 0;
    };

    inline std::ostream &operator<<(std::ostream &os, const Shape &s)
    {
        return os << (std::string)s;
    }
} // namespace shape
