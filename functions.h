/** @fparam_count */
#ifndef SPANNING_TREE_FOCP_PROJECT_FUNCTIONS_H
#define SPANNING_TREE_FOCP_PROJECT_FUNCTIONS_H

#include "structures.h"

/**
 * A function that causes overload of operator >>. It's used to load data into edges in proper format.
 * @param in
 * @param edge
 * @return ifstream&
 */

std::ifstream& operator >> (std::ifstream& in, Edge& edge);

/**
 * The function uses fstream to read from input file and overload of operator >> to save data to vector of read edges
 * @param a path in a form of a string
 * @return vector of read edges
 */
std::vector<Edge> read_input(std::string path);

/**
 * A function that causes overload of operator <<. It's used to print edges in a proper format.
 * @param str
 * @param edge
 * @return ostream&
 */
std::ostream& operator << (std::ostream& str, const Edge& edge);

/**
 * The function uses fstream to write to output file
 * @param a path in form of a string
 * @param result of the KruskalMST algorithm in a form of vector of edges
 */
void write_output(std::string path, std::vector<Edge> result);

/**
 * The functions applies Kruskal's algorithm to find the minimum spanning tree from a sorted list of edges.
 * @param a list of edges
 * @return minimal spanning tree
 */
std::vector<Edge> KruskalMST(std::vector<Edge> edge_list);


#endif

