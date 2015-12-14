#ifndef DIRECTEDDFS_H
#define DIRECTEDDFS_H
#include "directedgraph.h"
#include <QVector>

class DirectedDFS
{
protected:
    QVector <bool> *marked; //array to store the visited nodes
    digraph::DirectedGraph *digraph;
public:
    DirectedDFS(digraph::DirectedGraph *digraph);
    DirectedDFS(digraph::DirectedGraph *digraph, int node); //initialize the array marked to store the reachable states
    DirectedDFS(digraph::DirectedGraph *digraph, QVector<int> *nodes_list);
    ~DirectedDFS();

    void dfs(int node); //detect the reachble states of the digraph, store them in array marked[]
    void dfs(QVector<int> *nodes_list);
    bool mark(int node);

};

#endif // DIRECTEDDFS_H
