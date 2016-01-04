#ifndef NFA_H
#define NFA_H
#include <QString>
#include <QFile>
#include <QList>
#include "directedgraph.h"
#include "directeddfs.h"


class NFA
{
private:
    QString regular_expression;
    digraph::DirectedGraph *epsilon_transtions;
    int number_of_states;
    DirectedDFS *dfs;

public:
    NFA();
    NFA(QString regular_expression);
    ~NFA();

    void build_nfa(QString regular_expression);

    //function to recognize the string belongs to the regular expression or invalid
    bool recognizes(QString str);

    QList<int> * build_reachable_states(int root);
    QList<int> * build_reachable_states(QList<int>* root);
    digraph::DirectedGraph* get_epsilon_transtions();

    // check if _char is within a range defined with 'symbol'
    static bool check_range(QString symbol, QChar _char);
};

#endif // NFA_H

