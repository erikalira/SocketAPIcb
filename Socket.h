#ifndef SOCKET_H
#define SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

class ServerSocket
{
    public:
        //Cria um server socket desamarrado de qualquer porta.
        ServerSocket();
        //Cria um server socket, amarrado na porta específica.
        ServerSocket(int port);

        //Amarra o ServerSocket ao endereço do host local e à porta específica.
        //void Bind(int port);
        //Escuta a porta por conexões a serem feitas neste socket e as aceita, retornando um objeto socket que representa o socket remoto conectado.
        //O metodo é bloqueante enquanto a conexao é estabelecida.
        //Socket* Accept();

        //Fecha este socket.
        void close();

        //Retorna o número da porta que este socket está escutando.
        //int getLocalPort();

        ~ServerSocket();//destrutor

    private:
        int descritor = INVALID_SOCKET;
        unsigned short local_port;
        sockaddr_in local_address;
        sockaddr_in remote_address;

};

#endif // SOCKET_H
