package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

import javafx.scene.paint.Color;

public class Triangle extends Shape {
    private Point a;
    private Point b;
    private Point c;
    private Color color;

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

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
    }

    public Point getC() {
        return c;
    }

    public Color getColor() {
        return color;
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
