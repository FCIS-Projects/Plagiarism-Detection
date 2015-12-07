#ifndef NFA_H
#define NFA_H
#include <QString>
#include <QChar>
#include "directedgraph.h"
#include "directeddfs.h"


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
    bool recognizes(QString str);           //function to recognize the string belongs to the regular expression or invalid
    // check if _char is within a range defined with 'symbol'
    bool check_range(QString symbol, QChar _char);
};

#endif // NFA_H

