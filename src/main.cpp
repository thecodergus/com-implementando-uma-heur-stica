#include <iostream>

#include "Grafo.hpp"

int main(){

    auto grafo = createGraphFromFile("../mapa01.txt");


    std::cout << "Linhas: " << grafo->num_linhas << std::endl;
    std::cout << "Colunas: " << grafo->num_colunas << std::endl;
    grafo->exibir_mapa();

    return 0;
}