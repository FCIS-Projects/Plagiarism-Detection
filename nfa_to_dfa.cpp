#include "nfa_to_dfa.h"

NFA_TO_DFA::NFA_TO_DFA(digraph::DirectedGraph* nfa_digraph, int root)
{
    this->nfa_digraph = nfa_digraph;

    this->nfa = nfa_digraph->get_nodes_list();
    this->root = root;

    dfs = new DirectedDFS_DFA(nfa_digraph);
    dfa_digraph = new dfa_digraph::DirectedGraph_DFA();
    this->dfa = dfa_digraph->get_nodes_list();

    nfa_dfa_nodes = new QVector<int>(nfa_digraph->get_nodes_list()->length(), -1);
}

void NFA_TO_DFA::build_dfa()
{
    int tail = root;

    QList<int>* start_nodes = new QList<int>;

    // Create Initial Node
    dfa_digraph->create_node();
    (*nfa_dfa_nodes)[root] = root;
    start_nodes->append(root);

    for(int iii = 0; iii < start_nodes->length(); iii++ )
    {
        if( dfs->get_reachable_states()->length() != 0 )
            dfs->clear();

        dfs->search((*start_nodes)[iii]);

        foreach (int node, *dfs->get_reachable_states())
        {
            if( node == nfa->size() - 1 )
            {
                // mark current node as final node
                (*dfa)[iii].is_finial_state = true;
            }

            else if( node != nfa->size() - 1 && nfa_dfa_nodes->at(node) == -1 )
            {
                // Build new Node
                dfa_digraph->create_node();

                tail = dfa->last().index;
                (*nfa_dfa_nodes)[node] = tail;

                // make connection
                dfa_digraph->add_edge(iii, tail);

                // connect to coresponding alpha in the regular expression
                (*dfa)[tail].match_transitions.append((*nfa)[node].value);

                start_nodes->append(node + 1);
            }

            else if(nfa_dfa_nodes->at(node) != -1)
            {
                dfa_digraph->add_edge(iii, nfa_dfa_nodes->at(node));
            }
        }
    }
}

dfa_digraph::DirectedGraph_DFA* get_dfa_nodes()
{
    return dfa_digraph;
}
