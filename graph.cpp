#include "graph.h"

void Graph::printGraph()
{

    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            std::cout<<adjMatrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
} 


void Graph::addEdge(int u, int v, int w)
{
    adjMatrix[u][v] = w;
    if(!isdirected)
    {
        adjMatrix[v][u] = w;
    }
}
