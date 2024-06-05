#ifndef GRAFO_H
#define GRAFO_H

#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

class Grafo {
 public:
  std::map<std::pair<size_t, size_t>, std::string> mapa;
  std::set<std::pair<size_t, size_t>> nodos;
  std::vector<std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>>>
      edges;
  size_t num_linhas, num_colunas;

  void add_edges(const std::pair<size_t, size_t> &a,
                 const std::pair<size_t, size_t> &b);
  void exibir_mapa();
  void exibir_edges();
  void redefinir_mapa(
      const std::vector<std::pair<size_t, size_t>> &menor_caminho);

  std::vector<std::pair<size_t, size_t>> estrela(
      const std::pair<size_t, size_t> &origem,
      const std::pair<size_t, size_t> &destino);

 private:
  std::vector<std::pair<size_t, size_t>> vizinhos(
      const std::pair<size_t, size_t> &a);
  size_t distancia(const std::pair<size_t, size_t> &a,
                   const std::pair<size_t, size_t> &b);
  //   std::vector<std::pair<size_t, size_t>> ordernar(
  //       const std::vector<std::pair<size_t, size_t>> &vetor,
  //       const std::pair<size_t, size_t> &destino);
};

std::shared_ptr<Grafo> createGraphFromFile(const std::string &filename);

void exibir_menor_caminho(
    const std::vector<std::pair<size_t, size_t>> &menor_caminho);

#endif