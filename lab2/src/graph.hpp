// graph.hpp
#pragma once

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
