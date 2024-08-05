#ifndef reader
#define reader 

#include "node.hpp"
#include <unordered_map>
#include <string>
#include <vector>

void createGraph(std::unordered_map<std::string, Node>*, std::string);
void parseAndAdd(std::string, std::unordered_map<std::string, Node>*);

#endif