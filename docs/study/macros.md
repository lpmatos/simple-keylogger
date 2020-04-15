# Macros

Macros sao recursos de pre-processamento, que permite criar estruturas para serem substituidas antes do codigo ser devidamente compilado.

Em C++ as Macros nao sao bem vista, pos nao oferecem seguranca de tipos, nao respeitam escopo e podem dificultar o entendimento de um escopo do codigo.

Analisando de uma forma mais simples, Macros sao basicamente substituicoes de strings. Macros sao tratadas (expandidas) pelo pre-processador e criadas atraves da diretiva #define.

Macros sao de dois principais tipos:

* Objeto: Normalmente utilizado para dar nome a constantes.
* Funcao: Define uma função inline.

Declarar funcoes simples atraves de Macros podem otimizar o tempo de processamento, ja que evita o custo da chamada de uma funcao.
