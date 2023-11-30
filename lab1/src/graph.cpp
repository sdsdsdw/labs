#include "graph.hpp"

Graph::Graph(int V, std::vector<std::vector<int>>& edges) : V(V) {
    for (const auto& edge : edges) {
        addEdge(edge[0], edge[1], edge[2]);
    }

    subsets.resize(V);
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge edge = {src, dest, weight};
    edges.push_back(edge);
}

int Graph::find(int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets[i].parent);
    }
    return subsets[i].parent;
}

void Graph::Union(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } 
    else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    std::vector<Edge> result;
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];
        int x = find(next_edge.src);
        int y = find(next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(x, y);
            e++;
        }
    }

    std::cout << "Мінімальне остовне дерево за алгоритмом Краскала:\n";
    int totalWeight = 0;
    for (Edge edge : result) {
        std::cout << edge.src << " -- " << edge.dest << " вагою " << edge.weight << std::endl;
        totalWeight += edge.weight;
    }
    std::cout << "Загальна вага дерева: " << totalWeight << std::endl;
}
