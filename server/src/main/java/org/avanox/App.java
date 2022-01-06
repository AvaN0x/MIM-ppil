package org.avanox;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import io.github.cdimascio.dotenv.Dotenv;

public class App extends Application {
    private static final LogManager logManager = LogManager.getLogManager();
    private static final Logger LOGGER = Logger.getLogger("Serveur");
    private static Scene scene;

    @Override
    public void start(Stage stage) throws IOException {
        // Load environment variables
        Dotenv dotenv = Dotenv.load();

        // Load configuration file for LOGGER
        try {
            logManager.readConfiguration(new FileInputStream(dotenv.get("LOGGER_PROPERTIES_FILE")));
        } catch (Exception exception) {
            LOGGER.log(Level.WARNING,
                    "Le fichier de configuration de log n'a pas pu etre ouvert, la configuration par defaut va etre utilisee.");
        }

        // Load first scene
        scene = new Scene(loadFXML("primary"), 900, 514);
        stage.setTitle("Gestionnaire de mot de passe");
        setIcon(stage);
        stage.setScene(scene);
        stage.show();

        // Create the server
        Server server = new Server(LOGGER);

        // Interrupt server's thread when closing application
        stage.setOnCloseRequest(e -> {
            server.closeServer();
            Platform.exit(); // JavaVM will not exit because non-daemon threads are still running
            System.exit(0);
        });

        System.out.println("----- SERVEUR -----");
        server.start();
    }

    private static void setIcon(Stage stage) {
        stage.getIcons().add(new Image(App.class.getResourceAsStream("img/title-ico.png")));
    }

    static void setRoot(String fxml) throws IOException {
        scene.setRoot(loadFXML(fxml));
    }

    private static Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }

    public static void main(String[] args) {
        launch();
    }
}
