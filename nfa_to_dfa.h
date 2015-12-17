#ifndef NFA_TO_DFA_H
#define NFA_TO_DFA_H

#include "directedgraph_dfa.h"
#include "directeddfs_dfa.h"
#include <QList>

class NFA_TO_DFA
{
private:
//    QVector<int>* reachable_states;
//    QVector<int>* marked;
    digraph::DirectedGraph* nfa_digraph;
    dfa_digraph::DirectedGraph_DFA* dfa_digraph;
    QList<digraph::Node> *nfa;
    QList<dfa_digraph::Node> *dfa;
    int root;
    DirectedDFS_DFA* dfs;

public:
//    struct Node
//    {
//        bool is_finial_state;
//        QVector<int> next_state;
//    };

//    #define DFA_MAP QMap<int, Node*>

    NFA_TO_DFA(digraph::DirectedGraph* digraph_nfa, int root);
    void build_dfa();
//    void build_reachable_states(int node);
//    void build_reachable_states(QVector<int>* nodes);
};

#endif // NFA_TO_DFA_H
