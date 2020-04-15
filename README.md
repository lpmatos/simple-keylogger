<h1 align="center">
    <img alt="Keylogger" title="#keylogger" src="https://image.flaticon.com/icons/png/512/869/869418.png" width="175px" />
</h1>

<h4 align="center">
  Simple Keylogger - Version 1.0
</h4>

<p align="center">
  <a href="https://github.com/lpmatos/simple-keylogger">
    <img alt="Open Source" src="https://badges.frapsoft.com/os/v1/open-source.svg?v=102">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger/graphs/contributors">
    <img alt="GitHub Contributors" src="https://img.shields.io/github/contributors/lpmatos/simple-keylogger">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger">
    <img alt="GitHub Language Count" src="https://img.shields.io/github/languages/count/lpmatos/simple-keylogger">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger">
    <img alt="GitHub Top Language" src="https://img.shields.io/github/languages/top/lpmatos/simple-keylogger">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger/stargazers">
    <img alt="GitHub Stars" src="https://img.shields.io/github/stars/lpmatos/simple-keylogger?style=social">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger/commits/master">
    <img alt="GitHub Last Commit" src="https://img.shields.io/github/last-commit/lpmatos/simple-keylogger">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger">
    <img alt="Repository Size" src="https://img.shields.io/github/repo-size/lpmatos/simple-keylogger">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger/issues">
    <img alt="Repository Issues" src="https://img.shields.io/github/issues/lpmatos/semana-simple-keylogger">
  </a>
  <a href="https://github.com/lpmatos/simple-keylogger/blob/master/LICENSE">
    <img alt="MIT License" src="https://img.shields.io/github/license/lpmatos/simple-keylogger">
  </a>
</p>

<p align="center">
  <img alt="description" src="https://media1.giphy.com/media/UqxVRm1IaaIGk/source.gif" float="center"/>
</p>

<h1 align="center">🔒 Windows and Linux Keylogger 🔒</h1>

<p align="center">
  <strong>Building a Keylogger write in C Language and Docker and Docker-Compose support</strong>
</p>

<p align="center">
  <a href="#keylogger">What is Keylogger</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#how-to-contribute">How to contribute</a>&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#license">License</a>
</p>

## Getting Started

To use this repository you need **git clone**:

```bash
git clone --depth 1 https://github.com/lpmatos/omnistack.git -b master
```

This will give access of the project on your local machine.

## ☕ Buy me a coffee

Pull requests are welcome. If you'd like to support the work and buy me a ☕, I greatly appreciate it!

<a href="https://www.buymeacoffee.com/EatdMck" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 100px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>

## Pre Requisites

To this project you yeed:

- Windows or Linux System.
- Gcc to compile the code.
- Docker and Docker Compose to support in your tests and development.

## Built with

This project was developed with:

