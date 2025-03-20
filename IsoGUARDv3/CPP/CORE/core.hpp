#ifndef CORE_HPP
#define CORE_HPP

#include <string>
#include <libvirt/libvirt.h>

class Core {
public:
    Core();                         // Constructeur qui gère la connexion à libvirt
    ~Core();                        // Destructeur pour fermer la connexion
    static std::string loadXMLConfig(const std::string& xmlPath, const std::string& vmName);
    void createVM(const std::string& xmlPath, const std::string& vmName); // Création de la VM
    void deleteVM(const std::string& vmName);  // Suppression de la VM
    void startVM(const std::string& vmName);   // Démarrage de la VM
    void shutdownVM(const std::string& vmName); // Arrêt de la VM

private:
    virConnectPtr conn;  // Connexion à libvirt

};

#endif // CORE_HPP
