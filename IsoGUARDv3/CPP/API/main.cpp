#include "Server.hpp"
#include <thread>

int main() {
    int port = 8080;

    // Démarrer le serveur
    Server server(port);
    server.start();

    return 0;
}
