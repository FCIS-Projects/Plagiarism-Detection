#include "directedgraph.h"

int current_index = 0;

DirectedGraph::DirectedGraph()
{
    nodes_list = new MAP;
}

DirectedGraph::DirectedGraph(int nodes_number)
{
    nodes_list = new MAP;

    this->nodes_number = nodes_number;

    for (int iii = 0; iii < nodes_number; ++iii)
    {
        nodes_list->insert(iii, new QVector<int>);
    }
}

void DirectedGraph::check_node_validity(int node)
{
    if( node < 0 || node > this->nodes_number )
    {
        qWarning("%i is invalid as a node", node);
        exit(1);
    }
}

void DirectedGraph::add_edge(int head, int tail)
{
    check_node_validity(head);
    check_node_validity(tail);

    if( nodes_number == 0 && (*nodes_list)[tail] != NULL )
        nodes_list->insert(head, new QVector<int>);

    QVector<int> *vertex = nodes_list->operator [](head);
    vertex->append(tail);
}

MAP* DirectedGraph::get_nodes_list() const
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
