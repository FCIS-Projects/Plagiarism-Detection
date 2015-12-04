#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <QVector>
#include <QMap>

class DirectedGraph
{
public:
    #define MAP QMap< int, QVector<int>* >
    int nodes_number;

private:
    MAP* nodes_list;

public:
    DirectedGraph(int nodes_number);
    ~DirectedGraph();

    void add_edge( int head, int tail );
    MAP* get_nodes_list() const;

};

#endif // DIRECTEDGRAPH_H
