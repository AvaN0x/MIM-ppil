package org.avanox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.SocketException;
import java.util.logging.Logger;

public class Interlocuteur extends Thread {
    private BufferedReader _fluxEntrant = null;
    private PrintStream _fluxSortant = null;
    private static final Logger LOGGER = Logger.getLogger("Serveur");
    private Socket _socket = null;

    int _noClient;

    public Interlocuteur(Socket socket, int noClient) {
        try {
            this._fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            this._fluxSortant = new PrintStream(socket.getOutputStream());
            this._noClient = noClient;
            this._socket = socket;
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la creation de l'interlocuteur.");
            System.err.println(e);
            closeStreamAndSocket();
        }
    }

    @Override
    public void run() {
        try {
            while (!this.isInterrupted()) {
                String requete = _fluxEntrant.readLine();
                if (requete == null)
                    throw new SocketException();

                LOGGER.info("Client [" + _noClient + "] A envoye : " + requete);
                _fluxSortant.println(requete.toUpperCase());
            }
        } catch (SocketException e) {
            LOGGER.info("Client [" + _noClient + "] La connexion a ete interrompue");
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la lecture de la requete");
            System.err.println(e);
        } finally {
            closeStreamAndSocket();
        }
    }

    private void closeStreamAndSocket() {
        LOGGER.info("Fermeture des flux et de la socket du client [" + _noClient + "]...");
        try {
            if (_fluxEntrant != null)
                _fluxEntrant.close();
            if (_fluxSortant != null)
                _fluxSortant.close();
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la fermeture d'un flux");
            System.err.println(e);
        } finally {
            if (_socket != null) {
                try {
                    _socket.close();
                } catch (IOException e) {
                    LOGGER.severe(
                            "Client [" + _noClient + "] Une erreur est survenue lors de la fermeture de la socket");
                    System.err.println(e);
                }
            }
            this.interrupt();
        }
    }
}
