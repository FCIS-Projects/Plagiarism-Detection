#include "digraph.h"

const int node_length = 2;

DiGraph::DiGraph()
{
    verteces = new QVector< QVector<int>* >;
}

void DiGraph::add_edge(int head, int tail)
{
    verteces->append( new QVector<int>(node_length) );
    verteces->last()->operator [](HEAD) = head;
    verteces->last()->operator [](TAIL) = tail;
}

QVector< QVector<int>* >* DiGraph::get_verteces() const
{
    return verteces;
}

DiGraph::~DiGraph()
{
    for (int iii = 0; iii < verteces->length(); ++iii)
    {
        delete verteces->at(iii);
    }

    delete verteces;
}
