#ifndef DIRECTEDDFS_H
#define DIRECTEDDFS_H
#include "directedgraph.h"
#include <QVector>

class DirectedDFS
{
private:
    QVector <bool> *marked; //array to store the visited nodes
    nfa_graph::DirectedGraph *digraph;
public:
    DirectedDFS(nfa_graph::DirectedGraph *digraph);
    DirectedDFS(nfa_graph::DirectedGraph *digraph, int node); //initialize the array marked to store the reachable states
    DirectedDFS(nfa_graph::DirectedGraph *digraph, QVector<int> *nodes_list);
    ~DirectedDFS();

    void dfs(int node); //detect the reachble states of the digraph, store them in array marked[]
    void dfs(QVector<int> *nodes_list);
    bool mark(int node);

};

#endif // DIRECTEDDFS_H
