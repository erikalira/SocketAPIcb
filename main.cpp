#include <iostream>
#include <thread>         // std::thread
#include "Server.h"
#define EXIT_CALL_STRING "#quit"

using namespace std;

//servidor: bind >> listen >> accept >> recv
//cliente: connect > send

void serverThread()
{
    char message[128];

    Server socket;

    socket.Bind(8000);

    //listen and accept
    socket.Accept();

    do
    {
        // limpa o buffer
        memset(&message, 0, 128);

        socket.Recv(message, 128);

        // exibe a mensagem na tela
        printf("cliente: %s\n", message);
    }while(strcmp(message, EXIT_CALL_STRING)); // sai quando receber um "#quit" do cliente

    socket.close();
}

int main (){
    std::thread first (serverThread);

    Client cliente("127.0.0.1", 8000);

    char message[128];
    printf("digite as mensagens\n");

    do{
        // limpa o buffer
        memset(&message, 0, 128);

        printf("msg: ");
        gets(message);
        fflush(stdin);

        int message_length = strlen(message);

        cliente.Send(message, message_length);

    }while(strcmp(message, "#quit")); // sai quando enviar um "#quit" para o servidor

    first.join();

    cliente.close();

    return 0;
}
