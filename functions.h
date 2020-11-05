#ifndef SPANNING_TREE_FOCP_PROJECT_FUNCTIONS_H
#define SPANNING_TREE_FOCP_PROJECT_FUNCTIONS_H

#include "structures.h"
#include <fstream>
#include <string>
#include <vector>
/**
 * @brief A function to read from input file
 *
 * The function uses fstream to read from input file
 * @param a path in a form of a string
 * @return vector of read strings
 */
std::vector<std::string> read_input (std::string path);

/**
 * @brief A function to write to output file
 *
 * The function uses fstream to write to output file
 * @param a path in form of a string
 * @param a reference to vector of read lines
 */
 void write_output (std::string path, std::vector<std::string>& line);

/**
 * @brief A function used to conduct depth first search in a graph
 *
 * The function uses depth first search to traverse through graph
 * @param is node pointing to another node
 */

void dfs (node* node);
#endif //SPANNING_TREE_FOCP_PROJECT_FUNCTIONS_H

