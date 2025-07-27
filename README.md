# Web Server in C++

This project demonstrates how to build a simple **web server** using C++ from scratch. The web server is capable of accepting HTTP requests from clients and sending back HTTP responses. The server uses **sockets** to establish a communication channel between the client and the server. This project is designed to help understand the basic concepts of networking, socket programming, and HTTP communication.

## Table of Contents

1. [Overview](#overview)
2. [Architecture](#architecture)
3. [How Sockets Work](#how-sockets-work)
4. [File Structure](#file-structure)
5. [Requirements](#requirements)
6. [Getting Started](#getting-started)
7. [How to Run](#how-to-run)

---

## Overview

This project implements a **basic web server** that can handle HTTP `GET` requests. The server listens for incoming connections on a specified port and responds with a simple HTML page. It is built using basic **socket programming** in C++ and demonstrates the fundamental steps required to set up a web server from scratch.

Key Features:

- **Socket Communication**: The server uses **TCP sockets** for communication.
- **HTTP Request Handling**: The server reads HTTP requests, processes them, and sends back HTTP responses.
- **Modular Structure**: The project is divided into multiple files and modules for better organization.

---

## Architecture

The web server is built with a modular architecture, consisting of the following components:

- **Socket Layer**: Responsible for creating a socket, binding it to an address and port, and listening for incoming connections.
- **Request Handler**: Responsible for reading the client's HTTP request and sending an appropriate HTTP response.
- **Main Server Loop**: The entry point of the program. It initializes the server, waits for client connections, and delegates request handling to the request handler.

### Components:

1. **Socket**: The `Socket` class encapsulates the functionality for creating a socket, binding to a port, and listening for client connections.
2. **Client Handler**: The `ClientHandler` class is responsible for processing requests from clients. It reads the request and sends back an HTTP response.
3. **Main**: The `main.cpp` file is the entry point of the program, responsible for setting up the server and accepting client connections.

---

## How Sockets Work

### What is a Socket?

A **socket** is an endpoint for sending or receiving data across a computer network. It acts as a communication channel between two applications, either running on the same machine or on different machines connected over a network. Sockets provide a way for programs to send and receive data over the network.

Sockets are essential for establishing communication between clients and servers in client-server architecture.

### How does Socket Programming work in C++?

1. **Creating a Socket**: A socket is created using the `socket()` system call. In this project, the socket is created with `AF_INET` (IPv4) and `SOCK_STREAM` (TCP).
2. **Binding the Socket**: The server binds the socket to a specific port and address using the `bind()` system call. This is how the server listens for incoming requests on that address and port.
3. **Listening for Connections**: The server uses the `listen()` function to wait for incoming client connections.
4. **Accepting Connections**: The server uses `accept()` to establish a connection with the client. Once a connection is established, the server can read data from the client and send data back to the client.

---

## File Structure

Here is the directory structure of the project:

---

## Requirements

To compile and run the project, you need:

- **C++ compiler** (e.g., `g++` or `clang++`).
- A **Unix-like system** (Linux or MacOS) for socket functionality. For Windows, consider using **WSL (Windows Subsystem for Linux)** or adapt the code to use Winsock API.

---

## Getting Started

To get started with the project, follow these steps:

1. **Clone the repository**:

   ```bash
   git clone https://github.com/TheTangentLine/web_server.git
   cd web_server
   ```

2. **Compile the project**:

   ```bash
    g++ -o web_server main.cpp requestHandler/clientHandler.cpp socket/socket.cpp -std=c++17

   ```

---

## How to run

**Run the server**

```
./web_server
```

Once the server is running, you can test it by opening a web browser and navigating to http://localhost:8000
