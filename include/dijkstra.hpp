#ifndef dijkstra
#define dijkstra

#include <unordered_map>
#include <string>
#include <vector>
#include "node.hpp"

std::vector<Node>* findPath(std::unordered_multimap<std::string, Node>*, Node*, Node*);

#endif