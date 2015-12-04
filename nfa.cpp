#include "nfa.h"
#include <QStack>

NFA::NFA()
{

}

NFA::NFA(QString regular_expression)
{
    QStack<int> *operations = new QStack<int>();
    this->number_of_states = regular_expression.length();
//    match_transitions = regular_expression.data();

    for (int iii = 0; iii < number_of_states; ++iii)
    {
        int loop = iii;

        if( regular_expression[iii] == '(' || regular_expression[iii] == '|')
            operations->push(iii);

        else if( regular_expression[iii] == ')' )
        {
            int check_or = operations->pop();

            if( regular_expression[iii] == '|' )
            {
                loop = operations->pop();
//                G.addEdge(lp, or+1);
//                G.addEdge(or, i);
            }

            else
                loop = check_or;
        }

        if( iii < this->number_of_states - 1 && regular_expression[iii + 1] == '*' )
        {
//            G.addEdge(lp, i+1);
//            G.addEdge(i+1, lp);
        }

        if( regular_expression[iii] == '(' ||
            regular_expression[iii] == '*' ||
            regular_expression[iii] == ')' );
//            G.addEdge(i, i+1);
    }
}
