#ifndef dijkstra
#define dijkstra

#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>
#include "node.hpp"

std::tuple<std::vector<Node*>,int>findPath(const std::vector<Node*>*, const Node*, const Node*);

#endif