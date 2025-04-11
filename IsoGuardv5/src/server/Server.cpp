#include "server/Server.hpp"
#include <regex>
#include <sstream>

Server::Server(int port) : port_(port) {
    setupRoutes();
}

Server& Server::getInstance(int port) {
    static Server instance(port);
    return instance;
}

void Server::start() {
    std::cout << "[INFO] Server started on port " << port_ << std::endl;
    server_.listen("0.0.0.0", port_);
}

void Server::setupRoutes() {
    server_.Post("/addVM", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(mutex_);
        handleAddVM(req, res);
        std::cout << "[INFO] Request to add VM received" << std::endl;
    });

    server_.Delete("/eraseVM", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(mutex_);
        handleEraseVM(req, res);
        std::cout << "[INFO] Request to erase VM received" << std::endl;
    });

    server_.Post("/startVM", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(mutex_);
        handleStartVM(req, res);
        std::cout << "[INFO] Request to start VM received" << std::endl;
    });

    server_.Post("/stopVM", [&](const httplib::Request& req, httplib::Response& res) {
        std::lock_guard<std::mutex> lock(mutex_);
        handleStopVM(req, res);
        std::cout << "[INFO] Request to stop VM received" << std::endl;
    });
}

bool Server::isValidVMName(std::string_view name) const {
    static const std::regex pattern("^[a-zA-Z0-9_-]{3,32}$");
    return std::regex_match(name.data(), pattern);
}

void Server::sendJsonResponse(httplib::Response& res, int status, const std::string& message) {
    res.status = status;
    std::ostringstream oss;
    oss << R"({"message":")" << message << R"("})";
    res.set_content(oss.str(), "application/json");
}

void Server::handleAddVM(const httplib::Request& req, httplib::Response& res) {
    const auto name = req.get_param_value("name");
    const auto typeStr = req.get_param_value("type");

    if (!isValidVMName(name) || typeStr.empty()) {
        sendJsonResponse(res, 400, "Missing or invalid 'name' or 'type'");
        return;
    }

    // VMType type;
    // if (typeStr == "ubuntu") {
    //     type = VMType::Ubuntu;
    // } else if (typeStr == "windows10") {
    //     type = VMType::Windows10;
    // } else {
    //     sendJsonResponse(res, 400, "Unsupported VM type");
    //     return;
    // }

    try {
        // if (vmManager_.addVM(name, type)) {
        if (1) {
            sendJsonResponse(res, 200, "VM '" + name + "' added successfully");
        } else {
            sendJsonResponse(res, 409, "VM '" + name + "' already exists");
        }
    } catch (const std::exception& e) {
        sendJsonResponse(res, 500, "Internal error: " + std::string(e.what()));
    }
}

void Server::handleEraseVM(const httplib::Request& req, httplib::Response& res) {
    const auto name = req.get_param_value("name");

    if (!isValidVMName(name)) {
        sendJsonResponse(res, 400, "Invalid or missing VM name");
        return;
    }

    try {
        // if (vmManager_.eraseVM(name)) {
        if (1) {
            sendJsonResponse(res, 200, "VM '" + name + "' deleted successfully");
        } else {
            sendJsonResponse(res, 404, "VM '" + name + "' not found");
        }
    } catch (const std::exception& e) {
        sendJsonResponse(res, 500, "Internal error: " + std::string(e.what()));
    }
}

void Server::handleStartVM(const httplib::Request& req, httplib::Response& res) {
    const auto name = req.get_param_value("name");

    if (!isValidVMName(name)) {
        sendJsonResponse(res, 400, "Invalid or missing VM name");
        return;
    }

    try {
        // if (vmManager_.startVM(name)) {
        if (1) {        
            sendJsonResponse(res, 200, "VM '" + name + "' started successfully");
        } else {
            sendJsonResponse(res, 404, "VM '" + name + "' not found or failed to start");
        }
    } catch (const std::exception& e) {
        sendJsonResponse(res, 500, "Internal error: " + std::string(e.what()));
    }
}

void Server::handleStopVM(const httplib::Request& req, httplib::Response& res) {
    const auto name = req.get_param_value("name");

    if (!isValidVMName(name)) {
        sendJsonResponse(res, 400, "Invalid or missing VM name");
        return;
    }

    try {
        // if (vmManager_.stopVM(name)) {
        if (1) {
            sendJsonResponse(res, 200, "VM '" + name + "' stopped successfully");
        } else {
            sendJsonResponse(res, 404, "VM '" + name + "' not found or failed to stop");
        }
    } catch (const std::exception& e) {
        sendJsonResponse(res, 500, "Internal error: " + std::string(e.what()));
    }
}
