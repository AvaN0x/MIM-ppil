package org.avanox.visitor;

import org.avanox.Shapes.*;

public interface ShapeVisitor {
    /**
     * Visit a shape
     * 
     * @param triangle
     */
    void visit(Triangle triangle);

    /**
     * Visit a shape
     * 
     * @param circle
     */
    void visit(Circle circle);

    /**
     * Visit a shape
     * 
     * @param segment
     */
    void visit(Segment segment);

    /**
     * Visit a shape
     * 
     * @param other
     */
    void visit(AnyPolygon other);
}
