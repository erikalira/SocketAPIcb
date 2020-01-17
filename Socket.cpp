#include "Socket.h"

ServerSocket::ServerSocket()
{
    WSADATA wsa_data;

    WSAStartup(MAKEWORD(2, 0), &wsa_data);

    descritor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void ServerSocket::close(){
    closesocket(descritor);

    descritor = INVALID_SOCKET;

    WSACleanup();
}

ServerSocket::~ServerSocket()
{
    //dtor
}
