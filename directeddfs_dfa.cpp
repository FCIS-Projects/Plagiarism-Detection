#include "directeddfs_dfa.h"

using namespace digraph;

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph) : DirectedDFS( digraph )
{
    reachable_states = new QList<int>;
    created_nodes = new QVector<bool>(digraph->get_nodes_list()->length());
}

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph, int node) : DirectedDFS( digraph, node )
{
    reachable_states = new QList<int>;
    created_nodes = new QVector<bool>(digraph->get_nodes_list()->length());
}

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph, QList<int> *node) : DirectedDFS( digraph, node )
{
    reachable_states = new QList<int>;
    created_nodes = new QVector<bool>(digraph->get_nodes_list()->length());
}

void DirectedDFS_DFA::search(int node)
{
    QList<digraph::Node>* nfa = digraph->get_nodes_list();

    if((*nfa)[node].connections.length() == 0)
    {
        reachable_states->append(node);
        created_nodes->insert(node, true);
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

QVector<bool>* DirectedDFS_DFA::get_created_nodes() const
{
    return created_nodes;
}
