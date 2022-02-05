#pragma once

#include <vector>
#include <string>

#include "../Shape.h"
// #include "../utils/Color.h"
// #include "Vecteur2D.h"

class Vecteur2D;
class Color;

class SimpleShape : public Shape
{
protected:
	std::vector<Vecteur2D> _points;

public:
	// ==================== CONSTRUCTORS ====================
	// SimpleShape(std::vector<Vecteur2D> points, Color color);
	// SimpleShape(const SimpleShape &shape);
	// SimpleShape(const std::string &str);

	// ==================== DESTRUCTORS ====================
	virtual ~SimpleShape() {}

	// ==================== CLONE ====================
	virtual Shape *clone() const = 0;

	// ==================== GETTERS ====================
	virtual std::vector<Vecteur2D> getPoints() const { return _points; }

	// ==================== SETTERS ====================
	virtual void setPoints(std::vector<Vecteur2D> points) { _points = points; }

	// ==================== STRING ====================
	virtual operator std::string() const;

	// ==================== OPERATIONS ====================
	virtual SimpleShape *homothety(const Vecteur2D &origin, double coeff) const = 0;
	virtual SimpleShape *translation(const Vecteur2D &v) const = 0;
	virtual SimpleShape *rotation(const Vecteur2D &origin, double alpha) const = 0;
	virtual double area() const = 0;

	// ==================== OPERATORS ====================
	virtual bool operator==(Shape *shape) const = 0;
	virtual bool operator!=(Shape *shape) const = 0;
};