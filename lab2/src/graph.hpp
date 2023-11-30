// graph.hpp
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <climits>

class Graph {
public:
    Graph(int V, std::vector<std::vector<int>>& edges);
    void primMST();

private:
    int V;
    std::vector<std::vector<int>> graph;
};

#endif // GRAPH_H