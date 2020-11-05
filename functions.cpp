#include "functions.h"
#include "structures.cpp"
#include <iostream>
std::vector<std::string> read_input(std::string path){
    std::ifstream source(path);

    std::vector<std::string> line;
    std::string temporary;

    if (source.is_open())
    {
        while (getline(source, temporary))
        {
            line.push_back(temporary);
        }
        source.close();
    }
    return line;
}

void write_output(std::string path, std::vector<std::string>& line)
{
    std::ofstream target(path);

    if(target.is_open())
    {
        for (int i = 0; i < line.size(); i++)
        {
            target << line[i] << std::endl;
        }
    }
    target.close();
}

void dfs(node* node)
{
    std::cout << node->value <<std::endl;
    node->visited = true;

    for (int i = 0; i < node->edges.size(); i++)
    {
        if (!node->edges[i].next->visited)
        {
            dfs(node->edges[i].next);
        }
    }
}

