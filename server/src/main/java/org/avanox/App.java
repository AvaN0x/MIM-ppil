package org.avanox;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

import io.github.cdimascio.dotenv.Dotenv;

public class App extends Application {
    private static final LogManager logManager = LogManager.getLogManager();
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    @Override
    public void start(Stage primaryStage) throws IOException {
        primaryStage.show();
        primaryStage.close();

        // Load environment variables
        Dotenv dotenv = Dotenv.load();

        // Load configuration file for LOGGER
        try {
            logManager.readConfiguration(new FileInputStream(dotenv.get("LOGGER_PROPERTIES_FILE")));
        } catch (Exception exception) {
            LOGGER.log(Level.WARNING,
                    "Le fichier de configuration de log n'a pas pu etre ouvert, la configuration par defaut va etre utilisee.");
        }

        System.out.println("----- SERVEUR -----");
        int port = 9111;
        try {
            port = Integer.parseInt(dotenv.get("SERVER_PORT"));
        } catch (NumberFormatException e) {
            LOGGER.warning(
                    "Le port specifie dans le fichier de configuration n'est pas un nombre valide. Utilisation du port par default 9111.");
        }

        final int fport = port;
        Runnable server = null;
        try {
            server = new Server(fport);
        } catch (IOException e) {
            LOGGER.severe("Une erreur est survenue lors de l'ouverture du serveur.");
            System.err.println(e);
            Platform.exit();
            System.exit(0);
        }

        Thread server_t = new Thread(server);

        Runtime.getRuntime().addShutdownHook(new Thread() {
            @Override
            public void run() {
                System.out.println("got it");
                // server_t.interrupt();
            }
        });
        // server_t.setDaemon(true);
        server_t.start();
    }

    public static void main(String[] args) {
        launch();
    }
}