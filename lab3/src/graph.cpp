#include "graph.hpp"

Graph::Graph(int v) : vertices(v), adjacencyList(v) {}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyList[u].push_back(std::make_pair(v, weight));
    adjacencyList[v].push_back(std::make_pair(u, weight));
}

void Graph::dijkstra(int source, int destination) {
    std::vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    std::vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices - 1; ++i) {
        int minDist = INT_MAX, minIndex;

        for (int j = 0; j < vertices; ++j) {
            if (!visited[j] && distance[j] < minDist) {
                minDist = distance[j];
                minIndex = j;
            }
        }

        visited[minIndex] = true;

        for (const auto &neighbor : adjacencyList[minIndex]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && distance[minIndex] != INT_MAX && distance[minIndex] + weight < distance[v]) {
                distance[v] = distance[minIndex] + weight;
            }
        }
    }
    std::cout << "Найкоротший шлях від " << source << " до " << destination << " є: " << distance[destination] << std::endl;
}
