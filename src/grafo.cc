#include "grafo.hpp"

void Grafo::add_edges(const std::pair<size_t, size_t>& a,
                      const std::pair<size_t, size_t>& b) {
  std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>> aresta =
      std::make_pair(a, b);
  edges.push_back(aresta);
}

std::shared_ptr<Grafo> createGraphFromFile(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  std::vector<std::string> lines;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }

  std::shared_ptr<Grafo> graph(new Grafo());
  graph->num_linhas = lines.size();
  graph->num_colunas = lines[0].size();

  for (size_t i = 0; i < lines.size(); i++) {
    for (size_t j = 0; j < lines[i].size(); j++) {
      size_t v1 = i;
      size_t v2 = j;
      std::pair<size_t, size_t> nodo = {v1, v2};
      graph->nodos.insert(nodo);

      switch (lines[i][j]) {
        case '0': {
          graph->mapa[nodo] = "0";

          if (i > 0 && lines[i - 1][j] == '0') {
            graph->add_edges(nodo, std::make_pair(v1 - 1, v2));
          }
          if (i > 0 && j > 0 && lines[i - 1][j - 1] == '0') {
            graph->add_edges(nodo, std::make_pair(v1 - 1, v2 - 1));
          }
          if (i > 0 && j < lines[i].size() - 1 && lines[i - 1][j + 1] == '0') {
            graph->add_edges(nodo, std::make_pair(v1 - 1, v2 + 1));
          }
          if (j > 0 && lines[i][j - 1] == '0') {
            graph->add_edges(nodo, std::make_pair(v1, v2 - 1));
          }
          if (i < lines.size() - 1 && j > 0 && lines[i + 1][j - 1] == '0') {
            graph->add_edges(nodo, std::make_pair(v1 + 1, v2 - 1));
          }
          if (i < lines.size() - 1 && lines[i + 1][j] == '0') {
            graph->add_edges(nodo, std::make_pair(v1 + 1, v2));
          }
          if (i < lines.size() - 1 && j < lines[i].size() - 1 &&
              lines[i + 1][j + 1] == '0') {
            graph->add_edges(nodo, std::make_pair(v1 + 1, v2 + 1));
          }
          if (j < lines[i].size() - 1 && lines[i][j + 1] == '0') {
            graph->add_edges(nodo, std::make_pair(v1, v2 + 1));
          }
        } break;
        case '1': {
          graph->mapa[nodo] = "1";
        } break;
      }
    }
    std::cout << std::endl;
  }

  return graph;
}

void Grafo::exibir_mapa() {
  std::cout << "Numero de linhas: " << num_linhas << std::endl;
  std::cout << "Numero de colunas: " << num_colunas << std::endl;
  for (size_t i{}; i < num_linhas; i++) {
    for (size_t j{}; j < num_colunas; j++) {
      std::cout << mapa[{i, j}];
    }
    std::cout << std::endl;
  }
}

void Grafo::redefinir_mapa(
    const std::vector<std::pair<size_t, size_t>>& menor_caminho) {
  for (auto& pair : mapa) {
    pair.second = "#";
  }

  for (auto& passo : menor_caminho) {
    mapa[passo] = "¤";
  }
}

void exibir_menor_caminho(
    const std::vector<std::pair<size_t, size_t>>& menor_caminho) {
  std::cout << "Tamanho do caminho: " << menor_caminho.size() << std::endl;
  for (auto a : menor_caminho) {
    std::cout << "<" << a.first << ", " << a.second << ">, ";
  }
  std::cout << std::endl;
}

std::vector<std::pair<size_t, size_t>> Grafo::estrela(
    const std::pair<size_t, size_t>& origem,
    const std::pair<size_t, size_t>& destino) {
  std::vector<std::pair<size_t, size_t>> paraVisitar = {origem};
  std::vector<std::pair<size_t, size_t>> visitados;
  std::vector<std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>>>
      pais;
  std::map<std::pair<size_t, size_t>, size_t> custos = {
      {origem, distancia(origem, destino)}};
  // f = g + h, g = valor do custo acumulado até o
  // momento; h = valor do custo restante; f = custo
  // total

  while (!paraVisitar.empty()) {
    // paraVisitar = ordernar(paraVisitar, destino);

    std::pair<size_t, size_t> nodo_atual = paraVisitar.back();
    paraVisitar.pop_back();
    visitados.push_back(nodo_atual);

    if (nodo_atual == destino) {
      std::vector<std::pair<size_t, size_t>> caminho{destino};

      while (nodo_atual != origem) {
        for (auto& a : pais) {
          if (a.second == nodo_atual) {
            nodo_atual = a.first;
            caminho.push_back(nodo_atual);
            break;
          }
        }
      }

      std::reverse(caminho.begin(), caminho.end());

      return caminho;
    }

    std::vector<std::pair<size_t, size_t>> vizinhos{
        this->vizinhos(nodo_atual)};  // Procura pelos visinhos do nó atual
    vizinhos.erase(
        std::remove_if(vizinhos.begin(), vizinhos.end(),
                       [&visitados](const std::pair<size_t, size_t>& item) {
                         return std::find(visitados.begin(), visitados.end(),
                                          item) != visitados.end();
                       }),
        vizinhos.end());  // Remove os itens já visitados
    // vizinhos = ordernar(vizinhos, destino);

    for (auto& vizinho : vizinhos) {
      paraVisitar.push_back(vizinho);

      size_t custo_aux{distancia(vizinho, destino)};

      if (custos[nodo_atual] > custo_aux) {
        custos[vizinho] = custo_aux;
        pais.push_back({nodo_atual, vizinho});
      }
    }
  }

  return {};
}

std::vector<std::pair<size_t, size_t>> Grafo::vizinhos(
    const std::pair<size_t, size_t>& a) {
  std::vector<std::pair<size_t, size_t>> resultado;

  for (auto& item : edges) {
    if (item.first == a) {
      resultado.push_back(item.second);
    }
  }

  return {resultado};
}

void Grafo::exibir_edges() {
  for (auto& item : edges) {
    std::cout << "<" << item.first.first << ", " << item.first.second
              << "> -> <" << item.second.first << ", " << item.second.second
              << ">" << std::endl;
  }
}

size_t Grafo::distancia(const std::pair<size_t, size_t>& a,
                        const std::pair<size_t, size_t>& b) {
  return std::max(abs(a.first - b.first), abs(a.second - b.second));
}

// std::vector<std::pair<size_t, size_t>> ordernar(
//     const std::vector<std::pair<size_t, size_t>>& vetor,
//     const std::pair<size_t, size_t>& destino) {
//   std::sort(vetor.begin(), vetor.end(), [&destino](auto a, auto b) {
//     return distancia(a, destino) > distancia(b, destino);
//   });

//   return vetor;
// }