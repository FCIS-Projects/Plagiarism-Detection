#include "directeddfs_dfa.h"


DirectedDFS_DFA::DirectedDFS_DFA() : DirectedDFS(NULL)
{

}

void DirectedDFS::dfs(int node)
{
    marked->operator [](node) = true;
    MAP* nodes_list = digraph->get_nodes_list();

    foreach (int child, *(*nodes_list)[node])
    {
        if(!marked->at(child))
        {
            dfs(child);
        }
    }
}
