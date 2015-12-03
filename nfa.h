#ifndef NFA_H
#define NFA_H
#include <QString>
#include <QObject>

class NFA
{
private:
    char match_transitions[];
    //TODO: create DiGraph class
    QObject *epsilon_transions;
    int number_of_states;

public:
    NFA();
    ~NFA();
    bool recognizes(QString str);
};

#endif // NFA_H
