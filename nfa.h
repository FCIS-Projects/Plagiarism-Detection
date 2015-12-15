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

    //function to recognize the string belongs to the regular expression or invalid
    bool recognizes(QString str);

    // check if _char is within a range defined with 'symbol'
    bool check_range(QString symbol, QChar _char);

    void search( QString *str, int index );
    void search( QFile file );
    QList<int> * build_reachable_states(int root);
    QList<int> * build_reachable_states(QList<int>* root);
    MAP* get_epsilon_transtions();
};

#endif // NFA_H

