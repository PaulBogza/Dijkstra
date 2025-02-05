#ifndef dijkstra
#define dijkstra

#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>
#include "node.hpp"

std::tuple<std::vector<Node>, int> findPath(const std::unordered_multimap<std::string, Node*>*, const Node*, const Node*);

#endif