#include "core.hpp"
#include <libvirt/libvirt.h>
#include <iostream>
#include <fstream>
#include <sstream>

// 🔹 Constructeur : connexion à libvirt
Core::Core() {
    // Ouverture de la connexion à libvirt
    conn = virConnectOpen("qemu:///system");
    if (!conn) {
        std::cerr << "Erreur: Impossible de se connecter à libvirt\n";
    }
}

// 🔹 Destructeur : fermeture de la connexion à libvirt
Core::~Core() {
    if (conn) {
        virConnectClose(conn);
    }
}

// 🔹 Charge le contenu du fichier XML et remplace les valeurs dynamiques
std::string Core::loadXMLConfig(const std::string& xmlPath, const std::string& vmName) {
    std::ifstream file(xmlPath);
    if (!file) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier XML: " << xmlPath << "\n";
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();  // Charge le fichier XML en mémoire
    std::string xml = buffer.str();

    // Remplacer le contenu de la balise <name>
    size_t nameStartPos = xml.find("<name>");
    size_t nameEndPos = xml.find("</name>", nameStartPos);

    if (nameStartPos != std::string::npos && nameEndPos != std::string::npos) {
        // Calculer la longueur de la balise <name> ... </name>
        size_t nameLength = nameEndPos - nameStartPos + 7; // 7 est la longueur de "</name>"

        // Remplacer le contenu de la balise <name>
        xml.replace(nameStartPos + 6, nameLength - 13, vmName); // 6 pour après <name> et -13 pour avant </name>
    }

    return xml;
}

// 🔹 Crée et démarre une machine virtuelle à partir du fichier XML
void Core::createVM(const std::string& xmlPath, const std::string& vmName) {
    if (!conn) {
        std::cerr << "Erreur: Connexion libvirt non établie.\n";
        return;
    }

    std::string xmlConfig = loadXMLConfig(xmlPath, vmName);
    if (xmlConfig.empty()) {
        std::cerr << "Erreur: Configuration XML invalide ou vide\n";
        return;
    }

    // Affiche la configuration XML chargée (DEBUG)
    std::cout << "Configuration XML chargée :\n" << xmlConfig << "\n";

    // Sauvegarder les modifications dans le fichier XML
    std::ofstream outFile(xmlPath);
    if (!outFile) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier pour écriture: " << xmlPath << "\n";
        return;
    }

    outFile << xmlConfig;  // Réécrit le XML modifié dans le fichier
    outFile.close();

    // Définit et démarre la VM
    virDomainPtr dom = virDomainDefineXML(conn, xmlConfig.c_str());
    if (dom) {
        virDomainCreate(dom);
        std::cout << "VM " << vmName << " créée et démarrée avec succès.\n";
        virDomainFree(dom);
    } else {
        std::cerr << "Erreur: Impossible de créer la VM\n";
    }
}

// 🔹 Supprimer la VM
void Core::deleteVM(const std::string& vmName) {
    if (!conn) {
        std::cerr << "Erreur: Connexion libvirt non établie.\n";
        return;
    }

    virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
    if (!dom) {
        std::cerr << "Erreur: VM " << vmName << " introuvable\n";
        return;
    }

    // Détruire la VM et libérer la ressource
    int result = virDomainDestroy(dom);
    if (result == 0) {
        std::cout << "VM " << vmName << " détruite avec succès.\n";
    } else {
        std::cerr << "Erreur: Impossible de détruire la VM\n";
    }

    virDomainFree(dom);
}

// 🔹 Démarrer la VM
void Core::startVM(const std::string& vmName) {
    if (!conn) {
        std::cerr << "Erreur: Connexion libvirt non établie.\n";
        return;
    }

    virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
    if (!dom) {
        std::cerr << "Erreur: VM " << vmName << " introuvable\n";
        return;
    }

    // Démarrer la VM
    int result = virDomainCreate(dom);
    if (result == 0) {
        std::cout << "VM " << vmName << " démarrée avec succès.\n";
    } else {
        std::cerr << "Erreur: Impossible de démarrer la VM\n";
    }

    virDomainFree(dom);
}

// 🔹 Arrêter la VM
void Core::shutdownVM(const std::string& vmName) {
    if (!conn) {
        std::cerr << "Erreur: Connexion libvirt non établie.\n";
        return;
    }

    virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
    if (!dom) {
        std::cerr << "Erreur: VM " << vmName << " introuvable\n";
        return;
    }

    // Arrêter la VM
    int result = virDomainShutdown(dom);
    if (result == 0) {
        std::cout << "VM " << vmName << " arrêtée avec succès.\n";
    } else {
        std::cerr << "Erreur: Impossible d'arrêter la VM\n";
    }

    virDomainFree(dom);
}
