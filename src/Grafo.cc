#include "Grafo.hpp"

void Grafo::add_edges(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    std::pair<std::pair<int, int>, std::pair<int, int>> aresta = std::make_pair(a, b);
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

    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            int v1 = i;
            int v2 = j;
            std::pair<int, int> nodo = std::make_pair(v1, v2);
            graph->nodos.insert(nodo);

            if (lines[i][j] == '0')
            {
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
            else if (lines[i][j] == '1')
            {
                graph->mapa[nodo] = "1";
            }
        }
    }

    return graph;
}