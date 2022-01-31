package org.avanox.visitor;

import org.avanox.Shapes.*;

import javafx.stage.Stage;

public class DrawFX extends Draw {
    private static DrawFX instance;
    private static Stage stage;

    public DrawFX() {
        // TODO
    }

    @Override
    public void visit(Triangle triangle) {
        System.out.println("Je vais dessiner un triangle en FX");
        // TODO

    }

    @Override
    public void visit(Circle circle) {
        System.out.println("Je vais dessiner un cercle en FX");
        // TODO
    }

    @Override
    public void visit(Segment segment) {
        System.out.println("Je vais dessiner un segment en FX");
        // TODO
    }

    @Override
    public void visit(AnyPolygon other) {
        System.out.println("Je vais dessiner un polygone quelconque fermé en FX");
        // TODO
    }

    @Override
    public void closeDraw() {
        // TODO Auto-generated method stub

    }

    public DrawFX getInstance() {
        if (instance == null)
            instance = new DrawFX();

        return instance;
    }
}
