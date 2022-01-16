package org.avanox.visitor;

import org.avanox.Shapes.*;

public class DrawSwing extends Draw {
    private static DrawSwing instance;

    @Override
    public void visit(Triangle triangle) {
        System.out.println("Je vais dessiner un triangle en Swing");

    }

    @Override
    public void visit(Circle circle) {
        System.out.println("Je vais dessiner un cercle en Swing");

    }

    @Override
    public void visit(Segment segment) {
        System.out.println("Je vais dessiner un segment en Swing");

    }

    @Override
    public void visit(AnyPolygon other) {
        System.out.println("Je vais dessiner un polygone quelconque fermé en Swing");

    }

    @Override
    public void init() {
        // TODO Auto-generated method stub

    }

    public static DrawSwing getInstance() {
        if (instance == null)
            instance = new DrawSwing();
        return instance;
    }
}
