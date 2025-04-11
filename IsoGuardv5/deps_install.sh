#!/bin/bash

set -e

echo "Mise à jour du système..."
sudo apt-get update -y && sudo apt-get upgrade -y

echo "Installation des outils de compilation..."
sudo apt-get install -y build-essential cmake pkg-config
echo "Installation des bibliothèques nécessaires..."
sudo apt-get install -y libvirt-dev libxml2-dev
echo "Installation des dépendances réseau (curl)..."
sudo apt-get install -y curl

echo "Vérification des versions installées:"
echo -n "g++ version: "; g++ --version | head -n1
echo -n "libvirt version: "; pkg-config --modversion libvirt
echo -n "libxml2 version: "; pkg-config --modversion libxml-2.0
echo "Dépendances installées avec succès."
