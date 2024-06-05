#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <queue>
#include <limits>
#include <algorithm>
#include <tuple>
#include <set>
#include <string>
#include <map>
#include <utility>
#include <functional>

class Grafo{
    public:
        std::map<std::pair<size_t, size_t>, std::string> mapa;
        std::set<std::pair<size_t, size_t>> nodos;
        std::vector<std::pair< std::pair<size_t, size_t>, std::pair < size_t, size_t >>> edges;
        size_t num_linhas, num_colunas;

        void add_edges(const std::pair<size_t, size_t> &a, const std::pair<size_t, size_t> &b);
        void exibir_mapa();
        void redefinir_mapa(const std::vector<std::pair<size_t, size_t>>& menor_caminho);
};

std::shared_ptr<Grafo> createGraphFromFile(const std::string &filename);

void exibir_menor_caminho(const std::vector<std::pair<size_t, size_t>> &menor_caminho);

#endif