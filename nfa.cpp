#include "nfa.h"
#include "directedgraph.h"
#include <QStack>
#include <QDebug>

NFA::NFA()
{
}

NFA::NFA(QString regular_expression)
{
    /* Building the automaton for the regular expression */
    this->regular_expression = regular_expression;

    // we add another node to the regular expression length
    // to handle 'Accept State'
    epsilon_transtions = new digraph::DirectedGraph(regular_expression.length() + 1);

    // the stack of postfix
    QStack<int> *operations = new QStack<int>();
    this->number_of_states = regular_expression.length();

    for (int iii = 0; iii < number_of_states; ++iii)
    {
        int current_index = iii;

        // handling 'range'
        if( regular_expression[iii] == '[' )
        {
            int kkk;
            for (kkk = iii; regular_expression[kkk] != ']'; ++kkk);
            epsilon_transtions->add_edge(iii, kkk);
            iii = kkk;
            current_index = iii;
        }

        // this uses the concept of postfix to handl '(', ')' and '|'
        else if( regular_expression[iii] == '(' || regular_expression[iii] == '|' )
            operations->push(iii);

        else if( regular_expression[iii] == ')' )
        {
            int pop = operations->pop();

            if( regular_expression[pop] == '|' )
            {
                current_index = operations->pop();
                epsilon_transtions->add_edge(current_index, pop + 1);
                epsilon_transtions->add_edge(pop, iii);
            }

            else
                current_index = pop;
        }

        if( iii < number_of_states - 1 )
        {
            // handling epsilon_transions of '*'
            // we have 2 options
            // option 1: AB*
            // option 2: (AB)* and this one will use 'current_index = pop'
            if( regular_expression[iii + 1] == '*' )
            {
                epsilon_transtions->add_edge(current_index, iii + 1);
                epsilon_transtions->add_edge(iii + 1, current_index);
            }

            // handling epsilon_transions of '?'
            // we have 2 options
            // option 1: A?B
            // option 2: (AB)? and this one will use 'current_index = pop'
            else if( regular_expression[iii + 1] == '?' )
            {
                epsilon_transtions->add_edge(current_index, iii + 1);
            }

            // handling epsilon_transions of '+'
            // we have 2 options
            // option 1: AB+
            // option 2: (AB)+ and this one will use 'current_index = pop'
            else if( regular_expression[iii + 1] == '+' )
            {
                epsilon_transtions->add_edge(iii + 1, current_index);
            }
        }

        // handling '(', '*', '+', ')', '?', ']'
        switch(regular_expression[iii].toLatin1())
        {
            case '(':
            case '*':
            case '+':
            case ')':
            case '?':
            case ']':
                epsilon_transtions->add_edge(iii, iii + 1);
        }
    }
}

bool NFA::check_range(QString symbol, QChar _char)
{
    if( symbol[0] == '[' )
    {
        for (int iii = 1; iii < symbol.length() - 1; ++iii)
        {
            if( _char == symbol[iii] )
                return true;

            else if( symbol[iii] == '-' )
            {
                if( _char >= symbol[iii - 1] && _char <= symbol[iii + 1] )
                    return true;

                else if( symbol[1] == '^' )
                {
                    // TODO: this concept is wrong
                    return true;
                }
            }
        }
    }

    else if( symbol[0] == '\\' )
    {
        switch (symbol[1].toLatin1())
        {
            case 'd':
            {
                if ( _char >= '0' && _char <= '9' )
                    return true;
                break;
            }

            case 'D':
            {
                if ( !( _char >= '0' && _char <= '9' ) )
                    return true;
                break;
            }

            case 'w':
            {
                if ( ( _char >= '0' && _char <= '9' ) ||
                     ( _char >= 'A' && _char <= 'Z' ) ||
                     ( _char >= 'a' && _char <= 'z' ) ||
                       _char == '_' )
                    return true;
                break;
            }
        }
    }

    return false;
}

QList<int> * NFA::build_reachable_states(int root)
{
    // create list to store the nodes do match with str
    QList<int> *reachable_states = new QList<int>();

    if( dfs == NULL)
        dfs = new DirectedDFS(epsilon_transtions);

    else dfs->clear();

    // search from 'root'
    dfs->search(root);

    //store the indeces of the marked nodes
    for (int v = 0; v < epsilon_transtions->get_nodes_number(); v++)
    {
        if (dfs->is_marked(v))
            reachable_states->append(v);
    }

    return reachable_states;
}

QList<int> * NFA::build_reachable_states(QList<int>* root)
{
    // create list to store the nodes do match with str
    QList<int> *reachable_states = new QList<int>();

    if( dfs == NULL)
        dfs = new DirectedDFS(epsilon_transtions);

    else dfs->clear();

    // search from 'root'
    dfs->search(root);

    //store the indeces of the marked nodes
    for (int v = 0; v < epsilon_transtions->get_nodes_number(); v++)
    {
        if (dfs->is_marked(v))
            reachable_states->append(v);
    }

    return reachable_states;
}

bool NFA::recognizes(QString str)
{
    QList<int> *match_transisions = build_reachable_states(0);

// Compute possible NFA states for str[i+1]
    for (int i = 0; i < str.length(); i++)
    {
        //create list to store the match characters to the regular expression
        QList<int> *match = new QList<int>();

        //store the characters match with the regular expression
        foreach (int vertex, *match_transisions)
        {
            if (vertex < number_of_states)
            {
                if (regular_expression[vertex] == str[i] || regular_expression[vertex] == '.')
                {
                    match->append(vertex+1);
                }

                if (regular_expression[vertex] == ']')
                {
                    QString range ;
                    for (int iii = vertex; regular_expression[iii] != '['; iii--)
                    {
                        range = regular_expression[iii] + range;
                    }

                    range = '[' + range;

                    if (check_range(range, str[i]))
                        match->append(vertex+1);

                }
            }
        }

        match_transisions = build_reachable_states(match);
    }

    //final check if the string matches the regular expression or not
    //for (int v = 0; v < match_transisions->length(); v++)
    foreach (int vertex, *match_transisions)
    {
        if (vertex == number_of_states)
            return true;
    }
    return false;
}

void NFA::search( QFile file )
{

}

MAP* NFA::get_epsilon_transtions()
{
    return epsilon_transtions->get_nodes_list();
}

NFA::~NFA()
{
    delete epsilon_transtions;
}
