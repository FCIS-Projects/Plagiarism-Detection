#include "nfa.h"
#include "directedgraph.h"
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
        int current_index = iii;

        if( regular_expression[iii] == '(' || regular_expression[iii] == '|')
            operations->push(iii);

        else if( regular_expression[iii] == ')' )
        {
            int pop = operations->pop();

            if( regular_expression[pop] == '|' )
            {
                current_index = operations->pop();
                epsilon_transions->add_edge(current_index, pop + 1);
                epsilon_transions->add_edge(pop, iii);
            }

            else
                current_index = pop;
        }

        if( iii < number_of_states - 1 && regular_expression[iii + 1] == '*' )
        {
            epsilon_transions->add_edge(current_index, iii + 1);
            epsilon_transions->add_edge(iii + 1, current_index);
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
    QList<int> *match_transisions = new QList<int>(); //create list to store the nodes do match with str
    DirectedDFS *dfs = new DirectedDFS(epsilon_transions, 0); //initialize object dfs

    //store the indeces of the marked nodes
    for (int v = 0; v < epsilon_transions->nodes_number; v++)
    {
        if (dfs->mark(v))
            match_transisions->append(v);
    }

// Compute possible NFA states for str[i+1]
    for (int i = 0; i < str.length(); i++)
    {
        QList<int> *match = new QList<int>(); //create list to store the match characters to the regular expression

        //store the match characters to the regular expression
        for (int v = 0; v <= match_transisions->length(); v++)
        {
            if (v < number_of_states)
            {
                if (regular_expression[v] == str[i] || regular_expression[v] == '.')
                {
                    match->append(v+1);
                }
            }
        }

        match_transisions = new QList<int>();
        dfs = new DirectedDFS(epsilon_transions, match->last());

        //store the indeces of the marked nodes
        for (int v = 0; v < epsilon_transions->nodes_number; v++)
        {
            if (dfs->mark(v))
                match_transisions->append(v);
        }
    }

    //final check if the string matches the regular expression or not
    for (int v = 0; v <= match_transisions->length(); v++)
    {
        if (v == number_of_states)
            return true;
    }
    return false;
}
