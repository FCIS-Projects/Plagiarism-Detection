#include "directeddfs.h"
#include "directedgraph.h"

DirectedDFS::DirectedDFS(DirectedGraph *digraph)
{
    marked = new bool[digraph->nodes_number];
    this->digraph = digraph;
}

DirectedDFS::DirectedDFS(DirectedGraph *digraph, int node)
{
    marked = new bool[digraph->nodes_number];
    this->digraph = digraph;
    dfs(node);
}

void DirectedDFS::dfs(int node)
{
    marked[node] = true;
    for (int i = 0; i <= digraph->nodes_number; i++)
    {
        if(!marked[i])
            dfs(i);
    }
}

bool DirectedDFS::mark(int node)  //to check if the node is reachable or not
{
    return marked[node];
}

DirectedDFS::~DirectedDFS()
{
    delete[] marked;
}


