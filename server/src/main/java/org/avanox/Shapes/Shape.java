package org.avanox.Shapes;

import org.avanox.visitor.ShapeVisitor;
import java.awt.Color;

public abstract class Shape {
    protected Color color;

    /**
     * Return the color of the shape
     * 
     * @return the color
     */
    public Color getColor() {
        return color;
    }

    /**
     * Visit a shape
     * 
     * @param visitor
     */
    abstract void accept(ShapeVisitor visitor);
}
