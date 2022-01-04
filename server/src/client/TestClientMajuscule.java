package client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.Socket;

/**
 * Hello world!
 *
 */
public class TestClientMajuscule {
    public static void main(String[] args) {
        System.out.println("----- Client -----");
        try {
            BufferedReader clavier = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Tapez l'adresse du serveur : ");

            String sAdresse = clavier.readLine().trim();

            System.out.println("Tapez le n° de port du serveur : ");

            int portServeur = Integer.parseInt(clavier.readLine().trim());

            InetAddress adresseServeur = InetAddress.getByName(sAdresse);

            Socket socket = new Socket(adresseServeur, portServeur);
            System.out.println("Socket créé : " + socket);

            BufferedReader fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream fluxSortant = new PrintStream(socket.getOutputStream());

            boolean continuer = true;
            do {
                System.out.println("Tapez une chaine de caractères ou \"quitter\" pour terminer : ");
                String requete = clavier.readLine().trim();
                if (requete.equalsIgnoreCase("quitter")) {
                    continuer = false;
                } else {
                    fluxSortant.println(requete);
                    String reponse = fluxEntrant.readLine();
                    System.out.println("Réponse serveur : " + reponse);
                }
            } while (continuer);

            System.out.println("Arret de l'application à votre initiative.");
        } catch (NumberFormatException | IOException e) {
            e.printStackTrace();
        }
    }
}
