#include "nfa.h"
#include <QStack>

NFA::NFA()
{

}

NFA::NFA(QString regular_expression)
{
    this->regular_expression = regular_expression;

    epsilon_transions = new DirectedGraph(regular_expression.length() + 1);

    QStack<int> *operations = new QStack<int>();
    this->number_of_states = regular_expression.length();

    for (int iii = 0; iii < number_of_states; ++iii)
    {
        int loop = iii;

        if( regular_expression[iii] == '(' || regular_expression[iii] == '|')
            operations->push(iii);

        else if( regular_expression[iii] == ')' )
        {
            int _or = operations->pop();

            if( regular_expression[iii] == '|' )
            {
                loop = operations->pop();
                epsilon_transions->add_edge(loop, _or + 1);
                epsilon_transions->add_edge(_or, iii);
            }

            else
                loop = _or;
        }

        if( iii < this->number_of_states - 1 && regular_expression[iii + 1] == '*' )
        {
            epsilon_transions->add_edge(loop, iii + 1);
            epsilon_transions->add_edge(iii + 1, loop);
        }

        if( regular_expression[iii] == '(' ||
            regular_expression[iii] == '*' ||
            regular_expression[iii] == ')' )
        {
            epsilon_transions->add_edge(iii, iii + 1);
        }
    }
}

NFA::~NFA()
{
    delete epsilon_transions;
}

bool NFA::recognizes(QString str)
{
    QList<int> match_transisions = new QList<int>();
    DirectedDFS dfs = new DirectedDFS(epsilon_transions,0);

    for (int v = 0; v < epsilon_transions->nodes_number(); v++)
    {
        if (dfs.marked(v))
            match_transisions.append(v);
    }

    for (int i = 0; i < str.length(); i++)
    {
        QList<int> match = new QList<int>();
        for (int v = 0; v <= match_transisions.length(); v++)
        {
            if (v < number_of_states)
            {
                if (regular_expression[v] == str[i] || regular_expression[v] == ".")
                {
                    match.append(v+1);
                }
            }
        }

        match_transisions = new QList<int>();
        dfs = new DirectedDFS(epsilon_transions, match);

        for (int v = 0; v < epsilon_transions->nodes_number(); v++)
        {
            if (dfs.marked(v))
                match_transisions.append(v);
        }

        for (int v = 0; v <= match_transisions.length(); v++)
        {
            if (v == number_of_states)
                return true;
            else
                return false;
        }
    }
}
