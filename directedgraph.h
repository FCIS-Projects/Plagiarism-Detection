#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <QVector>
#include <QMap>

struct Node
{
    QVector<int> connections;
};

class DirectedGraph
{
public:
//    #define MAP QMap< int, QVector<int>* >
    #define MAP QVector<Node>
    // TODO: this should be private and use get_nodes_number() to get it
    int nodes_number = 0;

private:
    MAP* nodes_list;
protected:
    void check_node_validity(int node);

public:
    DirectedGraph(int nodes_number);
    DirectedGraph();
    ~DirectedGraph();

    void add_edge( int head, int tail );
//    void add_edge( Node* head, Node* tail );
    MAP* get_nodes_list() const;

};

#endif // DIRECTEDGRAPH_H
