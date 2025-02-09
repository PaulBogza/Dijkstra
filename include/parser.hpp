#ifndef reader
#define reader 

#include "node.hpp"
#include <unordered_map>
#include <string>
#include <vector>

void createGraph(std::vector<Node*>&, std::string);
void parseAndAdd(std::string, std::vector<Node*>&);

#endif