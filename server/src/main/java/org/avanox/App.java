package org.avanox;

import java.awt.Frame;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

import io.github.cdimascio.dotenv.Dotenv;
import javafx.application.Platform;

public class App {
    private static final LogManager logManager = LogManager.getLogManager();
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    public static void main(String[] args) {
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
        try {
            Server server = new Server(fport);
            Thread server_t = new Thread(server);

            Runtime.getRuntime().addShutdownHook(new Thread() {
                @Override
                public void run() {
                    // Frame[] frames = Frame.getFrames();
                    Platform.exit();
                    LOGGER.info("Fermeture du serveur ...");
                    server.closeServer();
                    LOGGER.info("Le serveur a ete interrompu.");
                }
            });

            // server_t.setDaemon(true);
            server_t.start();

        } catch (IOException e) {
            LOGGER.severe("Une erreur est survenue lors de l'ouverture du serveur.");
            System.err.println(e);
            System.exit(0);
        }
    }
}
