#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <QLinkedList>
#include <QVector>

class DiGraph
{
private:
    // 2d dynamic array of size (N x 2)
    // where '2' represents HEAD and TAIL
    // ---- To read from verteces,
    // verteces->at(N)->at(HEAD)
    // verteces->at(N)->at(TAIL)
    // ---- To read or write from/to verteces,
    // verteces->last()->operator [](HEAD)
    // verteces->last()->operator [](TAIL)
    QVector< QVector<int>* > *verteces;

public:
    DiGraph();
    ~DiGraph();

    #define HEAD 0
    #define TAIL 1

    void add_edge(int head, int tail);

    // 'const' at the end, is using to make verteces read-only
    QVector< QVector<int>* >* get_verteces() const;
};

#endif // DIGRAPH_H
