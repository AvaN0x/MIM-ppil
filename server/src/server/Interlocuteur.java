package server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class Interlocuteur extends Thread {
    private BufferedReader fluxEntrant;
    private PrintStream fluxSortant;

    int noClient;

    public Interlocuteur(Socket socket, int noClient) throws IOException {
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.noClient = noClient;

    }

    @Override
    public void run() {
        try {
            while (!this.isInterrupted()) {
                String requete = fluxEntrant.readLine();
                System.out.println("[" + noClient + "] A envoyé : " + requete);

                fluxSortant.println(requete.toUpperCase());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
