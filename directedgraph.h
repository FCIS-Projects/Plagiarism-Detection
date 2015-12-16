#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <QVector>

namespace digraph
{
    struct Node
    {
        int index;
        QList<int> connections;
    };

    class DirectedGraph
    {
    public:
        #define MAP QList<digraph::Node>

    protected:
        int nodes_number;

    private:
        MAP* nodes_list;

    protected:
        void check_node_validity(int node);

    public:
        DirectedGraph(int nodes_number);
        DirectedGraph();
        ~DirectedGraph();

        int create_node();
        void add_edge( int head, int tail );
        MAP* get_nodes_list() const;

    };
}

#endif // DIRECTEDGRAPH_H
