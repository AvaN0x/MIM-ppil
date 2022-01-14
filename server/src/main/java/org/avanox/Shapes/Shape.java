package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;

public abstract class Shape {
    abstract void accept(ShapeVisitor visitor);
}
