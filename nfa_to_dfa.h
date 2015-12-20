#ifndef NFA_TO_DFA_H
#define NFA_TO_DFA_H

#include "directedgraph_dfa.h"
#include "directeddfs_dfa.h"
#include <QList>

class NFA_TO_DFA
{
private:
    digraph::DirectedGraph* nfa_digraph;
    QList<digraph::Node> *nfa;
    dfa_digraph::DirectedGraph_DFA* dfa_digraph;
    QList<dfa_digraph::Node> *dfa;

    int root;
    DirectedDFS_DFA* dfs;

    // This has 2 uses,
    // #1 it append created node, to if it is already created
    // #2 if the node created, append the corrsponding dfa node to it
    QVector<int>* nfa_dfa_nodes;

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
