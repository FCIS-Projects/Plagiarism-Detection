#ifndef NFA_TO_DFA_H
#define NFA_TO_DFA_H

#include "directedgraph_dfa.h"
#include "directeddfs_dfa.h"
#include <QMap>

class NFA_TO_DFA
{
private:
//    QVector<int>* reachable_states;
//    QVector<int>* marked;
    DirectedGraph* digraph_nfa;
    MAP *nfa;
    DFA_MAP *dfa;
    int root;
    DirectedDFS_DFA* dfs;
    DirectedGraph_DFA* digraph_dfa;

public:
//    struct Node
//    {
//        bool is_finial_state;
//        QVector<int> next_state;
//    };

//    #define DFA_MAP QMap<int, Node*>

    NFA_TO_DFA(DirectedGraph* digraph_nfa, int root);
    void build_dfa();
//    void build_reachable_states(int node);
//    void build_reachable_states(QVector<int>* nodes);
};

#endif // NFA_TO_DFA_H
