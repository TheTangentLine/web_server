#ifndef CLIENT_HANDLER_HPP
#define CLIENT_HANDLER_HPP

#include <iostream>

class ClientHandler
{
public:
    ClientHandler(int clientSocket);
    void handleRequest();

    ~ClientHandler();

private:
    int clientSocket;
    void sendResponse(const std::string &response);
    std::string parseRequest();
};

#endif
