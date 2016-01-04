#include "dfa_search.h"

DFA_Search::DFA_Search(dfa_digraph::DirectedGraph_DFA *digraph )
{
    this->digraph = digraph;

    dfa = digraph->get_nodes_list();

    reachables = new QList<int>;
}

bool DFA_Search::search(QString str)
{
      int index = 1;
      int reachable_index = 0;

      // append the root node
      (*reachables).append(0);

      // prepare the root node
      // append its connections into the 'reachables'
      foreach (int node_index, (*dfa)[reachables->at(reachables->at(0))].connections)
      {
          reachable_index++;
          reachables->insert(reachable_index, node_index);
      }

      for (int iii = 0; iii < str.length(); )
      {
//          if( index >= reachables->length() || iii == str.length() - 1 )
//          {
//              if( (*dfa)[reachables->at(index - 1)].is_finial_state )
//                  return true;

//              else
//                  return false;
//          }

          reachable_index = index;

          // get the match transition
          QString match = (*dfa)[reachables->at(index)].match_transitions[0];

          if(  match[0] == str[iii] ||
               match[0] == '.'      ||
             ( match[0] == '[' && NFA::check_range(match, str[iii]) ) )
          {
              foreach (int node_index, (*dfa)[reachables->at(reachables->at(index))].connections)
              {
                  reachable_index++;
                  reachables->insert(reachable_index, node_index);
              }

              iii++;

//              if( index == reachables->length() - 1 )
//              {
//                  if( (*dfa)[reachables->at(index)].is_finial_state ||
//                          iii == str.length() - 1 )
//                      return true;

//                  else
//                      return false;
//              }
          }

          else if( index <= reachables->length() - 1 )
          {
              return false;
          }

//          if( index < reachables->length() - 1 )
            index++;

          if( index >= reachables->length() )
          {
              if( (*dfa)[reachables->at(index - 1)].is_finial_state )
                  return true;

              else
                  return false;
          }
      }

      if ( (*dfa)[reachables->at(index) - 1].is_finial_state )
      {
          return true;
      }

      else
          return false;

//    return true;
}