* Dev Tools

  - [C](https://www.geeksforgeeks.org/c-language-set-1-introduction/)
  - [Docker](https://docs.docker.com/)
  - [Docker Compose](https://docs.docker.com/compose/)

## Description

Neste projeto a minha inteção principal é construir um simples Keylogger que funcione tanto para sistemas operacionais Windows, quanto para sistemas operacionais Linux. Existem vários formas de se construir um Keylogger, porém a forma abordada neste projeto procura ser a mais simples possível, uma vez que não passa de um simples projeto de estudo.

Para podemos dentro do código saber em qual contexto de sistema operacional nós estamos, utilizamos macros de validação. Caso você queira saber um pouco mais sobre o que são macros em C, eu preparei um breve resumo sobre isso. Basta acessar [aqui](/docs/study/macros.md).

Um outro detalhe importante sobre este projeto é que estamos utilizando uma library externa de log. Para mais detalhes sobre ela, acesse [aqui](https://github.com/rxi/log.c).

## Keylogger

A keylogger (short for keystroke logger) is software that tracks or logs the keys struck on your keyboard, typically in a covert manner so that you don’t know that your actions are being monitored. This is usually done with malicious intent to collect your account information, credit card numbers, user names, passwords, and other private data.

Keystroke logging is an act of tracking and recording every keystroke entry made on a computer, often without the permission or knowledge of the user. A keylogger may be either hardware- or software-based, and has its uses as a legitimate personal or professional IT monitoring tool. However, keystroke logging can also be used for criminal purposes. More commonly, keystroke logging is malicious spyware that is used to capture sensitive information, like passwords or financial information, which is then sent to third parties for criminal exploitation.

Keylogger malware may reside in the computer operating system, at the keyboard API level, in memory or at the kernel level itself. Keylogging can be hard to detect because it doesn't always cause noticeable computer problems, like slow processes or glitches. It can be hard to detect even by some antivirus programs because spyware is good at hiding itself — it often appears as normal files or traffic, and can also potentially reinstall itself.

## 🐋 Development with Docker

Steps to build the Docker Image.

### Build

```bash
docker image build -t <IMAGE_NAME> -f <PATH_DOCKERFILE> <PATH_CONTEXT_DOCKERFILE>
docker image build -t <IMAGE_NAME> . (This context)
```

### Run

Steps to run the Docker Container.

* **Linux** running:

```bash
docker container run -d -p <LOCAL_PORT:CONTAINER_PORT> <IMAGE_NAME> <COMMAND>
docker container run -it --rm --name <CONTAINER_NAME> -p <LOCAL_PORT:CONTAINER_PORT> <IMAGE_NAME> <COMMAND>
```

* **Windows** running:

```
winpty docker.exe container run -it --rm <IMAGE_NAME> <COMMAND>
```

For more information, access the [Docker](https://docs.docker.com/) documentation or [this](docs/annotations/docker.md).

## 🐋 Development with Docker Compose

Build and run a docker-compose.

```bash
docker-compose up --build
```

Down all services deployed by docker-compose.

```bash
docker-compose down
```

Down all services and delete all images.

```bash
docker-compose down --rmi all
```

## 📆 Pomodoro Tasks

- [x] Add Windows support.
- [x] Add logger support and some system validations.
- [x] Add Makefile with Docker and Docker Compose commands support.
- [] Add Linux support.
- [] Validate Docker and Docker Compose.

## 🎒 How to contribute

1. Make a **Fork**.
2. Follow the project organization.
3. Add the file to the appropriate level folder - If the folder does not exist, create according to the standard.
4. Make the **Commit**.
5. Open a **Pull Request**.
6. Wait for your pull request to be accepted.. 🚀

Remember: There is no bad code, there are different views/versions of solving the same problem. 😊

## 🔔 Add to git and push

You must send the project to your GitHub after the modifications

```bash
git add -f .
git commit -m "Added - Fixing somethings"
git push origin master
```

## 📋 Versioning

- [CHANGELOG](CHANGELOG.md)

## 📜 License

Distributed under the MIT License. See [LICENSE](LICENSE) for more information.

## ☎️ Contacts

Hey!! If you like this project or if you find some bugs feel free to contact me in my channels:

* **Email**: luccapsm@gmail.com
* **Linkedin**: www.linkedin.com/in/lucca-pessoa-4abb71138/

[![Facebook](https://github.frapsoft.com/social/facebook.png)](https://www.facebook.com/lucca.pessoa.9)
[![Github](https://github.frapsoft.com/social/github.png)](https://github.com/lpmatos)

## ✨ Contributors

<table>
  <tr>
    <td align="center"><a href="https://github.com/lpmatos"><img src="https://avatars2.githubusercontent.com/u/58797390?s=400&v=4" width="100px;" alt=""/><br /><sub><b>Lucca Pessoa</b></sub></a><br /><a href="https://github.com/lpmatos/simple-keylogger/commits?author=lpmatos" title="Code">💻</a></a></td>
  <tr>
</table>

## 🐯 Autor

<table>
  <tr>
    <td align="center"><a href="https://github.com/lpmatos"><img src="https://avatars2.githubusercontent.com/u/58797390?s=400&v=4" width="100px;" alt=""/><br /><sub><b>Lucca Pessoa</b></sub></a><br /><a href="https://github.com/lpmatos/simple-keylogger/commits?author=lpmatos" title="Code">💻</a> <a href="https://github.com/lpmatos/simple-keylogger/commits?author=lpmatos" title="Design">🎨</a></td>
  <tr>
</table>

## Project Status

* 🔛 In production

---

<p align="center">Feito com ❤️ by <strong>Lucca Pessoa :wave:</p>
