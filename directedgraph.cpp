#include "directedgraph.h"

int current_index = 0;

DirectedGraph::DirectedGraph(int nodes_length)
{
    nodes_list = new QMap< int, QVector<int>* >;

    for (int iii = 0; iii < nodes_length; ++iii)
    {
        nodes_list->insert(iii, new QVector<int>);
    }
}

void DirectedGraph::add_edge(int head, int tail)
{
    QVector<int> *vertex = nodes_list->operator [](head);
    vertex->append(tail);
}

QMap< int, QVector<int>* >* DirectedGraph::get_nodes_list() const
{
    return nodes_list;
}
