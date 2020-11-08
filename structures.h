/** @file */
#ifndef SPANNING_TREE_FOCP_PROJECT_STRUCTURES_H
#define SPANNING_TREE_FOCP_PROJECT_STRUCTURES_H
#include <vector>
#include <string>
#include <list>


/**
*@brief structure of a edge of a graph
 *
 * Structure which contains an edge of a graph
 * @param constructor which constructs the beginning and end of an edge and it's weight
 * @param empty constructor used to initialize an edge in read_input function
 */

struct Edge{

    Edge(int begin_,  int end_, double weight_):
        begin(begin_),
        end(end_),
        weight(weight_)
        {}
    Edge() = default;
    int begin;
    int end;
    double weight;

};


#endif //SPANNING_TREE_FOCP_PROJECT_STRUCTURES_H
