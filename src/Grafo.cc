#include "Grafo.hpp"

void Grafo::add_edges(const std::pair<size_t, size_t> &a, const std::pair<size_t, size_t> &b)
{
    std::pair<std::pair<size_t, size_t>, std::pair<size_t, size_t>> aresta = std::make_pair(a, b);
    edges.push_back(aresta);
}

std::shared_ptr<Grafo> createGraphFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    std::shared_ptr<Grafo> graph(new Grafo());
    graph->num_linhas = lines.size();
    graph->num_colunas = lines[0].size();

    for (size_t i = 0; i < lines.size(); i++)
    {
        for (size_t j = 0; j < lines[i].size(); j++)
        {
            size_t v1 = i;
            size_t v2 = j;
            std::pair<size_t, size_t> nodo = {v1, v2};
            graph->nodos.insert(nodo);

            switch (lines[i][j])
            {
                case '0':{

                
                graph->mapa[nodo] = "0";

                if (i > 0 && lines[i - 1][j] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1 - 1, v2));
                }
                if (i > 0 && j > 0 && lines[i - 1][j - 1] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1 - 1, v2 - 1));
                }
                if (i > 0 && j < lines[i].size() - 1 && lines[i - 1][j + 1] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1 - 1, v2 + 1));
                }
                if (j > 0 && lines[i][j - 1] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1, v2 - 1));
                }
                if (i < lines.size() - 1 && j > 0 && lines[i + 1][j - 1] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1 + 1, v2 - 1));
                }
                if (i < lines.size() - 1 && lines[i + 1][j] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1 + 1, v2));
                }
                if (i < lines.size() - 1 && j < lines[i].size() - 1 && lines[i + 1][j + 1] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1 + 1, v2 + 1));
                }
                if (j < lines[i].size() - 1 && lines[i][j + 1] == '0')
                {
                    graph->add_edges(nodo, std::make_pair(v1, v2 + 1));
                }
                }
                break;
                case '1':{
                    graph->mapa[nodo] = "1";
                }
                break;
            }
        }
        std::cout << std::endl;
    }

    return graph;
}

void Grafo::exibir_mapa(){
    for(size_t i{}; i < num_linhas; i++){
        for(size_t j{}; j < num_colunas; j++){
            std::cout << mapa[{i, j}];
        }
        std::cout << std::endl;
    }
}