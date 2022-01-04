package org.avanox;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

import org.avanox.exceptions.InterlocuteurException;

public class Serveur {
    private static final LogManager logManager = LogManager.getLogManager();
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    public static void main(String[] args) {
        try {
            logManager.readConfiguration(new FileInputStream("logger.properties"));
        } catch (Exception exception) {
            LOGGER.log(Level.WARNING,
                    "Le fichier de configuration de log n'a pas pu etre ouvert, configuration par defaut utilisee.");
        }

        System.out.println("----- SERVEUR -----");
        ServerSocket server = null;

        try {
            int portServeur = 9111;
            server = new ServerSocket(portServeur);
            LOGGER.info("Serveur de majuscule pret au port : " + server.getLocalPort());

            int noClient = 0;
            Socket socket = null;
            try {
                while (true) {
                    socket = server.accept();
                    LOGGER.log(Level.CONFIG, "Hello");
                    LOGGER.info("Connexion [" + noClient + "] reussie");
                    new Interlocuteur(socket, noClient++).start();
                }
            } catch (SocketTimeoutException e) {
                LOGGER.severe("Le delai d'attente de la socket est depasse.");
            } catch (InterlocuteurException e) {
                LOGGER.severe("Code " + e.getCode() + " : " + e.getMessage());
            } catch (IOException e) {
                LOGGER.severe("Une erreur est survenue lors de l'attente d'une connexion à la socket.");
                System.err.println(e);
            } finally {
                if (server != null) {
                    try {
                        server.close();
                    } catch (IOException e) {
                        LOGGER.severe("Une erreur s'est produite lors de la fermeture du serveur.");
                        System.err.println(e);
                    }
                }
            }
        } catch (IOException e) {
            LOGGER.severe("Une erreur est survenue lors de l'ouverture de la socket.");
            System.err.println(e);
        } catch (IllegalArgumentException e) {
            LOGGER.severe("Le port specifie n'est pas un port valide.");
        }
    }
}
