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

class Grafo{
    public:
        std::map<std::pair<size_t, size_t>, std::string> mapa;
        std::set<std::pair<size_t, size_t>> nodos;
        std::vector<std::pair< std::pair<size_t, size_t>, std::pair < size_t, size_t >>> edges;
        size_t num_linhas, num_colunas;

        void add_edges(const std::pair<size_t, size_t> &a, const std::pair<size_t, size_t> &b);
        void exibir_mapa();
};

std::shared_ptr<Grafo> createGraphFromFile(const std::string &filename);

#endif