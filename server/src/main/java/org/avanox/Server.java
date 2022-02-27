package org.avanox;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.util.logging.Logger;

public class Server extends ServerSocket implements Runnable {
    private static final Logger LOGGER = Logger.getLogger("Serveur");
    private ThreadGroup clientThreads = new ThreadGroup("clients");

    /**
     * Constructor, will create a server socket on the specified port
     * 
     * @param port the port to listen
     * @throws IOException
     */
    public Server(int port) throws IOException {
        super(port);
        LOGGER.info("Serveur de dessin pret au port : " + this.getLocalPort());
    }

    @Override
    public void run() {
        try {
            int noClient = 0;
            Socket socket = null;
            try {
                while (!Thread.currentThread().isInterrupted()) {
                    socket = this.accept();
                    Interlocutor interlocutor = new Interlocutor(clientThreads, socket, noClient);
                    LOGGER.info("Connexion [" + noClient++ + "] reussie");
                    interlocutor.start();
                }
            } catch (SocketTimeoutException e) {
                LOGGER.severe("Le delai d'attente de la socket est depasse.");
            } catch (SocketException e) {
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
        if (!Thread.currentThread().isInterrupted()) {
            try {
                this.close();
                Thread.currentThread().interrupt();
            } catch (IOException e) {
                LOGGER.severe("Une erreur s'est produite lors de la fermeture du serveur.");
                System.err.println(e);
            }
        }
    }
}
