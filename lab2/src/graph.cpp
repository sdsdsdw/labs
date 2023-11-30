#include "graph.hpp"

Graph::Graph(int V, std::vector<std::vector<int>>& edges) : V(V) {
    graph = edges;
}

void Graph::primMST() {
    std::vector<int> parent(V, -1);
    std::vector<int> key(V, INT_MAX);
    std::vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    std::cout << "Мінімальне остовне дерево за алгоритмом Прима:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; ++i) {
        std::cout << "Ребро " << parent[i] << " -- " << i << " вагою " << graph[i][parent[i]] << std::endl;
        totalWeight += graph[i][parent[i]];
    }
    std::cout << "Загальна вага дерева: " << totalWeight << std::endl;
}
