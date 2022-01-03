#include "Server.h"

Server::Server(int port) throw(const char *) {
    //  Creating socket file descriptor
    this->serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->serverFd == 0) {
        throw "socket failed";
    }
    //  server struct
    this->server.sin_port = htons(port);
    this->server.sin_addr.s_addr = INADDR_ANY;
    this->server.sin_family = AF_INET;

    // attaching socket to the port
    if (bind(serverFd, (struct sockaddr *) &server, sizeof(server)) < 0){
        throw "bind failed";
    }

    if (listen(serverFd, 3) < 0){
        throw "listen failed";
    }
    // to check if we need to close the connection.
    this->shouldCloseConnection = false;
}


void Server::start(ClientHandler &ch) throw(const char *) {
    t = new thread([&ch, this](){ // lambda expression

            while(!this->shouldCloseConnection){
                socklen_t clientSocketSize = sizeof(client);
                alarm(5);
                int clientFd = accept(serverFd, (struct sockaddr *)&client, &clientSocketSize);
                if (clientFd < 0)
                {
                    throw "accept failed";
                }
                ch.handle(clientFd);
                close(clientFd);
            }
        close(this->serverFd);
    });
}


void Server::stop() {
    this->shouldCloseConnection = true;
    this->t->join();
}

Server::~Server() {
    delete this->t;
}

