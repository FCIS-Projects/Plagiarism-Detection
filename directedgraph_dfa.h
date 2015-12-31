#ifndef DIRECTEDGRAPH_DFA_H
#define DIRECTEDGRAPH_DFA_H
#include "directedgraph.h"
#include <QList>
#include <QString>

namespace dfa_digraph
{
    struct Node
    {
        int index;
        QList<int> connections;
        bool is_finial_state;
        QList<QString> match_transitions;
    };
    
    class DirectedGraph_DFA : private digraph::DirectedGraph
    {
    public:
        DirectedGraph_DFA();
        ~DirectedGraph_DFA();

        int create_node();
        void add_edge( int head, int tail );
    
    private:
        QList< dfa_digraph::Node >* nodes_list;
    
    public:
        QList< dfa_digraph::Node >* get_nodes_list();
        void set_node_value(int index, QChar _char);
    };
}
    
#endif // DIRECTEDGRAPH_DFA_H
