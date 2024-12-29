#include "core/Core.hpp"
#include "ModuleVM/ModuleVM.hpp"
#include "ModuleNetworks/ModuleNetworks.hpp"

int main() {
    Core core;

    ModuleVM moduleVM;
    ModuleNetworks moduleNetworks;

    core.addModule(&moduleVM);
    core.addModule(&moduleNetworks);

    // Envoyer un message à un module spécifique
    moduleVM.send("Avengers Assemble", &moduleNetworks);

    // Envoyer un message à tous les modules
    moduleNetworks.send("API: Handling request");

    // Créer des VMs
    moduleVM.createVM("VM1");
    moduleVM.createVM("VM2");

    // Lister les VMs
    moduleVM.listVMs();

    return 0;
}