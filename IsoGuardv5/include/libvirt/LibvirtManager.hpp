#ifndef LIBVIRT_MANAGER_HPP
#define LIBVIRT_MANAGER_HPP

#include <libvirt/libvirt.h>
#include <string>
#include <memory>

class LibvirtManager {
    public:
        LibvirtManager() noexcept;
        ~LibvirtManager() noexcept;

        // Connexion à libvirt
        bool connect(const std::string& uri);

        // Gestion des VMs
        bool createVM(const std::string& name, const std::string& xmlConfig);
        bool startVM(const std::string& name);
        bool stopVM(const std::string& name);
        bool destroyVM(const std::string& name);

        // Copie de fichiers de template
        bool copyDiskTemplate(const std::string& srcPath, const std::string& dstPath);
        bool copyXMLTemplate(const std::string& srcPath, const std::string& dstPath);

        std::string injectVMNameIntoXML(const std::string& xmlContent, const std::string& vmName);
        bool isVMRunning(const std::string& vmName);


    private:
        virConnectPtr ptr_connection; // Pointeur vers la connexion libvirt
};

#endif // LIBVIRT_MANAGER_HPP
