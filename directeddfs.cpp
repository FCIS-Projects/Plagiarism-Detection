#include "directeddfs.h"

DirectedDFS::DirectedDFS(digraph::DirectedGraph *digraph)
{
    marked = new QVector<bool>(digraph->get_nodes_number());
    this->digraph = digraph;
}

DirectedDFS::DirectedDFS(digraph::DirectedGraph *digraph, int node)
{
    marked = new QVector<bool>(digraph->get_nodes_number());
    this->digraph = digraph;
    dfs(node);
}

DirectedDFS::DirectedDFS(digraph::DirectedGraph *digraph, QVector<int> *nodes_list)
{
    marked = new QVector<bool>(digraph->get_nodes_number());
    this->digraph = digraph;
    foreach (int node, *nodes_list)
    {
        dfs(node);
    }
}

void DirectedDFS::dfs(int node)
{
    marked->operator [](node) = true;
    MAP* nodes_list = digraph->get_nodes_list();

    foreach (int child, (*nodes_list)[node].connections )
    {
        if(!marked->at(child))
        {
            dfs(child);
        }
    }
}

void DirectedDFS::dfs(QVector<int> *nodes_list)
{
    foreach (int node, *nodes_list)
    {
        dfs(node);
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


