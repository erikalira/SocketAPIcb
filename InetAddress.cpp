#include "InetAddress.h"

//Retorna o endereço IP (objeto InetAddress) de um host, dando o nome do host.
InetAddress* InetAddress::getByName(std::string host){
    InetAddress *temp = new InetAddress[5];

    return temp;
}

//Retorna o endereço IP (objeto InetAddress), dando o endereço IP bruto.
InetAddress* InetAddress::getByAddress(std::string addr){
    InetAddress *temp = new InetAddress();

    // preenchendo o ip_address
    memset(&temp->ip_address, 0, sizeof(temp->ip_address));

    temp->ip_address.sin_family = AF_INET;
    temp->ip_address.sin_addr.s_addr = inet_addr(addr.c_str());

    return temp;
}

//Retorna o endereço IP (objeto InetAddress) do host local.
InetAddress* InetAddress::getLocalHost(){
    InetAddress *temp = new InetAddress[5];

    return temp;
}

//Fornece o nome do host
std::string InetAddress::getHostName(){
    return "temp";
}

//Fornece o endereço IP do host
std::string InetAddress::getHostAddress(){
    return "temp";
}
