/* 
    *   Завдання. 
    *   Написати програму, що знаходить мінімальне остовне дерево
    *   за допомогою алгоритму Прима на мові програмування С++. Вхідні дані: це
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
        std::cerr << "Не вдалося відкрити файл.\n";
        return 1;
    }

    int V;
    input >> V;

    std::vector<std::vector<int>> edges(V, std::vector<int>(V, 0));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            input >> edges[i][j];
        }
    }

    input.close();

    Graph graph(V, edges);
    graph.primMST();

    return 0;
}
