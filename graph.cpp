#include"graph.h"
#define VERYBIGINT 1000000000
Graph::Graph() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    }
    vertexCount = 1;
}
void Graph::addVertex(const std::string name)
{
    vertexes[vertexCount].name = name;
    vertexCount++;
}
void Graph::addEdge(int v1, int v2)
{
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
bool Graph::vertexExists(const std::string name)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i].name == name)
            return true;
    }
    return false;
}
size_t Graph::findVertexname(const std::string name)
{
    for (size_t i = 0; i < vertexCount; i++)
    {
        if (vertexes[i].name == name)
            return i;
    }
    return -1;
}
std::string Graph::findVertexIndex(int index)
{
    return vertexes[index].name;
}
size_t Graph::findMinWayDFS(int from, int to) 
{
    bool visited[SIZE]; 
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    int min = VERYBIGINT; 
    int currentDistance = 0;
    inner(from, to, visited, min, currentDistance);
    return min;
}
void Graph::inner(int current, int to, bool visited[], int& min, int currentDistance)
{
    if (current == to)
    {
        if (min > currentDistance)
        {
            min = currentDistance;
        }
        return;
    }
    visited[current] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
        {
            int newDist = currentDistance + matrix[current][i];
            inner(i, to, visited, min, newDist);
        }
    }
    visited[current] = false;
}
size_t Graph::getVertexCount() const
{
    return vertexCount;
}
