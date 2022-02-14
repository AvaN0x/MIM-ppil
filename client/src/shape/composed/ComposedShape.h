#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "../Shape.h"
#include "../../utils/Color.h"

class ComposedShape : public Shape
{
private:
    std::vector<Shape *> _shapes;

public:
    // ==================== CONSTRUCTORS ====================
    ComposedShape(Color color);
    ComposedShape(std::vector<Shape *> shapes, Color color);
    ComposedShape(const ComposedShape &composedShape);

    // ==================== DESTRUCTORS ====================
    ~ComposedShape();

    // ==================== CLONE ====================
    Shape *clone() const { return new ComposedShape(*this); }

    // ==================== GETTERS ====================
    std::vector<Shape *> getShapes() const { return _shapes; }

    // ==================== SETTERS ====================
    void addShape(Shape *shape);
    void removeShape(Shape *shape);

    // ==================== STRING ====================
    operator std::string() const;

    // ==================== OPERATIONS ====================
    Shape *homothety(const Vecteur2D &origin, double coeff) const;
    Shape *translation(const Vecteur2D &v) const;
    Shape *rotation(const Vecteur2D &origin, double alpha) const;
    double area() const;

    // ==================== OPERATORS ====================
    bool operator==(Shape *shape) const;
    bool operator!=(Shape *shape) const;
};