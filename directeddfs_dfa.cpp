#include "directeddfs_dfa.h"

using namespace digraph;

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph) : DirectedDFS( digraph )
{
}

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph, int node) : DirectedDFS( digraph, node )
{
}

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph, QList<int> *node) : DirectedDFS( digraph, node )
{
}

void DirectedDFS_DFA::search(int node)
{
    MAP* nfa = digraph->get_nodes_list();

    if((*nfa)[node].connections.length() == 0)
    {
        reachable_states->append(node);
//        qDebug("%i", node);
        return;
    }

    marked[node] = true;

    foreach (int connection, (*nfa)[node].connections)
    {
        if(!marked[connection])
        {
            search(connection);
        }
    }
}

QList<int>* DirectedDFS_DFA::get_reachable_states() const
{
    return reachable_states;
}

void DirectedDFS_DFA::clear()
{
    DirectedDFS::clear();
    reachable_states->clear();
}
