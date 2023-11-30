/* 
    * Завдання. 
    * Написати програму, що знаходить найкоротший шлях між за-
    * даними вершинами за допомогою алгоритму Дейкстри на мові програмування
    * С++. Вхідні дані: це можуть бути – кількість вершин графа, матриця ваг, або
    * список ребер з вагами графа, та імена вершин, для яких треба визначити найко-
    * ротший шлях, що зчитуються з текстового файлу. Вихідні дані – перелік дуг,
    * які складають найкоротший шлях, та вага отриманого шляху. '
*/

#include "graph.cpp"

int main() {
    std::ifstream inputFile("../graph_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    int vertices;
    inputFile >> vertices;

    Graph graph(vertices);

    int edges;
    inputFile >> edges;

    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        inputFile >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    int source, destination;
    inputFile >> source >> destination;

    inputFile.close();

    graph.dijkstra(source, destination);

    return 0;
}
