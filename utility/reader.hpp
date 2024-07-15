#ifndef reader
#define reader 

#include "../classes/node.hpp"
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::vector<Node>>* readFile(std::string);

#endif