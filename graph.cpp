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


int main()
{
    Graph g(6,true);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,9);
    g.addEdge(3,4,2);
    g.addEdge(4,5,1);

    g.printGraph();
}