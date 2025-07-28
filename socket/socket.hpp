#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <netinet/in.h>

class Socket
{
public:
    Socket(int port = 8080);
    ~Socket();

    int getServerSocket();

    void listenSocket();
    void closeSocket();

private:
    int serverSocket;
    sockaddr_in serverAddress;
    int port;
};

#endif
