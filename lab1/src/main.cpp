/* 
    *   Завдання. 
    *   Написати програму, що знаходить мінімальне остовне дерево
    *   за допомогою алгоритму Краскала на мові програмування С++. Вхідні дані: це
    *   можуть бути – кількість вершин графа, матриця ваг, або список ребер з вагами
    *   графа, які зчитуються з текстового файлу. Вихідні дані – перелік ребер, які
    *   складають мінімальне остовне дерево, та вага дерева.
*/

#include "graph.cpp"
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream input("../graph_input.txt");
    if (!input.is_open()) {
        std::cerr << "Не вдалося відкрити файл." << '\n';
        return 1;
    }

    int V;
    input >> V;

    std::vector<std::vector<int>> edgesData;
    int src, dest, weight;
    while (input >> src >> dest >> weight) {
        edgesData.push_back({src, dest, weight});
    }

    input.close();

    Graph graph(V, edgesData);
    graph.kruskalMST();

    return 0;
}
