# Algoritmo de Busca A* em C++ 20

Este código implementa o algoritmo de busca A* para encontrar o menor caminho em um grafo representado por um mapa lido de um arquivo de texto.

## Classe Grafo

A classe `Grafo` é utilizada para representar o grafo e contém os seguintes métodos:

- `add_edges`: adiciona arestas ao grafo.
- `exibir_mapa`: exibe o mapa do grafo.
- `exibir_edges`: exibe as arestas do grafo.
- `exibir_nodos`: exibe os nós do grafo.
- `redefinir_mapa`: redefine o mapa com base no menor caminho encontrado.
- `estrela`: implementa o algoritmo de busca A\*.

Além disso, a classe utiliza estruturas de dados como `std::map`, `std::set`, `std::vector` e `std::pair` para armazenar e manipular o grafo.

## Funções adicionais

- `createGraphFromFile`: lê um arquivo de texto e cria um grafo com base nas informações do arquivo. O arquivo deve conter apenas os caracteres '0' e '1', onde '0' representa um nó passível e '1' um obstáculo.
- `exibir_menor_caminho`: exibe o menor caminho encontrado pelo algoritmo A\*.

## Programa principal

No programa principal, um grafo é criado a partir de um arquivo de texto, o menor caminho é encontrado e exibido, o mapa é redefinido com base no menor caminho e o novo mapa é exibido.

## Requisitos

- Compilador C++ 20 compatível (g++ ou clang++).

## Como compilar e executar

1. Salve o código em um arquivo `main.cpp`.
2. Execute `bash run.sh` no terminal.
