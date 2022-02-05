#pragma once

#include <vector>
#include <string>

#include "../Shape.h"

class SimpleShape : public Shape
{
protected:
	std::vector<Vecteur2D> _points;

public:
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
	virtual Shape *homothety(const Vecteur2D &origin, double coeff) const = 0;
	virtual Shape *translation(const Vecteur2D &v) const = 0;
	virtual Shape *rotation(const Vecteur2D &origin, double alpha) const = 0;
	virtual double area() const = 0;

	// ==================== OPERATORS ====================
	virtual bool operator==(Shape *shape) const;
	virtual bool operator!=(Shape *shape) const;
};