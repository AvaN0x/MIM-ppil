#pragma once

#include <vector>
#include <string>
#include <sstream>

class Shape;
class Vecteur2D;

class GroupShape
{
private:
    const int _groupId;
    std::vector<Shape *> _shapes;

public:
    // ==================== CONSTRUCTORS ====================
    GroupShape(std::vector<Shape *> shapes, int groupId);
    GroupShape(const GroupShape &composedShape, int groupId);

    // ==================== DESTRUCTORS ====================
    ~GroupShape();

    // ==================== CLONE ====================
    GroupShape *clone() const { return new GroupShape(*this); }

    // ==================== GETTERS ====================
    int getId() const { return _groupId; }
    std::vector<Shape *> getShapes() const { return _shapes; }

    // ==================== SETTERS ====================
    void addShape(Shape *shape);
    void removeShape(Shape *shape);

    // ==================== STRING ====================
    operator std::string() const;
    friend std::ostream &operator<<(std::ostream &os, const GroupShape &s);

    // ==================== OPERATIONS ====================
    GroupShape homothety(const Vecteur2D &origin, double coeff) const;
    GroupShape translation(const Vecteur2D &v) const;
    GroupShape rotation(const Vecteur2D &origin, double alpha) const;
    double area() const;

    // ==================== OPERATORS ====================
    bool operator==(const GroupShape &shape) const;
    bool operator!=(const GroupShape &shape) const;
};