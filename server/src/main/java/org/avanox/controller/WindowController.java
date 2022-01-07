package org.avanox.controller;

import javafx.scene.layout.Pane;
import javafx.fxml.FXML;

public class WindowController {
    @FXML
    private Pane pane;

    @FXML
    private void click() {
        System.out.println("Click" + Thread.currentThread().getName());
    }
}