#ifndef reader
#define reader 

#include "../classes/node.hpp"
#include <map>
#include <string>
#include <vector>

void createGraph(std::map<std::string, std::vector<Node>>*, std::string);
void parseLine(int, std::string);

#endif