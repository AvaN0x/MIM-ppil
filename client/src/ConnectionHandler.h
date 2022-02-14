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
    ConnectionHandler(const string &address, int port);
    virtual ~ConnectionHandler()
    {
        close();
    }

    void close();

    bool isClosed() const
    {
        return _closed;
    }

    int sendLine(const string &content);
    string receive();
};
