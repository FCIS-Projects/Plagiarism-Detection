#ifndef DIRECTEDGRAPH_DFA_H
#define DIRECTEDGRAPH_DFA_H
#include "directedgraph.h"
#include <QMap>

struct Node
{
    bool is_finial_state;
    QVector<int> next_state;
};

class DirectedGraph_DFA : private DirectedGraph
{
public:
    DirectedGraph_DFA(MAP* nfa);
    ~DirectedGraph_DFA();


    #define DFA_MAP QMap< int, Node* >

    void build_reachable_states(int node);
    void build_reachable_states(QVector<int>* nodes);
    void add_edge( int head, int tail );

private:
    DFA_MAP* dfa;

public:
    DFA_MAP* get_dfa();
};

#endif // DIRECTEDGRAPH_DFA_H
