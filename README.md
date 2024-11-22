<h1 align="center">
  <img src="assets/logo.png" alt="Logo de la Sandbox" width="200">
  <br>
  IsoGuard
</h1>

<h4 align="center" style="color: purple;">SANDBOX PROJECT </h4>

<h3 align="center"> Table of content</h4>

<p align="center">
    <a href="#description">1. Description</a>
    <br/>
    <a href="#technology">2. Technology</a>
    <br/>
    <a href="#requirements">3. Requirements</a>
    <br/>
    <a href="#features">4. Features</a>
    <br/>
    <a href="#download">5. Download</a>
    <br/>
    <a href="#start-project">6. Start project</a>
</p>



## Description

* This sandbox project is designed for analysis and isolation of suspicious files using a secure virtualization environment. The tool supports multiple file types and provides complete visibility into potentially harmful behavior by capturing system interactions. The goal is to provide cybersecurity professionals and researchers with a secure, fast and 
extensible analysis space.

## 💻 Technology

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)


## ⚠️ Requirements

[Docker](https://www.docker.com/)

sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients build-essential

sudo apt install libvirt-dev libcapstone-dev

## Features


*   **Total insulation :** The files are executed in an isolated environment, with no impact on the host system.
*   **Detection of malicious behavior :**  Analysis of the file's interactions with the system, such as network access, file manipulation, etc.
*   **Detailed analysis reports :** Generate comprehensive reports including event logs, system calls and suspicious behavior.

* **Support for different file types** : Analysis of executable files, documents and scripts.
*   **Intuitive user interface :** Interface to upload and manage files, view analysis results and download reports.



> **Note**  
> If you're using Linux Bash for Windows, [see this guide](https://www.howtogeek.com/261575/how-to-run-graphical-linux-desktop-applications-from-windows-10s-bash-shell/) or use `node` from the command prompt.


## Download

```
# Clone this repository
$ git clone https://github.com/raphaeldemonchy/IsoGuard.git

# Go into the repository
$ cd IsoGuard

# Install dependencies
$ npm install

# Run the app
$ npm start
```


## Start Project

WIP

## Teams



*   [Lev](http://electron.atom.io/)
*   [Viu](https://nodejs.org/)
*   [Ben](https://github.com/chjj/marked)
*   [Raphael](http://showdownjs.github.io/showdown/)




## License

MIT

