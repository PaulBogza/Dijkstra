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
        for(auto i : unvisitedNodes){
            std::cout << i->name << std::endl;
            if(i->neighbours.at(0) != nullptr){
                std::cout << i->neighbours.at(0)->weight << std::endl;
            }
            if(i->neighbours.at(1) != nullptr){
                std::cout << i->neighbours.at(1)->weight << std::endl;
            }
        }
        return std::make_pair(path, distance);
    }
    

    return std::make_pair(path, distance);
}