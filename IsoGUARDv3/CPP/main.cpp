#include <libvirt/libvirt.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// // 🔹 Charge le contenu du fichier XML et remplace les valeurs dynamiques
// std::string loadXMLConfig(const std::string& xmlPath, const std::string& vmName) {
//     std::ifstream file(xmlPath);
//     if (!file) {
//         std::cerr << "Erreur: Impossible d'ouvrir le fichier XML: " << xmlPath << "\n";
//         return "";
//     }

//     std::stringstream buffer;
//     buffer << file.rdbuf();  // Charge le fichier XML en mémoire
//     std::string xml = buffer.str();

//     // Remplacer le contenu de la balise <name>
//     size_t nameStartPos = xml.find("<name>");
//     size_t nameEndPos = xml.find("</name>", nameStartPos);

//     if (nameStartPos != std::string::npos && nameEndPos != std::string::npos) {
//         // Calculer la longueur de la balise <name> ... </name>
//         size_t nameLength = nameEndPos - nameStartPos + 7; // 7 est la longueur de "</name>"

//         // Remplacer le contenu de la balise <name>
//         xml.replace(nameStartPos + 6, nameLength - 13, vmName); // 6 pour après <name> et -13 pour avant </name>
//     }

//     return xml;
// }

// // 🔹 Crée et démarre une machine virtuelle à partir du fichier XML
// void createVM(const std::string& xmlPath, const std::string& vmName) {
//     virConnectPtr conn = virConnectOpen("qemu:///system");
//     if (!conn) {
//         std::cerr << "Erreur: Impossible de se connecter à libvirt\n";
//         return;
//     }

//     std::string xmlConfig = loadXMLConfig(xmlPath, vmName);
//     if (xmlConfig.empty()) {
//         std::cerr << "Erreur: Configuration XML invalide ou vide\n";
//         virConnectClose(conn);
//         return;
//     }

//     // Affiche la configuration XML chargée (DEBUG)
//     std::cout << "Configuration XML chargée :\n" << xmlConfig << "\n";

//     // Sauvegarder les modifications dans le fichier XML
//     std::ofstream outFile(xmlPath);
//     if (!outFile) {
//         std::cerr << "Erreur: Impossible d'ouvrir le fichier pour écriture: " << xmlPath << "\n";
//         virConnectClose(conn);
//         return;
//     }

//     outFile << xmlConfig;  // Réécrit le XML modifié dans le fichier
//     outFile.close();

//     // Définit et démarre la VM
//     virDomainPtr dom = virDomainDefineXML(conn, xmlConfig.c_str());
//     if (dom) {
//         virDomainCreate(dom);
//         std::cout << "VM " << vmName << " créée et démarrée avec succès.\n";
//         virDomainFree(dom);
//     } else {
//         std::cerr << "Erreur: Impossible de créer la VM\n";
//     }

//     virConnectClose(conn);
// }

// // 🔹 Programme principal
// int main() {
//     std::string xmlPath = "vm.xml";  // Chemin du fichier XML de configuration
//     std::string vmName = "test";  // Nom de la VM (à remplacer dans le fichier XML)
//     // Exemple de chemin disque (non utilisé dans le code actuel)
//     std::string diskPath = "/var/lib/libvirt/images/windows10.qcow2";

//     createVM(xmlPath, vmName);
//     return 0;
// }

#include "CORE/core.hpp"
#include <iostream>

int main() {
    std::string xmlPath = "vm.xml";  // Chemin du fichier XML de configuration
    std::string vmName = "test2";  // Nom de la VM (à remplacer dans le fichier XML)

    // Appel à la méthode pour créer la VM
    Core::createVM(xmlPath, vmName);

    return 0;
}

