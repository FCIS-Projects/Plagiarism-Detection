#ifndef DIRECTEDDFS_H
#define DIRECTEDDFS_H
#include "directedgraph.h"
#include <QList>

class DirectedDFS
{
protected:
    bool *marked; //array to store the visited nodes
    digraph::DirectedGraph *digraph;
public:
    DirectedDFS(digraph::DirectedGraph *digraph);
    DirectedDFS(digraph::DirectedGraph *digraph, int node); //initialize the array marked to store the reachable states
    DirectedDFS(digraph::DirectedGraph *digraph, QList<int> *nodes_list);
    ~DirectedDFS();

    //detect the reachble states of the digraph, store them in array marked[]
    void search(int node);
    void search(QList<int> *nodes_list);
    bool is_marked(int node);
    void clear();

};

#endif // DIRECTEDDFS_H
