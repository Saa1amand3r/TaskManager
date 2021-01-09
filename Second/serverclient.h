#ifndef SERVERCLIENT_H
#define SERVERCLIENT_H
#include<winsock2.h>
#include<ws2tcpip.h>
#include <iostream>

class ServerClient
{
public:
    ServerClient();
    void StartServer();
};

#endif // SERVERCLIENT_H
