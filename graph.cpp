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


    void printGraph()
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


    void addEdge(int u, int v, int w)
    {
        adjMatrix[u][v] = w;
        if(!isdirected)
        {
            adjMatrix[v][u] = w;
        }
    }


};


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