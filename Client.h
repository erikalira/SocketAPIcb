#ifndef CLIENT_H
#define CLIENT_H
#include <winsock2.h>

class Client
{
    public:
        Client();
        ~Client();

    protected:

    private:
        friend class Server;
        unsigned local_socket = INVALID_SOCKET;
};

#endif // CLIENT_H
