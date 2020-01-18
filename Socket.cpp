#include "Socket.h"

Server::Server()
{
    WSADATA wsa_data;

    WSAStartup(MAKEWORD(2, 0), &wsa_data);

    local_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void Server::Bind(int porta){
    // zera a estrutura local_address
    memset(&local_address, 0, sizeof(local_address));

    // internet address family
    local_address.sin_family = AF_INET;

    // porta local
    local_address.sin_port = htons(porta);

    // endereco
    local_address.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr("127.0.0.1")

    // interligando o socket com o endereço (local)
    if (bind(local_socket, (struct sockaddr *) &local_address, sizeof(local_address)) == SOCKET_ERROR)
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "Erro no bind()\n" << std::endl;
    }
}

void Server::close(){
    closesocket(local_socket);

    local_socket = INVALID_SOCKET;

    WSACleanup();
}

Server::~Server()
{
    //dtor
}
