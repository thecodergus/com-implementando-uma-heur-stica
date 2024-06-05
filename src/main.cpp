#include <iostream>

#include "Grafo.hpp"

int main(){

    auto grafo = createGraphFromFile("../mapa01.txt");
    auto menor_caminho = grafo->a_star({1, 1}, {23, 51});

    exibir_menor_caminho(menor_caminho);

    // grafo->redefinir_mapa();

    // grafo->exibir_mapa();

    return 0;
}