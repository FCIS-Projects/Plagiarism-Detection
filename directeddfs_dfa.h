#ifndef DIRECTEDDFS_DFA_H
#define DIRECTEDDFS_DFA_H
#include "directeddfs.h"
#include <QVector>

struct ReachableState
{
    int head;
    QList<int> tails;
};

class DirectedDFS_DFA : public DirectedDFS
{
private:
    QList< int >* reachable_states_list;
//    QList<int>* list_of_reachable_states;

public:
    DirectedDFS_DFA(digraph::DirectedGraph *digraph);
    DirectedDFS_DFA(digraph::DirectedGraph *digraph, int node);
    DirectedDFS_DFA(digraph::DirectedGraph *digraph, QList<int> *nodes_list);
    ~DirectedDFS_DFA();

    void search(int node);
    void search(QList<int> *nodes_list);
    QList< int >* get_reachable_states() const;
    // clear 'marked' array, and 'reachable_states' array
    void clear();
//    QVector<bool>* get_created_nodes() const;
};

#endif // DIRECTEDDFS_DFA_H
