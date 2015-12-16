#include "directedgraph_dfa.h"

using namespace dfa_digraph;

DirectedGraph_DFA::DirectedGraph_DFA() : DirectedGraph()
{
    nodes_list = new DFA_MAP;
}

int DirectedGraph_DFA::create_node()
{
    // Create new node and append it to the array
    nodes_list->append( (*new Node) );

    // Change the 'index' variable into the current index
    int last_node_index = nodes_list->length() - 1;
    (*nodes_list)[last_node_index].index = last_node_index;

    // Update the number of nodes
    nodes_number++;


    nodes_list->last().is_finial_state = false;

    return last_node_index;
}

void DirectedGraph_DFA::add_edge( int head, int tail )
{
    DirectedGraph::check_node_validity(head);
    DirectedGraph::check_node_validity(tail);

//    if( dfa->size() == 0 && (*dfa)[tail] != NULL )
//    QVector<int> *vertex = dfa->operator [](head);


//    tail_node->next_state.append(tail);
//    Node *tail_node = new Node;
//    dfa->insert(-1, tail_node);

    (*nodes_list)[head].connections.append(tail);
}

DFA_MAP* DirectedGraph_DFA::get_nodes_list()
{
    return nodes_list;
}

DirectedGraph_DFA::~DirectedGraph_DFA()
{

}
