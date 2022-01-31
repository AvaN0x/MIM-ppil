package org.avanox.visitor;

import javafx.application.Application;
import javafx.stage.Stage;

public class FXApplicationThread extends Application {
    private static FXApplicationThread instance;

    public FXApplicationThread() {
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
    }

    public static FXApplicationThread getInstance() {
        if (instance == null)
            instance = new FXApplicationThread();

        return instance;
    }

}
