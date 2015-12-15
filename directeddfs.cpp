#include "directeddfs.h"
#include <algorithm>

DirectedDFS::DirectedDFS(digraph::DirectedGraph *digraph)
{
    marked = new bool[digraph->get_nodes_number()];
    this->digraph = digraph;
}

DirectedDFS::DirectedDFS(digraph::DirectedGraph *digraph, int node)
{
    marked = new bool[digraph->get_nodes_number()];
    this->digraph = digraph;
    search(node);
}

DirectedDFS::DirectedDFS(digraph::DirectedGraph *digraph, QList<int> *nodes_list)
{
    marked = new bool[digraph->get_nodes_number()];
    this->digraph = digraph;
    foreach (int node, *nodes_list)
    {
        search(node);
    }
}

void DirectedDFS::search(int node)
{
    marked[node] = true;
    MAP* nodes_list = digraph->get_nodes_list();

    foreach (int child, (*nodes_list)[node].connections )
    {
        if(!marked[child])
        {
            search(child);
        }
    }
}

void DirectedDFS::search(QList<int> *nodes_list)
{
    foreach (int node, *nodes_list)
    {
        search(node);
    }
}

bool DirectedDFS::is_marked(int node)  //to check if the node is reachable or not
{
    return marked[node];
}

void DirectedDFS::clear()
{
    // restart marked - this is the fastest way
    // std::fill which is depend on memset
    std::fill( marked, marked + digraph->get_nodes_number(), false);
}

DirectedDFS::~DirectedDFS()
{
    delete[] marked;
}


