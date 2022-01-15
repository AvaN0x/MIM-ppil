package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

public class Triangle extends Shape {
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
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
        return true;
    }

}