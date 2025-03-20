#ifndef SERVER_HPP
#define SERVER_HPP

#include "httplib.h"
#include <iostream>

class Server {
public:
    Server(int port);
    void start();
    
private:
    httplib::Server server;
    int port;
    
    void setup_routes();
};

#endif // SERVER_HPP
