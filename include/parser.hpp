#ifndef reader
#define reader 

#include "../include/node.hpp"
#include <map>
#include <string>
#include <vector>

void createGraph(std::map<std::string, std::vector<Node>>*, std::string);
void parseAndAdd(int, std::string, std::map<std::string, std::vector<Node>>*);

#endif