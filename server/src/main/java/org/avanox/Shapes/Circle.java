package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

import java.awt.Color;

public class Circle extends Shape {
    private Point _center;
    private int _radius;

    public Circle(Point center, int radius) {
        this._center = center;
        this._radius = radius;
        this.color = Color.BLACK;
    }

    public Circle(Point center, int radius, Color color) {
        this._center = center;
        this._radius = radius;
        this.color = color;
    }

    /**
     * Return the center point
     * 
     * @return the center point
     */
    public Point getCenter() {
        return this._center;
    }

    /**
     * Return the radius
     * 
     * @return the radius
     */
    public int getRadius() {
        return this._radius;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visit(this);
    }

    @Override
    public boolean equals(Object obj) {
        if (this.getClass() != obj.getClass())
            return false;
        if (!this._center.equals(((Circle) obj)._center))
            return false;
        if (this._radius != ((Circle) obj)._radius)
            return false;
        if (!this.color.equals(((Circle) obj).color))
            return false;

        return true;
    }

}
