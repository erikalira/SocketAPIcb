#include "Server.h"

Server::Server()
{
    WSADATA wsa_data;

    // inicia o Winsock 2.0 (DLL), Only for Windows
    if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0)
        std::cout << "WSAStartup() failed\n" << std::endl;

    // criando o socket local para o servidor
    local_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (local_socket == INVALID_SOCKET)
    {
        WSACleanup();
        std::cout << "socket() failed\n" << std::endl;
    }

    //std::cout << "server: SERVER INICIALIZADO COM SUCESSO!!" << std::endl;
}

void Server::Bind(int porta){
    local_address = InetAddress::getByAddress("127.0.0.1");

    // porta local
    local_address->ip_address.sin_port = htons(porta);

    // interligando o socket com o endereço (local)
    if (bind(local_socket, (struct sockaddr *) &(local_address->ip_address), sizeof(local_address->ip_address)) == SOCKET_ERROR)
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "Erro no bind()\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    std::cout << "server: BIND FEITO COM SUCESSO" << std::endl;
}

Client* Server::Accept(){
    Client *cliente = new Client();

    // coloca o socket para escutar as conexoes
    if (listen(local_socket, 5) == SOCKET_ERROR)
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "listen() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    int remote_length = sizeof(cliente->remote_address->ip_address);

    std::cout << "server: AGUARDANDO CONEXAO" << std::endl;
    //aceita a conexao (bloqueante)
    remote_socket = accept(local_socket, (struct sockaddr *) &(cliente->remote_address->ip_address), &remote_length);
    if(remote_socket == INVALID_SOCKET)
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "accept() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    printf("conexao estabelecida com %s\n", inet_ntoa(cliente->remote_address->ip_address.sin_addr));

    return cliente;
}

int Server::Recv(char *message, int size){
    int message_length = recv(remote_socket, message, size, 0);
    if(message_length == SOCKET_ERROR)
        std::cout << "recv() failed\n" << std::endl;

    return message_length;
}

void Server::close(){
    closesocket(local_socket);
    WSACleanup();
}

int Server::getLocalPort(){
    return local_port;
}

Server::~Server()
{
    //dtor
}


