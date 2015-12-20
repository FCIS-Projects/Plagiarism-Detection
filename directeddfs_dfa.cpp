#include "directeddfs_dfa.h"

using namespace digraph;

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph) : DirectedDFS( digraph )
{
    reachable_states_list = new QList<int>;
//    reachable_states_list = new QList< ReachableState >;
}

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph, int node) : DirectedDFS( digraph, node )
{
    reachable_states_list = new QList<int>;
//    reachable_states_list = new QList< ReachableState >;
//    created_nodes = new QVector<bool>(digraph->get_nodes_list()->length());
}

DirectedDFS_DFA::DirectedDFS_DFA(DirectedGraph *digraph, QList<int> *node) : DirectedDFS( digraph, node )
{
    reachable_states_list = new QList<int>;
//    reachable_states_list = new QList< ReachableState >;
//    created_nodes = new QVector<bool>(digraph->get_nodes_list()->length());
}

ReachableState* temp_state = NULL;

void DirectedDFS_DFA::search(int node)
{
    QList<digraph::Node>* nfa = digraph->get_nodes_list();

    if((*nfa)[node].connections.length() == 0)
    {
        // TODO: get the first 'node' value and use it as index
        // for list_of_reachable_states
        reachable_states_list->append(node);

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

void DirectedDFS_DFA::search(QList<int> *nodes_list)
{
    foreach (int node, *nodes_list)
    {
        search(node);
    }
}

QList< int >* DirectedDFS_DFA::get_reachable_states() const
{
    return reachable_states_list;
}

void DirectedDFS_DFA::clear()
{
    DirectedDFS::clear();
    reachable_states_list->clear();
}

//QVector<bool>* DirectedDFS_DFA::get_created_nodes() const
//{
//    return created_nodes;
//}
