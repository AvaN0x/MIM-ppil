package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

import javafx.scene.paint.Color;

public class Segment extends Shape {
    private Point a;
    private Point b;
    private Color color;

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

    public Point getA() {
        return a;
    }

    public Point getB() {
        return b;
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
        if (!this.a.equals(((Segment) obj).a))
            return false;
        if (!this.b.equals(((Segment) obj).b))
            return false;
        if (!this.color.equals(((Segment) obj).color))
            return false;

        return true;
    }

}
