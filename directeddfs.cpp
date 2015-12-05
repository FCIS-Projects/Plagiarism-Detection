#include "directeddfs.h"
#include "directedgraph.h"

DirectedDFS::DirectedDFS(DirectedGraph *digraph, int node)
{
    marked = new bool[digraph->nodes_number];
    dfs(digraph, node);
}

void DirectedDFS::dfs(DirectedGraph *digraph, int node)
{
    marked[node] = true;
    for (int i = 0; i <= digraph->nodes_number; i++)
    {
        if(!marked[i])
            dfs(digraph, i);
    }
}

bool DirectedDFS::mark(int node)  //to check if the node is reachable or not
{
    return marked[node];
}


