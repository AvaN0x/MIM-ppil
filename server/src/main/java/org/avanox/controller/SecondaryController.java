package org.avanox.controller;

import java.io.IOException;
import javafx.fxml.FXML;

import org.avanox.App;

public class SecondaryController {

    @FXML
    private void switchToPrimary() throws IOException {
        App.setRoot("primary");
    }
}