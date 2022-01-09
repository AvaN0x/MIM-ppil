package org.avanox;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.logging.Logger;

public class Server implements Runnable {
    private static final Logger LOGGER = Logger.getLogger("Serveur");
    private ServerSocket _serverSocket;

    public Server(int port) throws IOException {
        _serverSocket = new ServerSocket(port);
        LOGGER.info("Serveur de majuscule pret au port : " + _serverSocket.getLocalPort());
    }

    @Override
    public void run() {
        try {
            ThreadGroup clientThreads = new ThreadGroup("clients");

            int noClient = 0;
            Socket socket = null;
            try {
                while (!Thread.currentThread().isInterrupted()) {
                    socket = _serverSocket.accept();
                    Interlocuteur interlocuteur = new Interlocuteur(clientThreads, socket, noClient++);
                    LOGGER.info("Connexion [" + noClient + "] reussie");
                    interlocuteur.start();
                }
                System.out.println("ned");
            } catch (SocketTimeoutException e) {
                LOGGER.severe("Le delai d'attente de la socket est depasse.");
            } catch (SocketException e) {
                e.printStackTrace();
                /*
                 * When server is blocked in `accept()` and methode `_serverSocket.close()` has
                 * been called
                 * Ignore it because we are going to close server
                 */
            } catch (IOException e) {
                LOGGER.severe("Une erreur est survenue lors de l'attente d'une connexion à la socket.");
                System.err.println(e);
            } catch (Exception e) {
                e.printStackTrace();
            }
        } catch (IllegalArgumentException e) {
            LOGGER.severe("Le port specifie n'est pas un port valide.");
        } catch (Exception e) {
            e.printStackTrace();
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
                LOGGER.info("Fermeture du serveur ...");
                _serverSocket.close();
                _serverSocket = null;
                LOGGER.info("Le serveur a ete interrompu.");
            } catch (IOException e) {
                LOGGER.severe("Une erreur s'est produite lors de la fermeture du serveur.");
                System.err.println(e);
            }
        }
    }
}
