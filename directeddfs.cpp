#include "directeddfs.h"
#include "directedgraph.h"

DirectedDFS::DirectedDFS(DirectedGraph *digraph)
{
    marked = new QVector<bool>(digraph->nodes_number);
    this->digraph = digraph;
}

DirectedDFS::DirectedDFS(DirectedGraph *digraph, int node)
{
    marked = new QVector<bool>(digraph->nodes_number);
    this->digraph = digraph;
    dfs(node);
}

void DirectedDFS::dfs(int node)
{
    marked->operator [](node) = true;
    MAP* nodes_list = digraph->get_nodes_list();

    foreach (int child, *(*nodes_list)[node])
    {
        if(!marked->at(child))
        {
            dfs(child);
        }
    }
}

bool DirectedDFS::mark(int node)  //to check if the node is reachable or not
{
    return marked->at(node);
}

DirectedDFS::~DirectedDFS()
{
    delete[] marked;
}


