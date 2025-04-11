#ifndef SERVER_HPP
#define SERVER_HPP

#include "httplib.h"
#include "manager/VMManager.hpp"
#include <string>
#include <string_view>
#include <mutex>

class Server {
public:
    static Server& getInstance(int port);
    void start();

private:
    httplib::Server server_;
    int port_;
    VMManager vmManager_;
    std::mutex mutex_;

    explicit Server(int port);
    void setupRoutes();

    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    void handleAddVM(const httplib::Request& req, httplib::Response& res);
    void handleEraseVM(const httplib::Request& req, httplib::Response& res);
    void handleStartVM(const httplib::Request& req, httplib::Response& res);
    void handleStopVM(const httplib::Request& req, httplib::Response& res);

    bool isValidVMName(std::string_view name) const;
    void sendJsonResponse(httplib::Response& res, int status, const std::string& message);
};

#endif // SERVER_HPP
