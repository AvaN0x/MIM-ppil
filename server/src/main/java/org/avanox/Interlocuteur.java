package org.avanox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.SocketException;
import java.util.logging.Logger;

import org.avanox.chainOfResponsability.shapes.*;
import org.avanox.visitor.Draw;
import org.avanox.chainOfResponsability.graphicLibrairy.*;

import java.lang.ThreadGroup;

public class Interlocuteur extends Thread {
    private BufferedReader _fluxEntrant = null;
    private PrintStream _fluxSortant = null;
    private Socket _socket = null;

    private static final Logger LOGGER = Logger.getLogger("Serveur");

    private int _noClient;

    public Interlocuteur(ThreadGroup group, Socket socket, int noClient) {
        super(group, "client" + noClient);
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
        ExpertShapes expertShapes = null;
        expertShapes = new ExpertCircle(expertShapes);
        expertShapes = new ExpertSegment(expertShapes);
        expertShapes = new ExpertTriangle(expertShapes);
        expertShapes = new ExpertAnyPolygon(expertShapes);

        ExpertGL expertGL = null;
        expertGL = new ExpertAWT(expertGL);
        expertGL = new ExpertFX(expertGL);
        expertGL = new ExpertSwing(expertGL);

        Draw graphicLibrairy = null;

        try {
            while (!this.isInterrupted()) {
                String requete = _fluxEntrant.readLine();
                if (requete == null)
                    throw new SocketException();

                LOGGER.info("Client [" + _noClient + "] A envoye : " + requete);

                if (graphicLibrairy == null) {
                    graphicLibrairy = expertGL.resolve(requete);
                } else {
                    expertShapes.resolve(requete, graphicLibrairy);
                }

                _fluxSortant.println(requete.toUpperCase());
            }
        } catch (SocketException e) {
            e.printStackTrace();
            // Connection interrupted
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la lecture de la requete");
            System.err.println(e);
        } finally {
            closeStreamAndSocket();
        }
    }

    private void closeStreamAndSocket() {
        try {
            LOGGER.info("Client [" + _noClient + "] La connexion a ete interrompue");
            LOGGER.info("Fermeture des flux du client [" + _noClient + "]...");
            if (_fluxEntrant != null)
                _fluxEntrant.close();
            if (_fluxSortant != null)
                _fluxSortant.close();
            LOGGER.info("Les flux du client [" + _noClient + "] ont ete fermes avec succes.");
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la fermeture d'un flux");
            System.err.println(e);
        } finally {
            if (_socket != null) {
                try {
                    LOGGER.info("Fermeture de la socket du client [" + _noClient + "]...");
                    _socket.close();
                    LOGGER.info("La socket du client [" + _noClient + "] a ete fermee avec succes.");
                } catch (IOException e) {
                    LOGGER.severe(
                            "Client [" + _noClient + "] Une erreur est survenue lors de la fermeture de la socket");
                    System.err.println(e);
                }
            }
            if (!this.isInterrupted())
                this.interrupt();
        }
    }
}
