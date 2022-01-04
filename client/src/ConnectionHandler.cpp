#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include "ConnectionHandler.h"

using namespace std;

ConnectionHandler::ConnectionHandler(const string &address, int port)
{
    _closed = false;

    WSADATA wsaData;

    int r = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (r)
        throw runtime_error(string("WSAStartup failed: " + r));

    // Socket
    int familleAdresses = AF_INET; // IPv4
    int typeSocket = SOCK_STREAM;  // mode connecté TCP
    int protocole = IPPROTO_TCP;   // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
                                   // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

    _socket = socket(familleAdresses, typeSocket, protocole);

    if (_socket == INVALID_SOCKET)
    {
        ostringstream oss;
        // pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
        oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;
        throw runtime_error(oss.str());
    }

    SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(address.c_str()); // inet_addr() convertit de l'ASCII en entier
    sockaddr.sin_port = htons(port);                       // htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

    if (connect(_socket, (SOCKADDR *)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
        throw runtime_error(string("La connexion a échoué (code " + to_string(WSAGetLastError()) + ')'));
}

void ConnectionHandler::close()
{
    if (_closed)
        return;

    int r = shutdown(_socket, SD_BOTH); // on coupe la connexion pour l'envoi et la réception
    if (r == SOCKET_ERROR)
        throw runtime_error("La coupure de connexion a échoué");

    r = closesocket(_socket); // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
    if (r)
        throw runtime_error("La fermeture du socket a échoué");

    WSACleanup();
    _closed = true;
}

int ConnectionHandler::sendLine(const string &line)
{
    int r = send(_socket, line.c_str(), line.length(), 0);
    if (r == SOCKET_ERROR)
        throw runtime_error("échec de l'envoi de la requête");
    return r;
}

string ConnectionHandler::receive()
{
    char buffer[1024];
    int r = recv(_socket, buffer, 1024, 0);
    if (r == SOCKET_ERROR)
        throw runtime_error("échec de la réception de la réponse");

    char *p = strchr(buffer, '\n');
    *p = '\0';

    return string(buffer);
}