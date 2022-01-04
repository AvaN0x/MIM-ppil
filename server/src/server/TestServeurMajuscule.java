package server;

import java.net.ServerSocket;
import java.net.Socket;

/**
 * Hello world!
 *
 */
public class TestServeurMajuscule {
    public static void main(String[] args) {
        System.out.println("----- SERVEUR -----");
        try {
            int portServeur = 9111;
            ServerSocket serveur = new ServerSocket(portServeur);

            System.out.println("Serveur de majuscule prêt : " + serveur);

            int noClient = 0;
            while (true) {
                Socket socket = serveur.accept();
                System.out.println("Connexion n°" + noClient + " réussie");
                noClient++;
                new Interlocuteur(socket, noClient).start();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
