#ifndef DIRECTEDDFS_DFA_H
#define DIRECTEDDFS_DFA_H
#include "directeddfs.h"

class DirectedDFS_DFA : DirectedDFS
{
private:
    QList<int>* reachable_states;

public:
    DirectedDFS_DFA(digraph::DirectedGraph *digraph);
    DirectedDFS_DFA(digraph::DirectedGraph *digraph, int node);
    DirectedDFS_DFA(digraph::DirectedGraph *digraph, QList<int> *node);
    ~DirectedDFS_DFA();

    void search(int node);
    QList<int>* get_reachable_states() const;
    // clear 'marked' array, and 'reachable_states' array
    void clear();
};

#endif // DIRECTEDDFS_DFA_H
