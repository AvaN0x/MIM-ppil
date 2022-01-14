package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

public class Segment extends Shape {

    private Point a;
    private Point b;

    public Segment(Point a, Point b) {
        this.a = a;
        this.b = b;
    }

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visit(this);
    }

}
