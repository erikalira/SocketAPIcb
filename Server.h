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
        //Cria um server socket, amarrado na porta espec�fica.
        Server(int port);

        //Amarra o Server ao endere�o do host local e � porta espec�fica.
        void Bind(int port);

        /*Escuta a porta por conex�es a serem feitas neste socket e as aceita,
        retornando um objeto socket que representa o socket remoto conectado.
        O metodo � bloqueante enquanto a conexao � estabelecida.*/
        Client* Accept();

        int Recv(char *message, int tam);

        //Fecha este socket.
        void close();

        //Retorna o n�mero da porta que este socket est� escutando.
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
