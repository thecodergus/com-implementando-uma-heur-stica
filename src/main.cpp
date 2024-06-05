#include <iostream>

#include "grafo.hpp"

int main() {
  auto grafo = createGraphFromFile("../mapa01.txt");

  auto menor_caminho = grafo->estrela({1, 1}, {22, 49});

  grafo->exibir_mapa();

  exibir_menor_caminho(menor_caminho);

  grafo->redefinir_mapa(menor_caminho);

  grafo->exibir_mapa();

  return 0;
}