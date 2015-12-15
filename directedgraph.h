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

    private:
        int nodes_number;
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
        int get_nodes_number();

    };
}

#endif // DIRECTEDGRAPH_H
