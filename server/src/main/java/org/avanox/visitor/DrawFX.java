package org.avanox.visitor;

import org.avanox.Shapes.*;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

public class DrawFX extends Draw {
    private static DrawFX instance;
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
    public void init() {
        Application.launch(FXApplicationThread.class);
        // Platform.runLater(() -> {
        // stage = new Stage();
        // });
    }

    public static DrawFX getInstance() {
        if (instance == null)
            instance = new DrawFX();
        return instance;
    }
}
