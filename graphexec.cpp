#include "graph.h"

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