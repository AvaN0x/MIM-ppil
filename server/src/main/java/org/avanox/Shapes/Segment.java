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

    @Override
    public boolean equals(Object obj) {
        if (this.getClass() != obj.getClass())
            return false;
        if (!this.a.equals(((Segment) obj).a))
            return false;
        if (!this.b.equals(((Segment) obj).b))
            return false;

        return true;
    }

}
