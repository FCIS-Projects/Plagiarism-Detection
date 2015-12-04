#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <QVector>
#include <QMap>

class DirectedGraph
{
public:
    #define MAP QMap< int, QVector<int>* >
private:
    int vertecies;
    MAP* nodes_list;

public:
    DirectedGraph(int nodes_length);
    ~DirectedGraph();

    void add_edge( int head, int tail );
    MAP* get_nodes_list() const;

};

#endif // DIRECTEDGRAPH_H
