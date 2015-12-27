#include "dfa_search.h"

DFA_Search::DFA_Search(dfa_digraph::DirectedGraph_DFA *digraph, QString *regex )
{
    this->digraph = digraph;
    this->regex = regex;

    dfa = digraph->get_nodes_list();
}

bool DFA_Search::search(QString *str)
{
    bool is_dismatch = false;
    int index = 0;
    int str_index = 0;
    int regex_index = 0;

    while( !is_dismatch )
    {
        foreach (int node_index, (*dfa)[index].connections)
        {
            regex_index = (*dfa)[node_index].match_transitions[0];

            if( (*regex)[regex_index] == str->at(str_index) )
            {
                index = (*dfa)[node_index].index;
                is_dismatch == true;
                break;
            }

            else
                is_dismatch == false;
        }

        str_index++;
    }
}
