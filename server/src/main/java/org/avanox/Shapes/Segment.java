package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

import java.awt.Color;

public class Segment extends Shape {
    private Point a;
    private Point b;

    public Segment(Point a, Point b) {
        this.a = a;
        this.b = b;
        this.color = Color.BLACK;
    }

    public Segment(Point a, Point b, Color color) {
        this.a = a;
        this.b = b;
        this.color = color;
    }

    /**
     * Return point A
     * 
     * @return the point a
     */
    public Point getA() {
        return a;
    }

    /**
     * Return point B
     * 
     * @return the point b
     */
    public Point getB() {
        return b;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visit(this);
    }

    @Override
    public boolean equals(Object obj) {
        if (this.getClass() != obj.getClass())
            return false;
        if (!this.a.equals(((Segment) obj).a))
            return false;
        if (!this.b.equals(((Segment) obj).b))
            return false;
        if (!this.color.equals(((Segment) obj).color))
            return false;

        return true;
    }

}
