#include "directedgraph.h"

using namespace digraph;

int current_index = 0;

DirectedGraph::DirectedGraph()
{
    nodes_list = new MAP;
    nodes_number = 0;
}

DirectedGraph::DirectedGraph(int nodes_number)
{
    nodes_list = new MAP;

    this->nodes_number = nodes_number;

    for (int iii = 0; iii < nodes_number; ++iii)
    {
//        nodes_list->insert(iii, new QVector<int>);
        nodes_list->append( (*new Node) );
        (*nodes_list)[iii].index = iii;
    }
}

int DirectedGraph::create_node()
{
    // Create new node and append it to the array
    nodes_list->append( (*new Node) );

    // Change the 'index' variable into the current index
    int last_node_index = nodes_list->length() - 1;
    (*nodes_list)[last_node_index].index = last_node_index;

    // Update the number of nodes
    nodes_number++;

    return last_node_index;
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

//    if( nodes_number == 0 )
//    {
//        nodes_list->append( (*new Node) );
//        (*nodes_list)[tail].index = tail;
//    }
//        nodes_list->insert(head, new QVector<int>);

    (*nodes_list)[head].connections.append(tail);
//    vertex->append(tail);
//    QVector<int> *vertex = nodes_list->operator [](head);
}

MAP* DirectedGraph::get_nodes_list() const
{
    return nodes_list;
}

int DirectedGraph::get_nodes_number()
{
    return nodes_number;
}

DirectedGraph::~DirectedGraph()
{
//    for (int iii = 0; iii < nodes_list->size(); ++iii)
//    {
//        delete (*nodes_list)[iii];
//    }

    delete nodes_list;
}
