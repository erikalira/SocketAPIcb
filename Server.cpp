#include "Server.h"

#define BACKLOG_MAX 5

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

    std::cout << "SERVER INICIALIZADO COM SUCESSO!!\n" << std::endl;
}

void Server::Bind(int porta){
    local_port = porta;

    // zera a estrutura local_address
    memset(&local_address, 0, sizeof(local_address));

    // internet address family
    local_address.sin_family = AF_INET;

    // porta local
    local_address.sin_port = htons(local_port);

    // endereco
    local_address.sin_addr.s_addr = htonl(INADDR_ANY); // inet_addr("127.0.0.1")

    // interligando o socket com o endereço (local)
    if (bind(local_socket, (struct sockaddr *) &local_address, sizeof(local_address)) == SOCKET_ERROR)
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "Erro no bind()\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    std::cout << "BIND FEITO COM SUCESSO" << std::endl;
}

Client* Server::Accept(){
    Client *cliente = new Client();

    // coloca o socket para escutar as conexoes
    if ( listen(local_socket, 5) == SOCKET_ERROR )
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "listen() falhou!!!\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    int remote_length = sizeof(remote_address);

    std::cout << "aguardando alguma conexao...\n" << std::endl;

    //aceita a conexao
    cliente->local_socket = accept(local_socket, (struct sockaddr *) &remote_address, &remote_length);
    if(cliente->local_socket == INVALID_SOCKET)
    {
        WSACleanup();
        closesocket(local_socket);
        std::cout << "accept() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    std::cout << "conexao estabelecida com %s\n" << inet_ntoa(remote_address.sin_addr) << std::endl;
    std::cout << "aguardando mensagens...\n" << std::endl;

    return cliente;
}


void Server::close(){
    closesocket(local_socket);

    local_socket = INVALID_SOCKET;

    WSACleanup();
}

int Server::getLocalPort(){
    return 0;
}

Server::~Server()
{
    //dtor
}
