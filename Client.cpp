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

    remote_ip = addr;
    remote_port = port;

    remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (remote_socket == INVALID_SOCKET)
    {
        WSACleanup();
        std::cout << "socket() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    // preenchendo o remote_address (servidor)
    memset(&remote_address, 0, sizeof(remote_address));
    remote_address.sin_family = AF_INET;
    remote_address.sin_addr.s_addr = inet_addr(remote_ip.c_str());
    remote_address.sin_port = htons(remote_port);

    std::cout << "client: conectando ao servidor " << remote_ip << std::endl;
    if (connect(remote_socket, (struct sockaddr *) &remote_address, sizeof(remote_address)) == SOCKET_ERROR)
    {
        WSACleanup();
        std::cout << "connect() failed\n" << std::endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }
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
