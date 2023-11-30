// graph.hpp
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph {
public:
    Graph(int V, std::vector<std::vector<int>>& edges);
    void addEdge(int src, int dest, int weight);
    void kruskalMST();

private:
    struct Edge {
        int src, dest, weight;
    };

    struct Subset {
        int parent, rank;
    };

    int V;
    std::vector<Edge> edges;
    std::vector<Subset> subsets;

    int find(int i);
    void Union(int x, int y);
};

#endif // GRAPH_HPP
