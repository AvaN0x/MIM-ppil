#pragma once

#include <vector>
#include <string>
#include "Color.h"
#include "Vecteur2D.h"

class GroupShape;

class Shape
{
private:
	std::vector<Vecteur2D> _points;
	Color _color;
	GroupShape *_group;

public:
	// ==================== CONSTRUCTORS ====================
	Shape(std::vector<Vecteur2D> points, Color color, GroupShape *group = nullptr);
	Shape(const Shape &shape);
	Shape(const std::string &str);

	// ==================== DESTRUCTORS ====================
	virtual ~Shape() {}

	// ==================== CLONE ====================
	virtual Shape *clone() const = 0;

	// ==================== GETTERS ====================
	virtual std::vector<Vecteur2D> getPoints() const { return _points; }
	virtual Color getColor() const { return _color; }
	virtual GroupShape *getGroup() const { return _group; }
	virtual bool hasGroup() const { return _group != nullptr; }

	// ==================== SETTERS ====================
	virtual void setColor(Color color) { _color = color; }
	virtual void setGroup(GroupShape *group) { _group = group; }

	// ==================== STRING ====================
	virtual operator std::string() const;
	friend std::ostream &operator<<(std::ostream &os, const Shape &s);

	// ==================== OPERATIONS ====================
	virtual Shape *homothety(const Vecteur2D &origin, double coeff) const = 0;
	virtual Shape *translation(const Vecteur2D &v) const = 0;
	virtual Shape *rotation(const Vecteur2D &origin, double alpha) const = 0;
	virtual double area() const = 0;

	// ==================== OPERATORS ====================
	virtual bool operator==(const Shape &shape) const = 0;
	virtual bool operator!=(const Shape &shape) const = 0;
};

inline std::ostream &operator<<(std::ostream &os, const Shape &s)
{
	return os << (std::string)s;
}