#ifndef DIRECTEDDFS_H
#define DIRECTEDDFS_H
#include "directedgraph.h"
#include <QVector>

class DirectedDFS
{
private:
    QVector <bool> *marked; //array to store the visited nodes
    DirectedGraph *digraph;
public:
    DirectedDFS(DirectedGraph *digraph);
    DirectedDFS(DirectedGraph *digraph, int node); //initialize the array marked to store the reachable states
    DirectedDFS(DirectedGraph *digraph, QVector<int> *node);
    ~DirectedDFS();

    void dfs(int node); //detect the reachble states of the digraph, store them in array marked[]
    bool mark(int node);

};

#endif // DIRECTEDDFS_H
