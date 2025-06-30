#pragma once
#include <iostream>
#include <vector>

class Graph
{
    public:
    int vertices;
    bool isdirected;
    std::vector<std::vector<int>> adjMatrix;

    Graph(int nVertices, bool directed) : vertices(nVertices), isdirected(directed)
    {
        for(int i=0;i<nVertices;i++)
        {
            adjMatrix.push_back(std::vector<int>(nVertices,0)); 
        }
    }

    void printGraph();
    void addEdge(int u, int v, int w);

};
