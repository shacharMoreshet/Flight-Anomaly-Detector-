/*
 * Server.h
 *
 *  Created on: Dec 13, 2020
 *      Author: Eli
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include "CLI.h"
#include <stdexcept>
#include "commands.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <thread>

using namespace std;

class ClientHandler { // interface
public:
    virtual void handle(int clientID) = 0;
};


class SocketIO : public DefaultIO {
    int clientId;
public:
    SocketIO(int clientID) {
        this->clientId = clientID;
    }

    void write(string str) override {
        const char *c = str.c_str(); // a pointer to an array that contains the string
        send(this->clientId, c, strlen(c), 0);
    }

    void write(float number) override {
        /**
        string s = to_string(number);
        s.erase(s.find_last_not_of('0') + 1, std::string::npos); //delete '0' at the end
        const char* c = s.c_str();
        send(this->clientId, c, strlen(c), 0);
        **/
        stringstream stringStream1;
        stringStream1 << number; // conversion of float to stringStream
        string input = stringStream1.str(); // conversion to string
        const char *text = input.c_str(); // pointer to the given string text
        send(this->clientId, text, input.size(), 0);

    }

    string read() override {
        char buffer = 0; // buffer to the receiving information
        string input = ""; // the line we read and return
        recv(this->clientId, &buffer, sizeof(char), 0);
        while (buffer != '\n') { // continue reading until the end of line
            input += buffer; // putting the chars in the return input
            recv(this->clientId, &buffer, sizeof(char), 0);
        }
        return input;
    }

    void read(float *f) override{
       ::read(this->clientId, f, sizeof(float));
    }
};


class AnomalyDetectionHandler : public ClientHandler {
public:
    virtual void handle(int clientID) {
        SocketIO socketIo(clientID); // creating socketIo for the client
        CLI cli (&socketIo);
        cli.start();
    }
};


// implement on Server.cpp
class Server {
    thread *t;
    int serverFd; // socket file descriptor
    sockaddr_in server;
    sockaddr_in client;
    bool shouldCloseConnection = false;

public:
    Server(int port) throw(const char *);

    virtual ~Server();

    void start(ClientHandler &ch) throw(const char *);

    void stop();
};

#endif /* SERVER_H_ */
