#ifndef reader
#define reader 

#include "node.hpp"
#include <map>
#include <string>
#include <vector>

void createGraph(std::map<std::string, std::vector<Node>>*, std::string);
void parseAndAdd(std::string, std::map<std::string, std::vector<Node>>*);

#endif