#ifndef DIRECTEDDFS_H
#define DIRECTEDDFS_H
#include "directedgraph.h"


class DirectedDFS
{
private:
    bool *marked; //array to store the visited nodes
    DirectedGraph *digraph;
public:
    DirectedDFS();
    ~DirectedDFS();
    DirectedDFS(DirectedGraph *digraph);
    DirectedDFS(DirectedGraph *digraph, int node); //initialize the array marked to store the reachable states
    void dfs(int node); //detect the reachble states of the digraph, store them in array marked[]
    bool mark(int node);

};

#endif // DIRECTEDDFS_H
