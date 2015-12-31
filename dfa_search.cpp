#include "dfa_search.h"

DFA_Search::DFA_Search(dfa_digraph::DirectedGraph_DFA *digraph, QString *regex )
{
    this->digraph = digraph;
    this->regex = regex;

    dfa = digraph->get_nodes_list();
}

bool DFA_Search::search(QString str)
{
      bool flag = false;
      int index = 0;

      for (int counter = 0; counter < str.length(); counter++)
      {
          foreach (int node_index, (*dfa)[index].connections)
          {
              if(str[counter] == (*dfa)[node_index].match_transitions[0][0]||
                      (*dfa)[node_index].match_transitions[0][0] == '.')
              {
                  if (counter == str.length()-1)
                  {
                      if ((*dfa)[node_index].is_finial_state)
                      {
                          flag = true;
                          break;
                      }
                  }
                  index = (*dfa)[node_index].index;
                  break;
              }
              else if ((*dfa)[node_index].match_transitions[0][0] == '[')
              {
//                  QString range ;
//                  for (int iii = 0; (*dfa)[node_index].match_transitions[0][iii] != ']'; iii++)
//                  {
//                      range = (*dfa)[node_index].match_transitions[0][iii] + range;
//                  }

//                  range = range + ']';

                  if (NFA::check_range((*dfa)[node_index].match_transitions[0], str[counter]))
                  {
                      if (counter == str.length()-1)
                      {
                          if ((*dfa)[node_index].is_finial_state)
                          {
                              flag = true;
                              break;
                          }
                      }
                      index = (*dfa)[node_index].index;
                      break;
                  }
                  else
                      return false;

              }

          }
      }
      return flag;

}
bool DFA_Search::search(QString str)
{
      bool flag = false;
      int index = 0;

      for (int counter = 0; counter < str.length(); counter++)
      {
          foreach (int node_index, (*dfa)[index].connections)
          {
              if(str[counter] == (*dfa)[node_index].match_transitions[0][0]||
                      (*dfa)[node_index].match_transitions[0][0] == '.')
              {
                  if (counter == str.length()-1)
                  {
                      if ((*dfa)[node_index].is_finial_state)
                      {
                          flag = true;
                          break;
                      }
                  }
                  index = (*dfa)[node_index].index;
                  break;
              }
              else if ((*dfa)[node_index].match_transitions[0][0] == '[')
              {
//                  QString range ;
//                  for (int iii = 0; (*dfa)[node_index].match_transitions[0][iii] != ']'; iii++)
//                  {
//                      range = (*dfa)[node_index].match_transitions[0][iii] + range;
//                  }

//                  range = range + ']';

                  if (NFA::check_range((*dfa)[node_index].match_transitions[0], str[counter]))
                  {
                      if (counter == str.length()-1)
                      {
                          if ((*dfa)[node_index].is_finial_state)
                          {
                              flag = true;
                              break;
                          }
                      }
                      index = (*dfa)[node_index].index;
                      break;
                  }
                  else
                      return false;

              }

          }
      }
      return flag;

}
