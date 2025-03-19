#include <libvirt/libvirt.h>
#include <iostream>
#include <fstream>
#include <sstream>

// 🔹 Charge le contenu du fichier XML et remplace les valeurs dynamiques
std::string loadXMLConfig(const std::string& xmlPath, const std::string& vmName, const std::string& diskPath) {
    std::ifstream file(xmlPath);
    if (!file) {
        std::cerr << "❌ Erreur: Impossible d'ouvrir le fichier XML: " << xmlPath << "\n";
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();  // Charge le fichier XML en mémoire
    std::string xml = buffer.str();

    // Remplacement des valeurs dynamiques
    size_t pos;
    while ((pos = xml.find("{{VM_NAME}}")) != std::string::npos)
        xml.replace(pos, 10, vmName);

    while ((pos = xml.find("{{DISK_PATH}}")) != std::string::npos)
        xml.replace(pos, 12, diskPath);

    return xml;
}

// 🔹 Crée et démarre une machine virtuelle à partir du fichier XML
void createVM(const std::string& xmlPath, const std::string& vmName, const std::string& diskPath) {
    virConnectPtr conn = virConnectOpen("qemu:///system");
    if (!conn) {
        std::cerr << "❌ Erreur: Impossible de se connecter à libvirt\n";
        return;
    }

    std::string xmlConfig = loadXMLConfig(xmlPath, vmName, diskPath);
    if (xmlConfig.empty()) {
        std::cerr << "❌ Erreur: Configuration XML invalide ou vide\n";
        virConnectClose(conn);
        return;
    }

    // Affiche la configuration XML chargée (DEBUG)
    std::cout << "📄 Configuration XML chargée :\n" << xmlConfig << "\n";

    // Définit et démarre la VM
    virDomainPtr dom = virDomainDefineXML(conn, xmlConfig.c_str());
    if (dom) {
        virDomainCreate(dom);
        std::cout << "✅ VM " << vmName << " créée et démarrée avec succès.\n";
        virDomainFree(dom);
    } else {
        std::cerr << "❌ Erreur: Impossible de créer la VM\n";
    }

    virConnectClose(conn);
}

// 🔹 Programme principal
int main() {
    std::string xmlPath = "vm.xml";  // Chemin du fichier XML de configuration
    std::string vmName = "SANDBOX1";
    std::string diskPath = "YEAH ZEUBI";

    createVM(xmlPath, vmName, diskPath);
    return 0;
}
