#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <netinet/in.h>

class Socket
{
public:
    Socket(int port = 8080);
    void listenSocket();
    void closeSocket();

    int getServerSocket();

    ~Socket();

private:
    int serverSocket;
    struct sockaddr_in serverAddress;
    int port;
};

#endif
