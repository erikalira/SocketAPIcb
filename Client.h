#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <winsock2.h>
#include "InetAddress.h"

//class InetAddress;

class Client
{
    public:
        //Cria um objeto socket não conectado.
        Client();
        //Cria um socket e o conecta a um número de porta e em um endereço IP específicos.
        Client(std::string addr, int port);
        //Cria um socket e o conecta para um número de porta e nome de host específico.
        //Client(std::string hostName, int port);
        //Fecha este socket.
        void close();

        //Envia a string no array msg para o socket remoto.
        //void operator<<(const char* msg) throw (IOException);
        //Envia os bytes armazenados no array msg, no intervalo [0 size], para o socket remoto.
        int Send(const char* message, int size);
        //Ler a string do socket remoto e armazena no array msg.
        //void operator>>(const char* msg) throw (IOException);
        //Ler size bytes do socket remoto e armazena no array msg.
        //int recv(const char *message, int size);

        ~Client();

    protected:

    private:
        long long unsigned int remote_socket;
        int local_port;
        int remote_port;
        std::string local_ip;
        std::string remote_ip;
        InetAddress* remote_address;
        friend class Server;
};

#endif // CLIENT_H
