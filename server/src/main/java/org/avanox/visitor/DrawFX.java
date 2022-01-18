package org.avanox.visitor;

import org.avanox.Shapes.*;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

public class DrawFX extends Draw {
    private static Stage stage;

    @Override
    public void visit(Triangle triangle) {
        System.out.println("Je vais dessiner un triangle en FX");

    }

    @Override
    public void visit(Circle circle) {
        System.out.println("Je vais dessiner un cercle en FX");

    }

    @Override
    public void visit(Segment segment) {
        System.out.println("Je vais dessiner un segment en FX");

    }

    @Override
    public void visit(AnyPolygon other) {
        System.out.println("Je vais dessiner un polygone quelconque fermé en FX");

    }

    @Override
    public void closeDraw() {
        // TODO Auto-generated method stub

    }
}
