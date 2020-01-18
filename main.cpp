#include <iostream>
#include "Server.h"

using namespace std;

//servidor: bind >> listen >> accept >> recv

//cliente: connect > send

int main()
{
    Server socket;

    socket.Bind(8000);

    //listen and accept
    socket.Accept();

    socket.close();



    return 0;
}
