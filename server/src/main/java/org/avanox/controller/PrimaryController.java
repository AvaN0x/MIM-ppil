package org.avanox.controller;

import java.io.IOException;
import javafx.fxml.FXML;

import org.avanox.App;

public class PrimaryController {

    @FXML
    private void switchToSecondary() throws IOException {
        App.setRoot("secondary");
    }
}
