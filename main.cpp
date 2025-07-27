#include <iostream>
#include "socket/socket.hpp"
#include "requestHandler/clientHandler.hpp"

#define PORT 8080

int main()
{
    Socket server(PORT);
    server.listenSocket();

    std::cout << "Server is listening on port " << PORT << "..." << std::endl;

    while (true)
    {
        int clientSocket = accept(server.getServerSocket(), nullptr, nullptr);
        if (clientSocket == -1)
        {
            std::cerr << "Failed to accept client connection!" << std::endl;
            continue;
        }

        ClientHandler clientHandler(clientSocket);
        clientHandler.handleRequest();
    }

    return 0;
}
