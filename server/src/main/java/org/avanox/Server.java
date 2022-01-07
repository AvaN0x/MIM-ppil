package org.avanox;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

import io.github.cdimascio.dotenv.Dotenv;

public class Server extends Application {
    private static Server instance = null;

    private static final LogManager logManager = LogManager.getLogManager();
    private static final Logger _LOGGER = Logger.getLogger("Serveur");

    private static Scene scene;

    @Override
    public void start(Stage primaryStage) throws IOException {
        // Load environment variables
        Dotenv dotenv = Dotenv.load();

        // Load configuration file for LOGGER
        try {
            logManager.readConfiguration(new FileInputStream(dotenv.get("LOGGER_PROPERTIES_FILE")));
        } catch (Exception exception) {
            _LOGGER.log(Level.WARNING,
                    "Le fichier de configuration de log n'a pas pu etre ouvert, la configuration par defaut va etre utilisee.");
        }

        System.out.println("----- SERVEUR -----");
        int port = 9111;
        try {
            port = Integer.parseInt(dotenv.get("SERVER_PORT"));
        } catch (NumberFormatException e) {
            _LOGGER.warning(
                    "Le port specifie dans le fichier de configuration n'est pas un nombre valide. Utilisation du port par default 9111.");
        }

        final int fport = port;
        Thread t = new Thread(() -> {
            startServer(fport);
        });
        t.start();
    }

    private void startServer(int port) {
        ServerSocket serverSocket = null;
        try {
            // Start server on port indicated in .env file
            serverSocket = new ServerSocket(port);
            _LOGGER.info("Serveur de majuscule pret au port : " + serverSocket.getLocalPort());

            int noClient = 0;
            Socket socket = null;
            try {
                while (true) {
                    socket = serverSocket.accept();
                    Interlocuteur interlocuteur = new Interlocuteur(socket, noClient++);
                    _LOGGER.info("Connexion [" + noClient + "] reussie");
                    interlocuteur.start();
                }
            } catch (SocketTimeoutException e) {
                _LOGGER.severe("Le delai d'attente de la socket est depasse.");
            } catch (SocketException e) {
                e.printStackTrace();
                /*
                 * When server is blocked in `accept()` and methode `serverSocket.close()` has
                 * been called
                 * Ignore it because we are going to close server
                 */
            } catch (IOException e) {
                _LOGGER.severe("Une erreur est survenue lors de l'attente d'une connexion à la socket.");
                System.err.println(e);
            } catch (Exception e) {
                e.printStackTrace();
            }
        } catch (IOException e) {
            _LOGGER.severe("Une erreur est survenue lors de l'ouverture du serveur.");
            System.err.println(e);
        } catch (IllegalArgumentException e) {
            _LOGGER.severe("Le port specifie n'est pas un port valide.");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            closeServer(serverSocket);
        }
    }

    public static void main(String[] args) {
        launch();
    }

    /**
     * Close the socket of the server
     */
    private void closeServer(ServerSocket serverSocket) {
        if (serverSocket != null) {
            try {
                serverSocket.close();
                serverSocket = null;
                _LOGGER.info("Le serveur a ete interrompu.");
            } catch (IOException e) {
                _LOGGER.severe("Une erreur s'est produite lors de la fermeture du serveur.");
                System.err.println(e);
            }
        }
    }
}