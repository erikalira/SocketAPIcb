#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include "Client.h"
#include "InetAddress.h"

//class InetAddress;

class Server
{
    public:
        //Cria um server socket desamarrado de qualquer porta.
        Server();
        //Cria um server socket, amarrado na porta específica.
        Server(int port);

        //Amarra o Server ao endereço do host local e à porta específica.
        void Bind(int port);

        /*Escuta a porta por conexões a serem feitas neste socket e as aceita,
        retornando um objeto socket que representa o socket remoto conectado.
        O metodo é bloqueante enquanto a conexao é estabelecida.*/
        Client* Accept();

        int Recv(char *message, int tam);

        //Fecha este socket.
        void close();

        //Retorna o número da porta que este socket está escutando.
        int getLocalPort();

        ~Server();//destrutor

    private:
        long long unsigned int local_socket; //used
        long long unsigned int remote_socket;
        unsigned short local_port; //used
        InetAddress *local_address;
        InetAddress *remote_address;
};

#endif // SERVER_H_INCLUDED
