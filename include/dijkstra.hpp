#ifndef dijkstra
#define dijkstra

#include <unordered_map>
#include <string>
#include <vector>
#include "node.hpp"

std::vector<Node>* findPath(const std::unordered_multimap<std::string, Node*>*, const Node*, const Node*);

#endif