#include "directedgraph.h"

int current_index = 0;

DirectedGraph::DirectedGraph(int nodes_number)
{
    nodes_list = new QMap< int, QVector<int>* >;

    this->nodes_number = nodes_number;

    for (int iii = 0; iii < nodes_number; ++iii)
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

DirectedGraph::~DirectedGraph()
{
    for (int iii = 0; iii < nodes_list->size(); ++iii)
    {
        delete nodes_list->operator [](iii);
    }

    delete nodes_list;
}
