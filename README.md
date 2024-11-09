# Sandbox d'Analyse de Fichiers Suspects

Bienvenue dans le projet **IsoGuard**, un outil conçu pour analyser des fichiers potentiellement malveillants dans un environnement entièrement isolé. Cette sandbox permet de détecter les comportements malveillants des fichiers sans exposer le système hôte à des risques, offrant ainsi une solution sécurisée pour l'analyse de sécurité.

## Table des matières

*   [Description du projet](#description-du-projet)
*   [Fonctionnalités](#fonctionnalit%C3%A9s)
*   [Installation](#installation)
*   [Configuration](#configuration)
*   [Utilisation](#utilisation)
*   [Contribuer](#contribuer)
*   [Licence](#licence)

---

## Description du projet

Ce projet de sandbox est conçu pour l'analyse et l'isolation de fichiers suspects en utilisant un environnement de virtualisation sécurisé. IsoGuard prend en charge plusieurs types de fichiers et offre une visibilité complète sur les comportements potentiellement dangereux en capturant les interactions système. L'objectif est de fournir aux professionnels de la cybersécurité ou pas un outils d'analyse sécurisé, rapide et extensible.

## Fonctionnalités

*   **Isolation totale** : Les fichiers sont exécutés dans un environnement isolé, sans impact sur le système hôte.
*   **Détection de comportements malveillants** : Analyse des interactions du fichier avec le système, telles que l'accès au réseau, la manipulation des fichiers, etc.
*   **Rapports d'analyse détaillés** : Génération de rapports exhaustifs incluant les logs d'événements, les appels système et les comportements suspects.
*   **Prise en charge de différents types de fichiers** : Analyse de fichiers exécutables, documents et scripts.
*   **Interface utilisateur intuitive** : Interface pour charger et gérer les fichiers, visualiser les résultats d'analyse et télécharger les rapports.

## Prérequis

*   Système d'exploitation : **Linux** (recommandé) ou **Windows**
*   [Docker](https://www.docker.com/) (pour exécuter l'environnement sandboxé)
*   **Python 3.8+**

## Installation