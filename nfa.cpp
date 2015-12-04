#include "nfa.h"
#include <QStack>

NFA::NFA()
{

}

NFA::NFA(QString regular_expression)
{
    this->regular_expression = regular_expression;

    epsilon_transions = new DiGraph();

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
