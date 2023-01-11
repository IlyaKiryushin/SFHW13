#include "graph.h"
int main()
{
    setlocale(LC_ALL, "");
    Graph g;
    g.addVertex("Олег");
    g.addVertex("Никита");
    g.addVertex("Настя");
    g.addVertex("Ваня");
    g.addVertex("Женя");
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    for (size_t i = 0; i < g.getVertexCount(); i++)
    {
        for (size_t j = i + 1; j < g.getVertexCount(); j++)
        {
            size_t distance = g.findMinWayDFS(i, j);
            if (distance <= 3)
                std::cout << g.findVertexIndex(i) << " знаком(а) с " << g.findVertexIndex(j) << std::endl;
        }
    }
    return 0;
}

