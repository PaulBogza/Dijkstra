#ifndef dijkstra
#define dijkstra

#include <unordered_map>
#include <string>
#include <vector>
#include <tuple>
#include "node.hpp"

std::tuple<std::vector<Node*>, int>findPath(const std::vector<Node*>&, const Node*, const Node*);
std::tuple<std::vector<Node*>, int>Dijkstra(const std::vector<Node*>&, const Node*, const Node*, std::vector<Node*>&);
Node* backTracking(std::vector<Node*>&, int&, Node*);
#endif
