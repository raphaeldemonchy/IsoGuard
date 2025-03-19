#include <iostream>
#include <libvirt/libvirt.h>
#include <httplib.h> // Inclure la bibliothèque httplib
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include <chrono>

class VMManager {
private:
    virConnectPtr conn;
    int vm_id_counter;

public:
    VMManager() : vm_id_counter(0) {
        conn = virConnectOpen("qemu:///system");
        if (!conn) {
            std::cerr << "Échec de la connexion à libvirt." << std::endl;
            exit(1);
        }
    }

    ~VMManager() {
        if (conn) {
            virConnectClose(conn);
        }
    }

    // Générer un nom de VM unique basé sur un timestamp
    std::string generateVMName() {
        std::ostringstream vmName;
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        vmName << "VM_" << millis;  // Utilisation de l'horodatage en millisecondes pour générer un nom unique
        return vmName.str();
    }

    // Vérifier si la VM existe déjà avec ce nom
    bool isVMDefined(const std::string &vmName) {
        virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
        return dom != nullptr;
    }

    bool createVM(const std::string &xmlPath) {
        std::string vmName = generateVMName();  // Utilisation du nom généré
        std::cout << "Création de la VM avec le nom: " << vmName << std::endl;

        // Vérifier si la VM existe déjà
        if (isVMDefined(vmName)) {
            std::cerr << "Erreur: La VM " << vmName << " existe déjà." << std::endl;
            return false;
        }

        // Créer un snapshot du disque principal (windows10.qcow2)
        std::string snapshotFile = "/var/lib/libvirt/images/" + vmName + "_disk.qcow2";
        std::string command = "qemu-img create -f qcow2 -b /var/lib/libvirt/images/windows10.qcow2 /var/lib/libvirt/images/" + vmName + "_disk.qcow2";

        int result = system(command.c_str());
        if (result != 0) {
            std::cerr << "Erreur lors de la création du snapshot pour " << vmName << std::endl;
            return false;
        }

        // Lire et modifier le fichier XML
        std::ifstream file(xmlPath);
        if (!file) {
            std::cerr << "Fichier XML de configuration introuvable." << std::endl;
            return false;
        }

        std::string xmlContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        size_t pos = xmlContent.find("<name>");
        if (pos != std::string::npos) {
            size_t endPos = xmlContent.find("</name>", pos);
            if (endPos != std::string::npos) {
                xmlContent.replace(pos + 6, endPos - (pos + 6), vmName);  // Remplacer le nom de la VM
                std::cout << "XML modifié:\n" << xmlContent << std::endl;
            } else {
                std::cerr << "Erreur: balise </name> non trouvée." << std::endl;
                return false;
            }
        } else {
            std::cerr << "Erreur: balise <name> non trouvée." << std::endl;
            return false;
        }

        // Remplacer le chemin du disque principal par celui du snapshot
        pos = xmlContent.find("<source file='/var/lib/libvirt/images/windows10.qcow2'/>");
        if (pos != std::string::npos) {
            xmlContent.replace(pos + 31, 37, snapshotFile);  // Remplacer le fichier du disque principal par le fichier du snapshot
        }

        // Définir la VM à partir du fichier XML modifié
        virDomainPtr dom = virDomainDefineXML(conn, xmlContent.c_str());
        if (dom == nullptr) {
            std::cerr << "Erreur lors de la définition de la VM." << std::endl;
            return false;
        }

        // Démarrer la VM
        int ret = virDomainCreate(dom);
        if (ret != 0) {
            std::cerr << "Erreur lors du démarrage de la VM." << std::endl;
            return false;
        }

        return true;
    }


    // Démarrer la VM
    bool startVM(const std::string &vmName) {
        virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
        if (!dom) {
            std::cerr << "La VM " << vmName << " n'a pas été trouvée." << std::endl;
            return false;
        }
        int ret = virDomainCreate(dom);
        if (ret != 0) {
            std::cerr << "Erreur lors du démarrage de la VM " << vmName << "." << std::endl;
            return false;
        }
        return true;
    }

    // Arrêter la VM
    bool stopVM(const std::string &vmName) {
        virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
        if (!dom) {
            std::cerr << "La VM " << vmName << " n'a pas été trouvée." << std::endl;
            return false;
        }
        return virDomainShutdown(dom) == 0;
    }

