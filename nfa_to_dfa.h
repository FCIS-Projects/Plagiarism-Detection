#ifndef NFA_TO_DFA_H
#define NFA_TO_DFA_H

#include "directedgraph.h"
#include "directeddfs.h"
#include <QMap>

class NFA_TO_DFA
{
private:
    QVector<int>* reachable_states;
    QVector<int>* marked;
    MAP *nfa;
    int root;

public:
//    struct Node
//    {
//        bool is_finial_state;
//        QVector<int> next_state;
//    };

//    #define DFA_MAP QMap<int, Node*>

    NFA_TO_DFA(MAP *nfa, int root);
    void build_dfa();
//    void build_reachable_states(int node);
//    void build_reachable_states(QVector<int>* nodes);

//private:
//    DFA_MAP *dfa;
};

#endif // NFA_TO_DFA_H
