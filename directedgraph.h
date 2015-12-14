#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <QVector>
#include <QMap>

namespace nfa_graph
{
    struct Node
    {
        int index;
        QVector<int> connections;
    };

    class DirectedGraph
    {
    public:
    //    #define MAP QMap< int, QVector<int>* >
        #define MAP QVector<Node>
        // TODO: this should be private and use get_nodes_number() to get it

    private:
        int nodes_number;
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
        int get_nodes_number();

    };
}

#endif // DIRECTEDGRAPH_H
