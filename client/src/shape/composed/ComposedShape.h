#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "../Shape.h"
#include "../../utils/Color.h"

namespace shape
{
    class ComposedShape : public Shape
    {
    private:
        std::vector<Shape *> _shapes;

    public:
        // ==================== CONSTRUCTORS ====================
        ComposedShape();
        ComposedShape(Color color);
        ComposedShape(std::vector<Shape *> shapes, Color color);
        ComposedShape(const ComposedShape &composedShape);

        // ==================== DESTRUCTORS ====================
        ~ComposedShape();

        // ==================== CLONE ====================
        Shape *clone() const { return new ComposedShape(*this); }

        // ==================== GETTERS ====================
        /**
         * @brief Get the Shapes object
         *
         * @return std::vector<Shape *> The Shapes object
         */
        std::vector<Shape *> getShapes() const { return _shapes; }

        // ==================== SETTERS ====================
        virtual void setColor(Color color);
        /**
         * @brief Add a shape to the ComposedShape
         *
         * @param shape The shape to add
         * @return Shape* The added shape
         */
        Shape *addShape(Shape *shape);
        /**
         * @brief Remove a shape from the ComposedShape
         *
         * @param shape The shape to remove
         */
        void removeShape(Shape *shape);
        virtual Vector2D getBottomLeft() const;
        virtual Vector2D getTopRight() const;

        // ==================== STRING ====================
        operator std::string() const;

        // ==================== OPERATIONS ====================
        ComposedShape *homothety(const Vector2D &origin, double coeff) const;
        ComposedShape *translation(const Vector2D &v) const;
        ComposedShape *rotation(const Vector2D &origin, double alpha) const;
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