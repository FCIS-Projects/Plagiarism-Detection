#include "directedgraph.h"

using namespace digraph;

DirectedGraph::DirectedGraph()
{
    nodes_list = new QList<Node>;
    nodes_number = 0;
}

DirectedGraph::DirectedGraph(int nodes_number)
{
    nodes_list = new QList<Node>;

    this->nodes_number = nodes_number;

    for (int iii = 0; iii < nodes_number; ++iii)
    {
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

void DirectedGraph::add_edge( int head, int tail, short type )
{
    check_node_validity(head);
    check_node_validity(tail);

    if( type == EPSILON_TRANS )
        (*nodes_list)[head].epsilon_transtions.append(tail);
    else if( type == MATCH_TRANS )
        (*nodes_list)[head].match_transtions.append(tail);
}

QList<Node>* DirectedGraph::get_nodes_list() const
{
    return nodes_list;
}

void DirectedGraph::set_node_value(int index, QChar _char)
{
    (*nodes_list)[index].value = _char;
}

DirectedGraph::~DirectedGraph()
{
    delete nodes_list;
}
