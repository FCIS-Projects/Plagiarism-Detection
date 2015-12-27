#ifndef DFA_SEARCH_H
#define DFA_SEARCH_H
#include <QString>
#include "directedgraph_dfa.h"
#include <QList>

class DFA_Search
{
private:
    dfa_digraph::DirectedGraph_DFA *digraph;
    QString *regex;
    QList<dfa_digraph::Node>* dfa;
public:
    DFA_Search(dfa_digraph::DirectedGraph_DFA *digraph, QString *regex );
    bool search(QString *str);
};

#endif // DFA_SEARCH_H