    // Supprimer la VM
    bool deleteVM(const std::string &vmName) {
        virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
        if (!dom) {
            std::cerr << "La VM " << vmName << " n'a pas été trouvée." << std::endl;
            return false;
        }

        // Supprimer le fichier de snapshot de la VM
        std::string snapshotFile = "/var/lib/libvirt/images/" + vmName + "_disk.qcow2";
        std::string command = "rm -f " + snapshotFile;
        int result = system(command.c_str());
        if (result != 0) {
            std::cerr << "Erreur lors de la suppression du snapshot pour " << vmName << std::endl;
            return false;
        }

        // Détruire et undefine la VM
        virDomainDestroy(dom);
        return virDomainUndefine(dom) == 0;
    }

    // Créer un snapshot de la VM
    bool createSnapshot(const std::string &vmName) {
        virDomainPtr dom = virDomainLookupByName(conn, vmName.c_str());
        if (!dom) {
            std::cerr << "La VM " << vmName << " n'a pas été trouvée." << std::endl;
            return false;
        }

        // Vérifier si la VM est en cours d'exécution
        int isActive = virDomainIsActive(dom);
        if (isActive != 1) {
            std::cerr << "La VM " << vmName << " n'est pas en cours d'exécution." << std::endl;
            return false;
        }

        // Définir le nom et le chemin du fichier de snapshot
        std::string snapshotFile = "/var/lib/libvirt/images/" + vmName + "_snapshot.qcow2";

        // Créer un XML pour définir le snapshot
        std::ostringstream snapshotXML;
        snapshotXML << "<domainsnapshot>"
                    << "<name>" << vmName << "_snapshot</name>"
                    << "<disks>"
                    << "<disk name='vda'>"
                    << "<diskSnapshot/>"
                    << "<source file='" << snapshotFile << "'/>"
                    << "</disk>"
                    << "</disks>"
                    << "</domainsnapshot>";

        // Créer le snapshot
        virDomainSnapshotPtr snapshot = virDomainSnapshotCreateXML(dom, snapshotXML.str().c_str(), 0);
        if (!snapshot) {
            std::cerr << "Erreur lors de la création du snapshot." << std::endl;
            return false;
        }

        std::cout << "Snapshot créé avec succès." << std::endl;
        return true;
    }


};

int main() {
    httplib::Server svr;

    VMManager manager;

    std::cout << "Démarrage du serveur..." << std::endl;

    // Route pour créer une VM
    svr.Post("/create", [&](const httplib::Request &req, httplib::Response &res) {
        if (manager.createVM("Config/vm.xml")) {
            res.status = 200;
            res.set_content("VM créée", "text/plain");
        } else {
            res.status = 500;
            res.set_content("Erreur lors de la création de la VM", "text/plain");
        }
    });

    // Route pour démarrer la VM
    svr.Post("/start", [&](const httplib::Request &req, httplib::Response &res) {
        // Assurez-vous d'utiliser le bon nom de VM
        std::string vmName = "VM_0000";  // Exemple, cela pourrait être dynamique
        if (manager.startVM(vmName)) {
            res.status = 200;
            res.set_content("VM démarrée", "text/plain");
        } else {
            res.status = 500;
            res.set_content("Erreur lors du démarrage de la VM", "text/plain");
        }
    });

    // Route pour arrêter la VM
    svr.Post("/stop", [&](const httplib::Request &req, httplib::Response &res) {
        std::string vmName = "VM_0000";  // Exemple, cela pourrait être dynamique
        if (manager.stopVM(vmName)) {
            res.status = 200;
            res.set_content("VM arrêtée", "text/plain");
        } else {
            res.status = 500;
            res.set_content("Erreur lors de l'arrêt de la VM", "text/plain");
        }
    });

    // Route pour supprimer la VM
    svr.Post("/delete", [&](const httplib::Request &req, httplib::Response &res) {
        std::string vmName = "VM_0000";  // Exemple, cela pourrait être dynamique
        if (manager.deleteVM(vmName)) {
            res.status = 200;
            res.set_content("VM supprimée", "text/plain");
        } else {
            res.status = 500;
            res.set_content("Erreur lors de la suppression de la VM", "text/plain");
        }
    });

    // Route pour créer un snapshot
    svr.Post("/snapshot", [&](const httplib::Request &req, httplib::Response &res) {
        std::string vmName = "VM_0000";  // Exemple, cela pourrait être dynamique
        if (manager.createSnapshot(vmName)) {
            res.status = 200;
            res.set_content("Snapshot créé", "text/plain");
        } else {
            res.status = 500;
            res.set_content("Erreur lors de la création du snapshot", "text/plain");
        }
    });

    // Lancer le serveur sur le port 8080
    svr.listen("127.0.0.1", 8080);
    return 0;
}
