package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

public class Circle extends Shape {
    private Point _center;
    private double _radius;

    public Circle(Point center, double radius) {
        this._center = center;
        this._radius = radius;
    }

    public Point getCenter() {
        return this._center;
    }

    public double getRadius() {
        return this._radius;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visit(this);
    }

}
