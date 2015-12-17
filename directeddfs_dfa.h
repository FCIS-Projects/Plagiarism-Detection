#ifndef DIRECTEDDFS_DFA_H
#define DIRECTEDDFS_DFA_H
#include "directeddfs.h"
#include <QVector>

class DirectedDFS_DFA : DirectedDFS
{
private:
    QList<int>* reachable_states;
    QVector<bool>* created_nodes;

public:
    DirectedDFS_DFA(digraph::DirectedGraph *digraph);
    DirectedDFS_DFA(digraph::DirectedGraph *digraph, int node);
    DirectedDFS_DFA(digraph::DirectedGraph *digraph, QList<int> *nodes_list);
    ~DirectedDFS_DFA();

    void search(int node);
    QList<int>* get_reachable_states() const;
    // clear 'marked' array, and 'reachable_states' array
    void clear();
    QVector<bool>* get_created_nodes() const;
};

#endif // DIRECTEDDFS_DFA_H
