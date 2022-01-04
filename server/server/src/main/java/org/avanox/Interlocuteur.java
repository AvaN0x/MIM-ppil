package org.avanox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.SocketException;
import java.util.logging.Logger;

import org.avanox.exceptions.InterlocuteurException;

public class Interlocuteur extends Thread {
    private BufferedReader _fluxEntrant = null;
    private PrintStream _fluxSortant = null;
    private static final Logger LOGGER = Logger.getLogger("Serveur");

    int _noClient;

    public Interlocuteur(Socket socket, int _noClient) throws InterlocuteurException {
        try {
            this._fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            this._fluxSortant = new PrintStream(socket.getOutputStream());
            this._noClient = _noClient;
        } catch (IOException e) {
            try {
                if (_fluxEntrant != null)
                    _fluxEntrant.close();
                if (_fluxSortant != null)
                    _fluxSortant.close();
            } catch (IOException e1) {
                LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la fermeture d'un flux");
                System.err.println(e1);
            }
            throw new InterlocuteurException(e.getMessage(), e.getCause(), 12);
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
            try {
                if (_fluxEntrant != null)
                    _fluxEntrant.close();
                if (_fluxSortant != null)
                    _fluxSortant.close();
            } catch (IOException e1) {
                LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la fermeture d'un flux");
                System.err.println(e1);
            } finally {
                this.interrupt();
            }
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la lecture de la requete");
            System.err.println(e);
        }
    }

}
