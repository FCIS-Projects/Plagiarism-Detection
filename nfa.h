#ifndef NFA_H
#define NFA_H
#include <QString>
#include "directedgraph.h"

class NFA
{
private:
    QString regular_expression;
    DirectedGraph *epsilon_transions;
    int number_of_states;

public:
    NFA();
    NFA(QString regular_expression);
    ~NFA();
    bool recognizes(QString str);
};

#endif // NFA_H
