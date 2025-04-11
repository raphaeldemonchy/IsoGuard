#include "libvirt/LibvirtManager.hpp"
#include <iostream>
#include <stdexcept>
#include <filesystem>

LibvirtManager::LibvirtManager() noexcept
    : ptr_connection(nullptr) {}

LibvirtManager::~LibvirtManager() noexcept {
    if (ptr_connection) {
        virConnectClose(ptr_connection); // On ferme la connexion libvirt si ouverte
    }
}

bool LibvirtManager::connect(const std::string& uri) {
    ptr_connection = virConnectOpen(uri.c_str());
    if (!ptr_connection) {
        std::cerr << "Failed to open connection to " << uri << std::endl;
        return false;
    }
    std::cout << "Successfully connected to " << uri << std::endl;
    return true;
}

bool LibvirtManager::createVM(const std::string& name, const std::string& xmlConfig) {
    virDomainPtr domain = virDomainCreateXML(ptr_connection, xmlConfig.c_str(), 0);
    if (!domain) {
        std::cerr << "Failed to create VM: " << name << std::endl;
        return false;
    }

    std::cout << "VM " << name << " created successfully." << std::endl;
    virDomainFree(domain);  // Libération de la mémoire allouée à la VM
    return true;
}

bool LibvirtManager::startVM(const std::string& name) {
    virDomainPtr domain = virDomainLookupByName(ptr_connection, name.c_str());
    if (!domain) {
        std::cerr << "Failed to find VM: " << name << std::endl;
        return false;
    }

    if (virDomainCreate(domain) != 0) {
        std::cerr << "Failed to start VM: " << name << std::endl;
        virDomainFree(domain);
        return false;
    }

    std::cout << "VM " << name << " started successfully." << std::endl;
    virDomainFree(domain);
    return true;
}

bool LibvirtManager::stopVM(const std::string& name) {
    virDomainPtr domain = virDomainLookupByName(ptr_connection, name.c_str());
    if (!domain) {
        std::cerr << "Failed to find VM: " << name << std::endl;
        return false;
    }

    if (virDomainShutdown(domain) != 0) {
        std::cerr << "Failed to stop VM: " << name << std::endl;
        virDomainFree(domain);
        return false;
    }

    std::cout << "VM " << name << " stopped successfully." << std::endl;
    virDomainFree(domain);
    return true;
}

bool LibvirtManager::destroyVM(const std::string& name) {
    virDomainPtr domain = virDomainLookupByName(ptr_connection, name.c_str());
    if (!domain) {
        std::cerr << "Failed to find VM: " << name << std::endl;
        return false;
    }

    if (virDomainDestroy(domain) != 0) {
        std::cerr << "Failed to destroy VM: " << name << std::endl;
        virDomainFree(domain);
        return false;
    }

    std::cout << "VM " << name << " destroyed successfully." << std::endl;
    virDomainFree(domain);
    return true;
}

bool LibvirtManager::copyDiskTemplate(const std::string& srcPath, const std::string& dstPath) {
    try {
        std::filesystem::copy(srcPath, dstPath);
        std::cout << "Disk template copied from " << srcPath << " to " << dstPath << std::endl;
        return true;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error copying disk template: " << e.what() << std::endl;
        return false;
    }
}

bool LibvirtManager::copyXMLTemplate(const std::string& srcPath, const std::string& dstPath) {
    try {
        std::filesystem::copy(srcPath, dstPath);
        std::cout << "XML template copied from " << srcPath << " to " << dstPath << std::endl;
        return true;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error copying XML template: " << e.what() << std::endl;
        return false;
    }
}

std::string LibvirtManager::injectVMNameIntoXML(const std::string& xmlContent, const std::string& vmName) {
    std::string updatedXml = xmlContent;

    size_t nameStart = updatedXml.find("<name>");
    size_t nameEnd = updatedXml.find("</name>");

    if (nameStart != std::string::npos && nameEnd != std::string::npos && nameEnd > nameStart) {
        nameStart += std::string("<name>").length();
        updatedXml.replace(nameStart, nameEnd - nameStart, vmName);
    } else {
        std::cerr << "[injectVMNameIntoXML] Balises <name>...</name> introuvables dans le XML !" << std::endl;
    }

    return updatedXml;
}

bool LibvirtManager::isVMRunning(const std::string& vmName) {
    virDomainPtr domain = virDomainLookupByName(ptr_connection, vmName.c_str());
    if (!domain) {
        std::cerr << "Erreur: Impossible de trouver la VM " << vmName << std::endl;
        return false;
    }

    virDomainInfo info;
    if (virDomainGetInfo(domain, &info) == -1) {
        std::cerr << "Erreur lors de la récupération des infos de la VM" << std::endl;
        virDomainFree(domain);
        return false;
    }

    virDomainFree(domain);

    return (info.state == VIR_DOMAIN_RUNNING);
}

