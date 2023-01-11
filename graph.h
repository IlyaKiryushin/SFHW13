#pragma once
#include<iostream>
#define SIZE 10
class Graph
{
public:
	Graph(); 
	void addVertex(std::string _name);
	void addEdge(int v1, int v2);
	size_t findMinWayDFS(int v1, int v2);
	size_t findVertexname(const std::string name);
	std::string findVertexIndex(int index);
	size_t getVertexCount() const;
	void inner(int current, int to, bool visited[], int& min, int currentDistance);
	void findMinDistancesFloyd();
private:
	struct vertex
	{
		std::string name;
	};
	bool vertexExists(std::string _name);
	bool edgeExists(int v1, int v2);
	size_t matrix[SIZE][SIZE]; 
	vertex vertexes[SIZE]; 
	size_t vertexCount;
};
