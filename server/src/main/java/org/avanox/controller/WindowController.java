package org.avanox.controller;

import javafx.scene.layout.Pane;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.event.EventHandler;

import javafx.scene.input.MouseEvent;

public class WindowController {
    @FXML
    private Pane pane;

    @FXML
    private void click() {
        System.out.println("Click");
    }
}