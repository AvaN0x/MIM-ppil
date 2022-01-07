package org.avanox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.net.SocketException;
import java.util.logging.Logger;

import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class Interlocuteur extends Thread {
    private BufferedReader _fluxEntrant = null;
    private PrintStream _fluxSortant = null;
    private Socket _socket = null;

    private static final Logger LOGGER = Logger.getLogger("Serveur");
    private static Scene _scene;

    private int _noClient;

    public Interlocuteur(Socket socket, int noClient) {
        try {
            this._fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            this._fluxSortant = new PrintStream(socket.getOutputStream());
            this._noClient = noClient;
            this._socket = socket;
            _scene = new Scene(loadFXML("window"), 900, 514);
            System.out.println("Interlocuteur created");
        } catch (IOException e) {
            LOGGER.severe("Client [" + _noClient + "] Une erreur est survenue lors de la creation de l'interlocuteur.");
            System.err.println(e);
            closeStreamAndSocket();
        }
    }

    @Override
    public void run() {
        Platform.runLater(() -> {
            System.out.println("Hello i'm in runLater client");
            Stage stage = new Stage();
            stage.setTitle("Client " + _noClient);
            setIcon(stage);
            stage.setScene(_scene);

            stage.setOnCloseRequest(value -> {
                stage.close();
                closeStreamAndSocket();
            });

            stage.show();
        });
        execution();
    }

    private void execution() {
        try {
            while (!this.isInterrupted()) {
                String requete = _fluxEntrant.readLine();
                if (requete == null)
                    throw new SocketException();

                LOGGER.info("Client [" + _noClient + "] A envoye : " + requete);
                _fluxSortant.println(requete.toUpperCase());
            }
        } catch (SocketException e) {
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
            if (this.isAlive())
                this.interrupt();
        }
    }

    private void setIcon(Stage stage) {
        stage.getIcons().add(new Image(Server.class.getResourceAsStream("img/title-ico.png")));
    }

    private void setRoot(String fxml) throws IOException {
        _scene.setRoot(loadFXML(fxml));
    }

    private Parent loadFXML(String fxml) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(Server.class.getResource(fxml + ".fxml"));
        return fxmlLoader.load();
    }
}
