/** @file */
#ifndef SPANNING_TREE_FOCP_PROJECT_STRUCTURES_H
#define SPANNING_TREE_FOCP_PROJECT_STRUCTURES_H
#include <vector>

/**
 * @brief structure of an edge of a graph
 *
 * Structure which contains parameters of an edge of a graph
 * @param contains weight of an edge
 * @param pointer to a next node
 *
 * @brief edge constructor
 *
 * A constructor which assigns weight and next node to an edge
 */
struct edge
{
    float weight;
    struct node* next;
    edge(float w, node* n){
        weight = w;
        next = n;
    }
};


/**
 * @brief structure of a node of a graph
 *
 * Structure which contains parameters of a node of a graph
 * @param contains value assigned to a node
 * @param vector of edges connected to a node
 * @param boolean expression to avoid getting caught in infinite cycles
 *
 * @brief Node constructor
 *
 * A constructor which assigns a value to a node
 *
 * @brief A function used to connect two nodes
 *
 * The function uses edges to connect two nodes
 * @param a weight in a form of floating point number
 * @param pointer to next node
 */


struct node
{
    int value;
    std::vector<edge> edges;
    bool visited = false;

    node(float v){
        value = v;
    }
    void connect(float w, node* next)
    {
        edge e(w, next);
        edges.push_back(e);
    }
};


#endif //SPANNING_TREE_FOCP_PROJECT_STRUCTURES_H
