#include "Client.h"

Client::Client()
{
    //ctor
}

Client::Client(std::string addr, int port){
    WSADATA wsa_data;

    if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0){
        std::cout << "WSAStartup() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (remote_socket == INVALID_SOCKET)
    {
        WSACleanup();
        std::cout << "socket() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    remote_address = InetAddress::getByAddress(addr);
    remote_address->ip_address.sin_port = htons(port);

    std::cout << "cliente: conectando ao servidor " << inet_ntoa(remote_address->ip_address.sin_addr) << std::endl;
    if (connect(remote_socket, (struct sockaddr *) &(remote_address->ip_address), sizeof(remote_address->ip_address)) == SOCKET_ERROR)
    {
        WSACleanup();
        std::cout << "connect() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    system("pause");
}

void Client::close(){
    WSACleanup();
    closesocket(remote_socket);
}

int Client::Send(const char* message, int size){
    if (send(remote_socket, message, size, 0) == SOCKET_ERROR)
    {
        WSACleanup();
        closesocket(remote_socket);
        std::cout << "send() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }
    return 0;
}

Client::~Client()
{
    //dtor
}
