package org.avanox.Shapes;

import java.util.LinkedList;

import org.avanox.visitor.ShapeVisitor;

public class Other extends Shape {
    private LinkedList<Segment> _segments;

    public Other(LinkedList<Segment> segments) {
        this._segments = segments;
    }

    public LinkedList<Segment> getSegments() {
        return _segments;
    }

    @Override
    public void accept(ShapeVisitor visitor) {
        visitor.visit(this);
    }

}
