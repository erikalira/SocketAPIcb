#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <stdlib.h>
#include <winsock2.h>

class Server
{
    public:
        //Cria um server socket desamarrado de qualquer porta.
        Server();
        //Cria um server socket, amarrado na porta espec�fica.
        Server(int port);

        //Amarra o Server ao endere�o do host local e � porta espec�fica.
        void Bind(int port);

        //Escuta a porta por conex�es a serem feitas neste socket e as aceita, retornando um objeto socket que representa o socket remoto conectado.
        //O metodo � bloqueante enquanto a conexao � estabelecida.
        //Socket* Accept();

        //Fecha este socket.
        void close();

        //Retorna o n�mero da porta que este socket est� escutando.
        //int getLocalPort();

        ~Server();//destrutor

    private:
        int local_socket = INVALID_SOCKET;
        unsigned short local_port;
        sockaddr_in local_address;
        sockaddr_in remote_address;

};

#endif // SOCKET_H
