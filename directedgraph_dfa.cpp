#include "directedgraph_dfa.h"

DirectedGraph_DFA::DirectedGraph_DFA(MAP* nfa) : DirectedGraph()
{

}

void DirectedGraph_DFA::add_edge( int head, int tail )
{
    DirectedGraph::check_node_validity(head);
    DirectedGraph::check_node_validity(tail);

//    if( dfa->size() == 0 && (*dfa)[tail] != NULL )
//    QVector<int> *vertex = dfa->operator [](head);

    Node *tail_node = new Node;
    tail_node->next_state.append(tail);

    dfa->insert(head, tail_node);
}

DFA_MAP* DirectedGraph_DFA::get_dfa()
{
    return dfa;
}

DirectedGraph_DFA::~DirectedGraph_DFA()
{

}
