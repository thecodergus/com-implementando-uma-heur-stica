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
        std::map<std::pair<int, int>, std::string> mapa;
        std::set<std::pair<int, int>> nodos;
        std::vector<std::pair< std::pair<int, int>, std::pair < int, int >>> edges;

        void Grafo::add_edges(const std::pair<int, int> &a, const std::pair<int, int> &b);
};

std::shared_ptr<Grafo> createGraphFromFile(const std::string &filename);

#endif