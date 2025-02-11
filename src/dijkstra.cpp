#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> &graph, const Node *start, const Node *dest){
    std::vector<Node*> unvisitedNodes = graph; 
    std::vector<Node*> path;
    std::vector<Node*> tempPath;
    Node currentNode = *start;
    Node startingNode = *start;
    int distance = 999;
    int tempDistance = 999;

    if(!unvisitedNodes.empty()){
        //find shortest path
        return std::make_pair(path, distance);
    }
    

    return std::make_pair(path, distance);
}