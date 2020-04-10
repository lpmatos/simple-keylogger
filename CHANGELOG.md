# CHANGELOG

All important changes to this project will be added to this file! This changelog will be based on [Keep a change log](http://keepachangelog.com/)

## 1.0.0 - [9-04-201]

* Criando funções de:
  * void helper();
  * void cabecalho();
  * void set_portuguese();
  * FILE *create_file();
  * FILE *check_file_exist();
  * bool check_file_pointer_exist();
  * int keylogger()
* Validações para verificar se o arquivo de Log existe e caso não exista, cria o mesmo.
* Criando estrutura básica do projecto com README e CHANGELOG.
* Aplicando Dockerfile com Multiplos Estágios.
* Criando docker-compose com a estratégias .env para receber variáveis de ambiente.
* Makefile para automatizar tarefas do Dockerfile e do docker-compose.
* Criando logger em C.
