package org.avanox.visitor;

import org.avanox.Shapes.*;

public class DrawAWT implements Draw {

    @Override
    public void visit(Triangle triangle) {
        System.out.println("Je vais dessiner un triangle en AWT");

    }

    @Override
    public void visit(Circle circle) {
        System.out.println("Je vais dessiner un cercle en AWT");

    }

    @Override
    public void visit(Segment segment) {
        System.out.println("Je vais dessiner un segment en AWT");

    }

    @Override
    public void visit(Other other) {
        System.out.println("Je vais dessiner un polygone quelconque fermé en AWT");

    }
}
