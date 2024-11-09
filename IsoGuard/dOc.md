> ### **démon/daemon** = Processus informatique qui s'exécute en arrière-plan sans interaction direct avec l'utilisateur. Contrairement au programmes qui sont lancés par l'utilisateur et qui s'éxecutent dans un terminal ou une interface graphique, les démons s'exécutent en arrère-plan, souvent dès le démarrage du système, et sont responsables de certaines taches système ou de services.
> 
> exemple (libvirtd est un démon qui gère l'execution des machines virtuelles via libvirt, permettant ainsi la création, l'arret, la gestion des machines virtuelles KVM

---

## **KVM (Kernel-based Virtual Machine)**

*   **Nom du paquet** : _quemu-kvm_
    *   **Role : KVM** est hyperviseur de type 1 (bare-metal) qui permet la virtualisation sur des systémes Linux. Il permet d'exécuter des machines virtuelles (VM)  en utilisant la virtualisation matérielle du processeur. KVM est intégré directement dans le noyau Linux et permet une performance proche de celle du matériel.
*   **Installation** :

> `$> sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager`

## **Libvirt (libvirt-deamon)**

*   **Nom du paquet :** _libvirt-daemon-system, libvirt-client_
    *   _**Role:** libvirt est une bibliothèque et une API de gestion de la virtualisation. Elle permet d'interagir avec différe,ts hyperviseur (KVM, Xen, etc.) Elle fournit des outils pour gérer les VMs, la configuration du réseau, les stockages et autre ressources liées a la virtualisation. Le deamon libvirt, permet de controler les instances de virtualisation via des commandes et interfaces._
*   **Composants** :
    *   libvirt-daemon-system : Le démon de gestion des VM qui permet de controler les VMs
    *   libvirt-clients : Les outils client en ligne de commande (exemple, virsh ) pour interagir avec le démon
*   _**Installation** :_

## **Virt-Manager**

*   **Nom du paquet :** _virt-manager_
    *   _**Role** : Interface graphique pour gérer les machines virtuelles. Virt-Manager fournit une interface conviviale pour créeer, configurer et surveiller les VMs, gérer les ressources, ainsi que pour visualiser la console des VMs._
    *   _**Utilisation** : Utile pour les utilisateurs qui préfèrent une interface graphique pour gérer les VMs plutot que la ligne de commande._
*   _**Installation :**_

## _**QEMU (Quick EMulator)**_

*   _**Nom du paquet :** qemu-kvm_
    *   _**Role :** QEMU est un émulateur et un virtualisateur du matériel. Il permet de simulelr des machines virtuelles, des périphériques et de gérer l'exécution d'un système d'exploitation invité dans un environnement isolée._
    *   _**Utilisation avec KVM** : Quand QEMU est utilisé avec KVM, ile permet d'exécuter des machines virtuelles de manière performante en utilisant la virtualisation matérielle du processeur._
*   _**Installation :**_

## _**Bridge-utils**_

*   **Nom du paquet** _**:** bridge-utils_
    *   **Role** : Un exemble d'outils pour configurer les réseaux de type bridge (pont). Cela permet de connecter une VM a un réseau physique et a d'autre VMs via un réseau virtuel, comme un pont réseau entre les VMs et l'hote.
    *   **Utilisation :** Pour configurer et gérer les interfaces réseau sur l'hote pour les machines virtuelles, en particulier la création de pont réseau (bridging)

## **VirtIO Drivers**

*   **Nom du paquet :** drivers via QEMU ou téléchargement sur les sites des distribution invités (généralement pour les systèmes invités Windows et Linux)
    *   **Role** : Les drivers VirtIO sont utilisé pour fournir des performances optimisées pour les machines virtuelles, particulièrement en ce qui concerne les périphériques de stockages et réseau.
    *   **Utilisation** : Il sont essentiels pour les performances des VMs exécutées avec KVM, car ils permettent une meilleur communication entre l'hote et l'invité.

## **Spice**

*   **Nom du paquet : spice-server**
    *   **Role :** Spice est un protocole graphique utilisé pour accéder a l'interface graphique des machines virtuelles. Il permet une interaction avec l'environnement graphique de la VM depuis un poste distant.
    *   **Utilisation :** Idéal pour des VMs ayant une interface graphique, notamment pour accéder a un bureau virtuel de la machine virtuelle via un client Spice

## **VNC (Virtual Network Computing)**

*   **Nom du paquet :** tightvncserver, x11vnc, ou tigervnc-standalone-server
    *   **Role** : VNC est un protocole graphique qui permet d'accéder a l'interface graphique de la machine virtuelle. Contrairement a Spice, VNC est plus utilisé pour des connexions réseau non sécuritsées ou pour des usage basique de bureau virtuel.
    *   **Utilisation** : Utilisé pour accéder a l'affichage graphique d'une VM via une interface graphique ou un client VNC

## **Cloud-Init**

*   **Nom du paquet :** _cloud-init_
    *   **Role :** Outils permettant de configurer les instances de machines virtuelles au moment de leur première mise en route. Il est utilisé pour configurer des éléments comme les adresse IP, les utilisateurs et la clé SSH lors de la création de la VM.
    *   **Utilisation :** Si tu veux automatiser le déploiement et la configuration des VMs (par exemple pour ajouter un utilisateur ou définir une clé SSH a la premiere connexion)

## **QEMU-IMG**

*   **Nom du paquet :** _QEMU-IMG_
    *   **Role :** Outil utilisé pour créer, convertir et manipuler des disques virtuels. Il permet de gérer les images disque des VMs.
    *   **Utilisation :** Uitle pour gérer les disques des VMs, comme crée des fichiers d'image de disque (exemple : .qcow2) et les redimenssioner.

## **Libvirt SDK (optionnel )**

*   **Nom du paquet :** libvirt-dev
    *   **Role:** Fournit les fichiers de développement nécessaires pour interagir avec l'API libvirt a partir d'un programme C ou C++
    *   **Utilisation :** Pour développer des outils personnalisé ou automatiser des actions via des scripts C++ en utilisant l'API libvirt, ce package fournit les bibiliothèques et headers nécessaires.

---

# Sécurité supplémentaires

*   **AppArmor, SELinux** : Pour renforcer la sécurité des VMs et des système hote
*   **Firejail** : Outils permettant de crée des environnement isolés en sandbox
*   **Auditd**: Outils pour collecter les logs de sécurité et auditer les appels système effectués par les processus dans la VM

---

```cs
                                       +-----------------------------------+
                                       |        Interface Web              |
                                       |  (Frontend - Nuxt / Tailwinds avec     |
                                       |    intégration noVNC)             |
                                       +-----------------------------------+
                                                     |
                                                     |
                                    +-------------------------------+
                                    |           Backend             |
                                    |      (REST API, Flask,        |
                                    |      gestion de sessions)     |
                                    +-------------------------------+
                                                     |
                                                     |
                           +-------------------------------+-----------------+
                           |                                                   |
                 +---------------------+                           +---------------------+
                 |       libvirt       |                           |       KVM           |
                 |  (Gestion VM,       |                           |  (Hyperviseur,      |
                 |  snapshots,         |                           |   isolation)        |
                 |  automatisation)    |                           +---------------------+
                 +---------------------+
                           |
                           |
                +--------------------------------------------+
                |                    VM Sandbox              |
                |            (OS invité isolé avec bureau,   |
                |             VNC/Spice activé)              |
                |                                            |
                |     +-----------------------------------+  |
                |     |       Programmes de surveillance  |  |
                |     |       (strace, auditd, tcpdump,   |  |
                |     |       capture mémoire, etc.)      |  |
                |     +-----------------------------------+  |
                |                                            |
                +--------------------------------------------+
                          |
                          |
            +-----------------------------------+
            |     noVNC / SPICE pour accès web         |
            |     (streaming de l'affichage    |
            |     graphique de la VM vers      |
            |     l'interface web)             |
            +-----------------------------------+

```

---

_COURS OS_

```cs
1. Les Composants de Base d’un Ordinateur

Un ordinateur est composé de plusieurs composants matériels (hardware) essentiels qui travaillent ensemble pour exécuter des programmes et traiter des données :

    CPU (Central Processing Unit) : C'est le "cerveau" de l'ordinateur. Le CPU exécute les instructions des programmes. Il est divisé en unités de traitement qui gèrent les calculs et la logique (ALU - Arithmetic Logic Unit), les instructions de contrôle, et la gestion de la mémoire.

    RAM (Random Access Memory) : La mémoire vive stocke temporairement les données et les instructions que le CPU utilise activement. Elle est rapide, mais volatile (les données sont perdues à l'arrêt de la machine).

    Stockage (Disque dur ou SSD) : Permet de conserver des données de façon permanente. Contrairement à la RAM, le stockage ne se vide pas lorsque l'ordinateur s’éteint.

    Carte mère : Connecte tous les composants ensemble, y compris les ports pour la communication externe (USB, Ethernet, etc.).

    Bus : Ce sont des circuits internes permettant le transfert de données entre les composants. Par exemple, le bus système connecte le CPU et la mémoire, et le bus d'E/S connecte les périphériques d'entrée et de sortie au CPU et à la mémoire.

2. Le Rôle du Système d’Exploitation (OS)

Un système d'exploitation (OS) est un ensemble de logiciels qui gère les ressources matérielles et fournit des services aux applications. Il sert d'interface entre le matériel et les utilisateurs.

Les principales fonctions de l'OS sont :

    Gestion des processus : L'OS crée, planifie, et gère les processus. Un processus est une instance d'un programme en cours d'exécution. Chaque processus a son propre espace de mémoire et des ressources allouées par l'OS.

    Gestion de la mémoire : L'OS alloue la mémoire nécessaire à chaque processus et protège les processus les uns des autres pour éviter que leurs données se mélangent.

    Gestion des périphériques : L'OS contrôle les périphériques d'entrée/sortie (comme le clavier, la souris, le disque dur) et fournit une interface pour les utiliser.

    Système de fichiers : Permet de stocker et d'organiser les fichiers dans des répertoires. Les systèmes de fichiers les plus communs sur Linux sont ext4, XFS, et Btrfs.

    Sécurité et gestion des utilisateurs : L'OS gère les permissions, les comptes utilisateurs, et assure la sécurité des données et des processus.

3. Comprendre le Noyau (Kernel) : Le Cœur de l’OS

Le noyau est la partie centrale du système d'exploitation. Il se situe entre le matériel et les logiciels applicatifs. Voici les fonctionnalités principales du noyau :

    Gestion de la mémoire : Le noyau utilise une stratégie appelée mémoire virtuelle pour allouer la mémoire. Chaque processus voit une mémoire dédiée, alors qu'en réalité, cette mémoire est partagée. Cela permet de protéger les processus les uns des autres et d'optimiser l'utilisation de la RAM.

    Planificateur de processus : Le noyau décide quel processus s'exécute et quand, en fonction des ressources disponibles et de la priorité du processus. Dans Linux, plusieurs algorithmes de planification existent pour adapter l'OS à différents usages (serveurs, temps réel, etc.).

    Systèmes de fichiers : Le noyau fournit une abstraction pour les différents types de systèmes de fichiers. Il permet l'accès et la gestion des fichiers de manière uniforme, peu importe le système de fichiers sous-jacent (ext4, NTFS, etc.).

    Gestion des pilotes (drivers) : Le noyau interagit avec le matériel à l'aide de pilotes (drivers), des modules spécifiques qui traduisent les instructions du noyau en commandes compréhensibles pour chaque périphérique.

4. L'Architecture du Noyau Linux

Le noyau Linux est conçu en modules pour permettre de l'étendre ou de le réduire en fonction des besoins. Les principaux composants sont :

    Les appels système (syscalls) : Ce sont des interfaces qui permettent aux programmes de demander des services au noyau. Par exemple, les appels système permettent de lire/écrire des fichiers, de créer des processus, et de communiquer entre les processus.

    Espace utilisateur vs espace noyau : Les applications s'exécutent en espace utilisateur (user space) tandis que le noyau s'exécute en espace noyau (kernel space). Cela garantit qu'une application ne peut pas affecter directement le noyau, offrant une couche de sécurité et de stabilité.

    Modules du noyau : Le noyau peut charger ou décharger des modules à la demande. Par exemple, un pilote de carte réseau peut être chargé lorsque le périphérique est branché. Cela permet de réduire l'empreinte mémoire et de ne charger que les modules nécessaires.

    Interruption et gestion des signaux : Le noyau gère les interruptions matérielles pour assurer le bon fonctionnement des périphériques et réagit aux signaux envoyés aux processus pour les informer de certains événements (arrêt, temporisation, etc.).

5. Les Processus et la Gestion des Processus dans Linux

En Linux, un processus est une instance d'un programme en cours d'exécution. Il comporte les éléments suivants :

    PID (Process Identifier) : Un identifiant unique pour chaque processus.
    Espace mémoire propre : Chaque processus a un espace mémoire privé pour isoler les données et assurer la sécurité.
    État du processus : Un processus peut être en exécution, en attente (suspendu), ou terminé. Le planificateur du noyau décide quand et pour combien de temps un processus s'exécute.

Les processus peuvent communiquer entre eux par des pipes ou des sockets, ou partager des informations par mémoire partagée (shared memory).
6. Le Système de Fichiers sous Linux

Le système de fichiers est organisé en une structure hiérarchique. Les principaux répertoires sont :

    /root : Répertoire racine de l'OS.
    /home : Contient les répertoires personnels des utilisateurs.
    /etc : Contient les fichiers de configuration système.
    /var : Contient les fichiers à usage variable (logs, bases de données temporaires).
    /dev : Contient les fichiers de périphériques pour interagir avec le matériel.

Chaque fichier et dossier a des permissions d'accès pour définir qui peut lire, écrire, ou exécuter le fichier.
7. Conclusion et Vue d’ensemble

Pour récapituler, voici comment les différents composants s'emboîtent dans Linux :

    Le matériel (CPU, RAM, etc.) fournit la puissance de calcul et de stockage.
    Le noyau interagit directement avec le matériel et gère la mémoire, les processus, et les systèmes de fichiers.
    Les appels système permettent aux programmes de demander des services au noyau.
    L'espace utilisateur contient les applications et processus qui s'exécutent de manière isolée, avec des permissions et un accès limité au matériel.
    Le système de fichiers structure les données pour un accès facile et une gestion efficace.
```