package org.avanox.Shapes;

import java.util.LinkedList;

import org.avanox.visitor.ShapeVisitor;

public class AnyPolygon extends Shape {
    private LinkedList<Point> _segments;

    public AnyPolygon(LinkedList<Point> segments) {
        this._segments = segments;
    }

    public LinkedList<Point> getSegments() {
        return _segments;
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

        return true;
    }

}
