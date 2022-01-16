package org.avanox.visitor;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

public class FXApplicationThread extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Platform.setImplicitExit(true);
        primaryStage.showAndWait();
    }

}
