#include "Server.hpp"

Server::Server(int port) : port(port) {
    setup_routes();
}

void Server::setup_routes() {
    server.Get("/", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"message\": \"Bienvenue sur le serveur!\"}", "application/json");
    });

    server.Post("/data", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("{\"received\": \"" + req.body + "\"}", "application/json");
    });
}

void Server::start() {
    std::cout << "Serveur démarré sur le port " << port << std::endl;
    server.listen("0.0.0.0", port);
}
