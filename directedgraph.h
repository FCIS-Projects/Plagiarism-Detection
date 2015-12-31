#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include <QVector>

namespace digraph
{
    const short EPSILON_TRANS = 0;
    const short MATCH_TRANS = 1;

    struct Node
    {
        int index;
        QList<int> epsilon_transtions;
        QList<int> match_transtions;
        QChar value;
    };

    class DirectedGraph
    {
    public:

    protected:
        int nodes_number;

    private:
        QList<Node>* nodes_list;

    protected:
        void check_node_validity(int node);

    public:
        DirectedGraph(int nodes_number);
        DirectedGraph();
        ~DirectedGraph();

        int create_node();
        void add_edge( int head, int tail, short type );
        QList<Node>* get_nodes_list() const;
        void set_node_value(int index, QChar _char);

    };
}

#endif // DIRECTEDGRAPH_H
