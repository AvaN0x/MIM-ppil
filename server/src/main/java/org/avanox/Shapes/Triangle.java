package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

import java.awt.Color;

public class Triangle extends Shape {
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.color = Color.BLACK;
    }

    public Triangle(Point a, Point b, Point c, Color color) {
        this.a = a;
        this.b = b;
        this.c = c;
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

    /**
     * Return point C
     * 
     * @return the point c
     */
    public Point getC() {
        return c;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visit(this);
    }

    @Override
    public boolean equals(Object obj) {
        if (this.getClass() != obj.getClass())
            return false;
        if (!this.a.equals(((Triangle) obj).a))
            return false;
        if (!this.b.equals(((Triangle) obj).b))
            return false;
        if (!this.c.equals(((Triangle) obj).c))
            return false;
        if (!this.color.equals(((Triangle) obj).color))
            return false;

        return true;
    }

}
