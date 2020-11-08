#include "functions.h"
#include "structures.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

std::ifstream& operator >> (std::ifstream& in, Edge& edge)
{

    char parenthesis1, comma1, comma2, parenthesis2;
    in >>parenthesis1 >> edge.begin >>   comma1 >> edge.end >> comma2 >> edge.weight >>parenthesis2;
    return in;
}

std::vector<Edge> read_input(std::string path)
{
    std::vector<Edge> edge_list;
    std::ifstream source(path);
    while(source)
    {
        char colon;
        Edge edge;
        source >> edge >> colon;
        edge_list.push_back(edge);
    }
    source.close();
    return edge_list;
}


std::ostream& operator << (std::ostream& str, const Edge& edge)
{
    str << "(" <<edge.begin <<", " << edge.end << ", " << edge.weight << ")";
    return str;
}



    std::vector<Edge> KruskalMST(std::vector<Edge> edge_list)
{

    std::vector<Edge> tree; /** defining tree as a vector of edges */
    auto edge_iterator = edge_list.begin();
    while (edge_iterator != edge_list.end()) /** stopping the loop once we have processed all of the edges or the tree was created */
    {

        auto beginNode = edge_iterator->begin; /** defining beginning vertex of an edge */
        auto endNode = edge_iterator->end; /** defining ending vertex of an edge */

        auto it = std::find_if(tree.begin(), tree.end(), [&](const Edge& edge) /** searching in a tree for the edge which contains the beginning of a given edge */
        {
            return edge.begin == beginNode || edge.end == endNode;
        });
        if (it == tree.end()) /** the given edge's beginning wasn't found in a tree */
        {
            tree.push_back(*edge_iterator); /** pushing back the given edge to a tree */
        }
        else /** the given edge's beginning was found in a tree */
        {
            /** We are looking for subtree which contains the given edge and we create the list of vertices it spans */
            bool ConnectedEdgesFound {true};
            std::set<int> ConnectedNodes; /** It guarantees uniqueness i. e. something that is already in a set won't be added once again */
            ConnectedNodes.insert(it->begin);
            ConnectedNodes.insert(it->end);

            while(ConnectedEdgesFound) /** Looking for edges connected with a given edge in subtree */
            {
                ConnectedEdgesFound = false;
                for (const auto& edge : tree) /** Iterating over all of the edges in a tree */
                {
                    auto beginNodeIt = ConnectedNodes.find(edge.begin); /** Checking if the beginning of a edge is in connected nodes */
                    auto endNodeIt = ConnectedNodes.find(edge.end); /** Checking if the end of a edge is in connected nodes */
                    /** If both of the nodes are in the ConnectedNodes set it means the the edge has already been added(it's nodes are in the set of ConnectedNodes).
                     * if neither beginning nor end are in the ConnectedNodes means that the edge is disconnected from the rest
                     * thus it means that we're interested in a situation where either beginning or end of an edge are in the ConnectedNodes set
                     */
                    if ((beginNodeIt != ConnectedNodes.end() && endNodeIt == ConnectedNodes.end()) or /** beginning is in the set but end isn't */
                    (beginNodeIt == ConnectedNodes.end() && endNodeIt != ConnectedNodes.end()))       /** end is in the set but beginning isn't */
                    {
                        ConnectedNodes.insert(edge.begin); /** inserting the found edge vertices into a set */
                        ConnectedNodes.insert(edge.end);
                        ConnectedEdgesFound = true; /** changing the value of boolean expression to continue the loop */
                    }
                }
            }
            if (ConnectedNodes.find(endNode) != ConnectedNodes.end()) /** The connection between the vertices of a given edge has been found thus we don't add the edge */
            {
            }
            else /** The connection between the vertices of a given edge hasn't been found thus we add the edge */
            {

                tree.push_back(*edge_iterator);
            }
        }
    edge_iterator++; /** Moving onto the next edge */
    }
return tree;
}




void write_output(std::string path, std::vector<Edge> result)
{
    std::ofstream target(path);

    if(target.is_open())
    {
        for (int i = 0; i < result.size(); i++)
        {

            target << result[i]<<", ";
        }
    }
    target.close();
}



