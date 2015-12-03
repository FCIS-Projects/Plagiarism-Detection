#ifndef NFA_H
#define NFA_H
#include <QString>
#include <QObject>
#include <QChar>

class NFA
{
private:
//    QChar* match_transitions;
//    QString regular_expressions;
    //TODO: create DiGraph class
    QObject *epsilon_transions;
    int number_of_states;

public:
    NFA();
    NFA(QString regular_expression);
    ~NFA();
    bool recognizes(QString str);
};

#endif // NFA_H
