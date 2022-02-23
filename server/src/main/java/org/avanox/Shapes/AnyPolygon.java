package org.avanox.Shapes;

import java.util.LinkedList;

import org.avanox.visitor.ShapeVisitor;

import javafx.scene.paint.Color;

public class AnyPolygon extends Shape {
    private LinkedList<Point> _segments;
    private Color color;

    public AnyPolygon(LinkedList<Point> segments) {
        this._segments = segments;
        this.color = Color.BLACK;
    }

    public AnyPolygon(LinkedList<Point> segments, Color color) {
        this._segments = segments;
        this.color = color;
    }

    public LinkedList<Point> getSegments() {
        return _segments;
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
        if (!this._segments.containsAll(((AnyPolygon) obj)._segments))
            return false;
        if (!this.color.equals(((AnyPolygon) obj).color))
            return false;

        return true;
    }

}
