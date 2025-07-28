#include "clientHandler.hpp"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>

// ----------------------------- Constructor --------------------------------->

ClientHandler::ClientHandler(int clientSocket) : clientSocket(clientSocket) {}

// ----------------------------- Handle request ------------------------------->

void ClientHandler::handleRequest()
{
    std::string request = parseRequest();
    std::cout << "Request received:\n"
              << request << std::endl;

    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/html\r\n";
    response += "Connection: close\r\n\r\n";
    response += "<html><body><h1>Hello from C++ Web Server!</h1></body></html>";

    sendResponse(response);
}

std::string ClientHandler::parseRequest()
{
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int bytesRead = read(clientSocket, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0)
    {
        std::cerr << "Error reading request!" << std::endl;
        return "";
    }

    return std::string(buffer);
}

// ---------------------------- Handle response ------------------------------>

void ClientHandler::sendResponse(const std::string &response)
{
    send(clientSocket, response.c_str(), response.length(), 0);
}

// ---------------------------- Stop listening ------------------------------>

ClientHandler::~ClientHandler()
{
    close(clientSocket);
}