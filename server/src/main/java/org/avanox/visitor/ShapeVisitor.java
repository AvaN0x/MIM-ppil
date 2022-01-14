package org.avanox.visitor;

import org.avanox.Shapes.*;

public interface ShapeVisitor {
    void visit(Triangle triangle);

    void visit(Circle circle);

    void visit(Segment segment);

    void visit(Other other);
}
