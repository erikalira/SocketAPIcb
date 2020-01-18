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
        //Cria um server socket, amarrado na porta específica.
        Server(int port);

        //Amarra o Server ao endereço do host local e à porta específica.
        void Bind(int port);

        //Escuta a porta por conexões a serem feitas neste socket e as aceita, retornando um objeto socket que representa o socket remoto conectado.
        //O metodo é bloqueante enquanto a conexao é estabelecida.
        //Socket* Accept();

        //Fecha este socket.
        void close();

        //Retorna o número da porta que este socket está escutando.
        //int getLocalPort();

        ~Server();//destrutor

    private:
        int local_socket = INVALID_SOCKET;
        unsigned short local_port;
        sockaddr_in local_address;
        sockaddr_in remote_address;

};

#endif // SOCKET_H
