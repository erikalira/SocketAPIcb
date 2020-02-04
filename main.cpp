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

    Server *servidor = new Server();
    servidor->Bind(8080);
    //listen and accept
    servidor->Accept();

    do
    {
        // limpa o buffer
        memset(&message, 0, 128);
        servidor->Recv(message, 128);
        // exibe a mensagem na tela
        printf("cliente: %s\n", message);
    }while(strcmp(message, EXIT_CALL_STRING)); // sai quando receber um "#quit" do cliente

    servidor->close();
}

void clientThread(){
    Client *cliente = new Client("127.0.0.1", 8080);

    char message[128];
    printf("digite as mensagens\n");

    do{
        // limpa o buffer
        memset(&message, 0, 128);

        printf("msg: ");
        gets(message);
        fflush(stdin);

        int message_length = strlen(message);
        cliente->Send(message, message_length);

    }while(strcmp(message, "#quit")); // sai quando enviar um "#quit" para o servidor


    cliente->close();
}

int main (){
    std::thread server (serverThread);
    //serverThread();
    //clientThread();

    Client *cliente = new Client("127.0.0.1", 8080);

    char message[128];
    printf("digite as mensagens\n");

    do{
        // limpa o buffer
        memset(&message, 0, 128);

        printf("msg: ");
        gets(message);
        fflush(stdin);

        int message_length = strlen(message);
        cliente->Send(message, message_length);

    }while(strcmp(message, "#quit")); // sai quando enviar um "#quit" para o servidor

    server.join();

    cliente->close();

    return 0;
}
