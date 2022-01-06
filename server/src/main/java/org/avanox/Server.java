package org.avanox;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.logging.Logger;

import io.github.cdimascio.dotenv.Dotenv;

public class Server extends Thread {
    private static Logger _LOGGER;
    private ServerSocket _serverSocket = null;

    /**
     * Constructor
     * 
     * @param LOGGER The logger to print infos
     */
    public Server(Logger LOGGER) {
        _LOGGER = LOGGER;
    }

    @Override
    public void run() {
        // Load environment variables
        Dotenv dotenv = Dotenv.load();
        try {
            // Start server on port indicated in .env file
            _serverSocket = new ServerSocket(Integer.parseInt(dotenv.get("SERVER_PORT")));
            _LOGGER.info("Serveur de majuscule pret au port : " + _serverSocket.getLocalPort());

            int noClient = 0;
            Socket socket = null;
            try {
                while (true) {
                    socket = _serverSocket.accept();
                    _LOGGER.info("Connexion [" + noClient + "] reussie");
                    new Interlocuteur(socket, noClient++).start();
                }
            } catch (SocketTimeoutException e) {
                _LOGGER.severe("Le delai d'attente de la socket est depasse.");
            } catch (SocketException e) {
                /*
                 * When server is blocked in `accept()` and methode `_serverSocket.close()` has
                 * been called
                 * Ignore it because we are going to close server
                 */
            } catch (IOException e) {
                _LOGGER.severe("Une erreur est survenue lors de l'attente d'une connexion à la socket.");
                System.err.println(e);
            }
        } catch (IOException e) {
            _LOGGER.severe("Une erreur est survenue lors de l'ouverture du serveur.");
            System.err.println(e);
        } catch (IllegalArgumentException e) {
            _LOGGER.severe("Le port specifie n'est pas un port valide.");
        } finally {
            closeServer();
        }
    }

    /**
     * Close the socket of the server
     */
    public void closeServer() {
        if (_serverSocket != null) {
            try {
                _serverSocket.close();
                _serverSocket = null;
                _LOGGER.info("Le serveur a ete interrompu.");
            } catch (IOException e) {
                _LOGGER.severe("Une erreur s'est produite lors de la fermeture du serveur.");
                System.err.println(e);
            }
        }
    }
}