#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> &graph, const Node *start, const Node *dest){
    std::vector<Node*> unvisitedNodes = graph;
    std::vector<Node*> visitedNodes; 
    std::vector<Node*> path;
    std::vector<Node*> tempPath;
    Node currentNode = *start;
    Node startingNode = *start;
    Node tempNode;
    int distance = 999;
    int tempDistance = 0;
    int tempWeight = 999;

    std::cout << unvisitedNodes.at(0)->name << std::endl;

    if(!unvisitedNodes.empty()){
        do{
            for(auto i : currentNode.neighbours){
                if((i->station->visited == false) && (i->weight < tempWeight)){
                    tempWeight = i->weight;    
                    tempNode = *i->station;
                }
            }
            currentNode.visited = true;
            visitedNodes.emplace_back(&currentNode);
            tempPath.emplace_back(&currentNode);
            tempDistance += tempWeight;
            currentNode = tempNode;
        }while(unvisitedNodes.size() != visitedNodes.size());
        
        path = tempPath;
        distance = tempDistance;

        return std::make_pair(path, distance);
    }
    
    return std::make_pair(path, distance);
}