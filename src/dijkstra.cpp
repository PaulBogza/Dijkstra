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
    int tempDistance = 0;
    int tempWeight = 999;

    if(!unvisitedNodes.empty()){
        //find shortest path
        do{
            for(auto i : currentNode.neighbours){
                if(i->weight < tempWeight){
                    tempWeight = i->weight;
                    currentNode = i;
                }
            }
        }while(!unvisitedNodes.empty() || currentNode.name !=  dest->name || !tempWeight == 999);
        
        return std::make_pair(path, distance);
    }
    

    return std::make_pair(path, distance);
}