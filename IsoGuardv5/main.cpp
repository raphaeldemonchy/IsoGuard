#include "manager/VMManager.hpp"

int main() {
    VMManager manager;

    manager.addVM("VM1", VMType::Windows10);
    manager.listVMs();
    manager.startVM("VM1");
    manager.stopVM("VM1");
    manager.eraseVM("VM1");
    manager.listVMs();

    return 0;
}





// #include "factory/VirtualMachineFactory.hpp"
// // #include "libvirt/LibvirtManager.hpp"
// #include <iostream>
// #include <cassert>

// int main() {
//     auto vm1 = VirtualMachineFactory::createVM(VMType::Windows10, "TestWin10");
//     auto vm2 = VirtualMachineFactory::createVM(VMType::Ubuntu, "TestUbuntu");

//     vm1->start();
//     vm1->stop();
//     vm1->destroy();

//     vm2->start();
//     vm2->stop();
//     vm2->destroy();

//     return 0;

//     // LibvirtManager LibvirtManager;
// }

// #include "libvirt/LibvirtManager.hpp"
// #include <fstream>
// #include <iostream>
// #include <cassert>

// int main() {
//     // Créer l'instance du manager
//     LibvirtManager libvirtManager;

//     // Tester la connexion à libvirt
//     if (!libvirtManager.connect("qemu:///system")) {
//         std::cerr << "Erreur de connexion à libvirt" << std::endl;
//         return 1;
//     }

//     // Définir un nom de VM à injecter
//     std::string vmName = "TestVM";

//     // Charger la configuration XML du template
//     std::string xmlConfig;
//     std::ifstream xmlFile("/home/uknown/Bureau/Capstone/V2/IsoGuard/IsoGuardv5/template/vm.xml");
//     if (!xmlFile) {
//         std::cerr << "Erreur d'ouverture du fichier XML de configuration" << std::endl;
//         return 1;
//     }
//     xmlConfig.assign((std::istreambuf_iterator<char>(xmlFile)), std::istreambuf_iterator<char>());
//     xmlFile.close();

//     // Définir le chemin du disque QCOW2
//     std::string diskPath = "/var/lib/libvirt/images/windows10.qcow2";

//     // Modifier le XML pour inclure le disque réel
//     size_t diskPos = xmlConfig.find("<source file='/path/to/your/template/disk.qcow2'/>");
//     if (diskPos != std::string::npos) {
//         xmlConfig.replace(diskPos, std::string("<source file='/path/to/your/template/disk.qcow2'/>").length(),
//                           "<source file='" + diskPath + "'/>");
//     } else {
//         std::cerr << "Erreur : template XML ne contient pas de chemin de disque valide." << std::endl;
//         return 1;
//     }

//     // Injecter dynamiquement le nom de la VM dans le XML
//     std::string updatedXml = libvirtManager.injectVMNameIntoXML(xmlConfig, vmName);

//     // Créer la VM
//     if (!libvirtManager.createVM(vmName, updatedXml)) {
//         std::cerr << "Erreur lors de la création de la VM" << std::endl;
//         return 1;
//     }

//     // Démarrer la VM
//     if (!libvirtManager.startVM(vmName)) {
//         std::cerr << "Erreur lors du démarrage de la VM" << std::endl;
//         return 1;
//     }

//     // Arrêter la VM
//     if (!libvirtManager.stopVM(vmName)) {
//         std::cerr << "Erreur lors de l'arrêt de la VM" << std::endl;
//         return 1;
//     }

//     // Détruire la VM
//     if (!libvirtManager.destroyVM(vmName)) {
//         std::cerr << "Erreur lors de la destruction de la VM" << std::endl;
//         return 1;
//     }

//     std::cout << "Test LibvirtManager réussi !" << std::endl;
//     return 0;
// }

