#include "Server.hpp"

Server::Server(int port) : port(port) {
    setup_routes();
}

void Server::setup_routes() {
    server.Post("/createVM", [&](const httplib::Request& req, httplib::Response& res) {
        handle_create_vm(req, res);
    });

    server.Delete("/deleteVM", [&](const httplib::Request& req, httplib::Response& res) {
        handle_delete_vm(req, res);
    });

    server.Post("/startVM", [&](const httplib::Request& req, httplib::Response& res) {
        handle_start_vm(req, res);
    });

    server.Post("/shutdownVM", [&](const httplib::Request& req, httplib::Response& res) {
        handle_shutdown_vm(req, res);
    });
}

void Server::handle_create_vm(const httplib::Request& req, httplib::Response& res) {
    std::string vm_name = req.get_param_value("name");
    if (vm_name.empty()) {
        res.status = 400;
        res.set_content("{\"error\": \"Missing VM name\"}", "application/json");
        return;
    }

    std::string response = "{\"message\": \"VM " + vm_name + " created successfully\"}";
    res.set_content(response, "application/json");
}

void Server::handle_delete_vm(const httplib::Request& req, httplib::Response& res) {
    std::string vm_name = req.get_param_value("name");
    if (vm_name.empty()) {
        res.status = 400;
        res.set_content("{\"error\": \"Missing VM name\"}", "application/json");
        return;
    }

    std::string response = "{\"message\": \"VM " + vm_name + " deleted successfully\"}";
    res.set_content(response, "application/json");
}

void Server::handle_start_vm(const httplib::Request& req, httplib::Response& res) {
    std::string vm_name = req.get_param_value("name");
    if (vm_name.empty()) {
        res.status = 400;
        res.set_content("{\"error\": \"Missing VM name\"}", "application/json");
        return;
    }

    std::string response = "{\"message\": \"VM " + vm_name + " started successfully\"}";
    res.set_content(response, "application/json");
}

void Server::handle_shutdown_vm(const httplib::Request& req, httplib::Response& res) {
    std::string vm_name = req.get_param_value("name");
    if (vm_name.empty()) {
        res.status = 400;
        res.set_content("{\"error\": \"Missing VM name\"}", "application/json");
        return;
    }

    std::string response = "{\"message\": \"VM " + vm_name + " shutdown successfully\"}";
    res.set_content(response, "application/json");
}

void Server::start() {
    std::cout << "Server started on port " << port << std::endl;
    server.listen("0.0.0.0", port);
}
