#include "nfa_to_dfa.h"
//#include <QVector>
//#include <iterator>

//QVector<int> * build_reachable_states(QVector<int>* root)
//{
//    QVector<int> *reachable_states = new QVector<int>(); // create list to store the nodes do match with str
//    DirectedDFS *dfs = new DirectedDFS(epsilon_transions, root); // initialize object dfs

////    reachable_states->resize(0);

//    //store the indeces of the marked nodes
//    for (int v = 0; v < epsilon_transions->nodes_number; v++)
//    {
//        if (dfs->mark(v))
//            reachable_states->append(v);
//    }

//    return reachable_states;
//}

//QVector<int> * build_reachable_states(int root)
//{
//    QVector<int> *reachable_states = new QVector<int>(); // create list to store the nodes do match with str
//    DirectedDFS *dfs = new DirectedDFS(epsilon_transions, root); // initialize object dfs

//    //store the indeces of the marked nodes
//    for (int v = 0; v < epsilon_transions->nodes_number; v++)
//    {
//        if (dfs->mark(v))
//            reachable_states->append(v);
//    }

//    return reachable_states;
//}

NFA_TO_DFA::NFA_TO_DFA(digraph::DirectedGraph* nfa_digraph, int root)
{
    this->nfa_digraph = nfa_digraph;

    this->nfa = nfa_digraph->get_nodes_list();
    this->root = root;

    dfs = new DirectedDFS_DFA(nfa_digraph);
    dfa_digraph = new dfa_digraph::DirectedGraph_DFA();
    this->dfa = dfa_digraph->get_nodes_list();

    nfa_dfa_nodes = new QVector<int>(nfa_digraph->get_nodes_list()->length(), -1);
}

void NFA_TO_DFA::build_dfa()
{
    int tail = root;

    QList<int>* start_nodes = new QList<int>;

    // Create Initial Node
    dfa_digraph->create_node();
    (*nfa_dfa_nodes)[root] = root;
    start_nodes->append(root);

    for(int iii = 0; iii < start_nodes->length(); iii++ )
    {
        if( dfs->get_reachable_states()->length() != 0 )
            dfs->clear();

        dfs->search((*start_nodes)[iii]);

        foreach (int node, *dfs->get_reachable_states())
        {
            if( node == nfa->size() - 1 )
            {
                // mark current node as final node
                (*dfa)[iii].is_finial_state = true;
            }

            else if( node != nfa->size() - 1 && nfa_dfa_nodes->at(node) == -1 )
            {
                // Build new Node
                dfa_digraph->create_node();

                tail = dfa->last().index;
                (*nfa_dfa_nodes)[node] = tail;

                // make connection
                dfa_digraph->add_edge(iii, tail);

                // connect to coresponding alpha in the regular expression
                (*dfa)[tail].match_transitions.append(node);

                start_nodes->append(node + 1);
            }

            else if(nfa_dfa_nodes->at(node) != -1)
            {
                dfa_digraph->add_edge(iii, nfa_dfa_nodes->at(node));
            }
        }
    }
}

    // build our DFA here
//    QVector<int> *dfa = new QVector<int>;

    // marked list
//    QVector<bool> *marked = new QVector<bool>;

    // start with first node from dfa
//    dfa->append(0);
    // mark it as visited
//    marked->insert(0, true);

//    QVector<int> *T = new QVector<int>;
//    QVector<int> *new_cases = new QVector<int>;

//    MAP* nodes_list = nfa->get_nodes_list();

//    while(true /*while dfa has unmarked states*/)
//    {
//        T->resize(0);
//        new_cases->resize(0);

//        foreach (QVector<int> *connections, *nodes_list)
//        {
            // add every reachable node has children to T
            // add all nodes that has no children to new_cases
//        }
//    };

//}


//void NFA_TO_DFA::build_reachable_states(int node)
//{
//    (*marked)[node] = true;

//    if((*nfa)[node]->length() == 0)
//    {
//        reachable_states->append(node);
//        qDebug("%i", node);
//        return;
//    }

//    foreach(int connection, *(*nfa)[node])
//    {
//        if( !marked->at(connection) )
//            build_reachable_states(connection);
//    }
//}

//void NFA_TO_DFA::build_reachable_states(QVector<int>* nodes)
//{
//    foreach (int node, *nodes)
//    {
//        build_reachable_states(node);
//    }
//}

//void DirectedDFS::dfs(int node)
//{
//    MAP* nodes_list = digraph->get_nodes_list();

//    foreach (int child, *(*nodes_list)[node])
//    {
//        if(!marked->at(child))
//        {
//            dfs(child);
//        }
//    }
//}

