package org.avanox.visitor;

public abstract class Draw implements ShapeVisitor {
    /**
     * Close everything needed to draw the shapes
     */
    public abstract void closeDraw();
}
