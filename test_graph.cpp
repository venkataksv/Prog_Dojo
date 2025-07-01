
#include <gtest/gtest.h>
#include <sstream>

#include "graph.h"


TEST(GraphTests, testAddEdge)
{
    // declare a undirected graph
    // Add a edge between 1&2
    Graph G(5,false);
    G.addEdge(1,2,3);
 
    ASSERT_EQ(G.adjMatrix[1][2], 3);
    ASSERT_FALSE(G.adjMatrix[2][1]==2);
    ASSERT_TRUE(G.adjMatrix[2][1]==3);

    //declare a directed graph
    // Add a edge between 1&2
    Graph G1(6,true);
    G1.addEdge(1,2,1);

    ASSERT_EQ(G1.adjMatrix[1][2], 1);
    ASSERT_TRUE(G1.adjMatrix[2][1]==0);
}

TEST(GraphTests, testNVertices)
{
    Graph G(6,false);
    ASSERT_EQ(G.vertices, 6);
}