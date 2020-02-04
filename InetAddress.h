#ifndef INETADDRESS_H_INCLUDED
#define INETADDRESS_H_INCLUDED

#include <string>
#include <winsock2.h>
#include <iostream>

class InetAddress
{
public:
        //Retorna o endere�o IP (objeto InetAddress) de um host, dando o nome do host.
        static InetAddress *getByName(std::string host);
    	//Retorna o endere�o IP (objeto InetAddress), dando o endere�o IP bruto.
        static InetAddress *getByAddress(std::string addr);
    	//Retorna o endere�o IP (objeto InetAddress) do host local.
        static InetAddress *getLocalHost();

    	//Fornece o nome do host
    	std::string getHostName();
    	//Fornece o endere�o IP do host
    	std::string getHostAddress();

    	~InetAddress(){}//destrutor

private:
    InetAddress(){}
    std::string hostName;
    std::string hostAddr;
    sockaddr_in ip_address;

    friend class Server;
    friend class Client;
};

#endif // INETADDRESS_H_INCLUDED
