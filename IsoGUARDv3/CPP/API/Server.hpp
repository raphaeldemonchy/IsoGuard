#ifndef SERVER_HPP
#define SERVER_HPP

#include "httplib.h"
#include "../CORE/core.hpp"
#include <iostream>
#include <string>

class Server {
public:
    Server(int port);
    void start();

private:
    httplib::Server server;
    int port;
    Core core;

    void setup_routes();
    void handle_create_vm(const httplib::Request& req, httplib::Response& res);
    void handle_delete_vm(const httplib::Request& req, httplib::Response& res);
    void handle_start_vm(const httplib::Request& req, httplib::Response& res);
    void handle_shutdown_vm(const httplib::Request& req, httplib::Response& res);
};

#endif // SERVER_HPP
