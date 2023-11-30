// graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <fstream>

class Graph {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    Graph(int v);
    void addEdge(int u, int v, int weight);
    void dijkstra(int source, int destination);
};

#endif // GRAPH_HPP