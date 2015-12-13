//#include "nfa_to_dfa.h"
//#include <QVector>
//#include <iterator>

////QVector<int> * build_reachable_states(QVector<int>* root)
////{
////    QVector<int> *reachable_states = new QVector<int>(); // create list to store the nodes do match with str
////    DirectedDFS *dfs = new DirectedDFS(epsilon_transions, root); // initialize object dfs

//////    reachable_states->resize(0);

////    //store the indeces of the marked nodes
////    for (int v = 0; v < epsilon_transions->nodes_number; v++)
////    {
////        if (dfs->mark(v))
////            reachable_states->append(v);
////    }

////    return reachable_states;
////}

////QVector<int> * build_reachable_states(int root)
////{
////    QVector<int> *reachable_states = new QVector<int>(); // create list to store the nodes do match with str
////    DirectedDFS *dfs = new DirectedDFS(epsilon_transions, root); // initialize object dfs

////    //store the indeces of the marked nodes
////    for (int v = 0; v < epsilon_transions->nodes_number; v++)
////    {
////        if (dfs->mark(v))
////            reachable_states->append(v);
////    }

////    return reachable_states;
////}

//NFA_TO_DFA::NFA_TO_DFA(MAP* nfa, int root)
//{
//    this->nfa = nfa;
//    this->root = root;
//    reachable_states = new QVector<int>;
//    marked = new QVector<int>(nfa->size());
//}

//void NFA_TO_DFA::build_dfa()
//{
//    int current_node = this->root;

//    build_reachable_states(current_node);

//    Node *head = NULL;
//    Node *tail = NULL;

//    // Create Initial Node
//    head = new Node();
//    dfa->insert(-1, head);

//    foreach (int node, *reachable_states)
//    {
//        // TODO: check if this node already created
//        if( node != nfa->size() )
//        {
//            // make connection
//            head->next_state.append(node);

//            // Build new Node
//            tail = new Node();
//            dfa->insert(node, child_node);
//        }


//        if( node == nfa->size() )
//        {
//            _node->is_finial_state = true;
//        }
//    }



//    // restart vectors like creating new one
//    reachable_states->resize(0);
//    marked->resize(0);
//}

//    // build our DFA here
////    QVector<int> *dfa = new QVector<int>;

//    // marked list
////    QVector<bool> *marked = new QVector<bool>;

//    // start with first node from dfa
////    dfa->append(0);
//    // mark it as visited
////    marked->insert(0, true);

////    QVector<int> *T = new QVector<int>;
////    QVector<int> *new_cases = new QVector<int>;

////    MAP* nodes_list = nfa->get_nodes_list();

////    while(true /*while dfa has unmarked states*/)
////    {
////        T->resize(0);
////        new_cases->resize(0);

////        foreach (QVector<int> *connections, *nodes_list)
////        {
//            // add every reachable node has children to T
//            // add all nodes that has no children to new_cases
////        }
////    };

////}


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

////void DirectedDFS::dfs(int node)
////{
////    MAP* nodes_list = digraph->get_nodes_list();

////    foreach (int child, *(*nodes_list)[node])
////    {
////        if(!marked->at(child))
////        {
////            dfs(child);
////        }
////    }
////}

