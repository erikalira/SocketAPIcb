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
        //Cria um server socket, amarrado na porta espec�fica.
        ServerSocket(int port);

        //Amarra o ServerSocket ao endere�o do host local e � porta espec�fica.
        //void Bind(int port);
        //Escuta a porta por conex�es a serem feitas neste socket e as aceita, retornando um objeto socket que representa o socket remoto conectado.
        //O metodo � bloqueante enquanto a conexao � estabelecida.
        //Socket* Accept();

        //Fecha este socket.
        void close();

        //Retorna o n�mero da porta que este socket est� escutando.
        //int getLocalPort();

        ~ServerSocket();//destrutor

    private:
        int descritor = INVALID_SOCKET;
        unsigned short local_port;
        sockaddr_in local_address;
        sockaddr_in remote_address;

};

#endif // SOCKET_H
