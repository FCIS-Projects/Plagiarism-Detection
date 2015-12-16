#ifndef DIRECTEDGRAPH_DFA_H
#define DIRECTEDGRAPH_DFA_H
#include "directedgraph.h"
#include <QList>

namespace dfa_digraph
{
    struct Node
    {
        int index;
        QList<int> connections;
        bool is_finial_state;
        QList<int> match_transitions;
    };
    
    class DirectedGraph_DFA : public digraph::DirectedGraph
    {
    public:
        DirectedGraph_DFA();
        ~DirectedGraph_DFA();
    
    
        #define DFA_MAP QList< dfa_digraph::Node >
    
//        void build_reachable_states(int node);
//        void build_reachable_states(QVector<int>* nodes);
        int create_node();
        void add_edge( int head, int tail );
    
    private:
        DFA_MAP* nodes_list;
    
    public:
        DFA_MAP* get_nodes_list();
    };
}
    
#endif // DIRECTEDGRAPH_DFA_H
