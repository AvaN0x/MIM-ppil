#pragma once
#include <winsock2.h>
#include <string>

using namespace std;

class ConnectionHandler
{
private:
    bool _closed;

public:
    SOCKET _socket;
    /**
     * @brief ConnectionHandler constructor, this will automatically connect
     * @param socket The socket to use
     */
    ConnectionHandler(const string &address, int port);

    /**
     * @brief ConnectionHandler destructor, this will automatically close the socket
     */
    virtual ~ConnectionHandler()
    {
        close();
    }

    /**
     * @brief Close the socket
     */
    void close();

    /**
     * @brief Check if the socket has been closed
     *
     * @return bool True if the socket has been closed, false otherwise
     */
    bool isClosed() const { return _closed; }

    /**
     * @brief Send a string to the server
     * @param content The string to send
     */
    int sendLine(const string &content);

    /**
     * @brief Receive a string from the server
     * @return The string received
     */
    string receive();
};
