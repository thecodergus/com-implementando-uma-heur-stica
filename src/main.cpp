#include <iostream>

#include "grafo.hpp"

int main() {
  auto grafo = createGraphFromFile("../mapa01.txt");

  //   auto menor_caminho = grafo->estrela({1, 1}, {})

  // grafo->exibir_edges();

  // exibir_menor_caminho(menor_caminho);

  // grafo->redefinir_mapa();

  grafo->exibir_mapa();

  return 0;
}