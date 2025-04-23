#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> &graph, const Node *start, const Node *dest){
    std::vector<Node*> unvisitedNodes = graph;
    std::vector<Node*> visitedNodes; 
    std::vector<Node*> path;
    std::vector<Node*> tempPath;
    Node currentNode;
    Node startingNode;
    Node tempNode;
    int distance = 999;
    int tempDistance = 0;
    int tempWeight = 999;

    if(!unvisitedNodes.empty()){
        for(auto i : unvisitedNodes){
            if(i->name == start->name){
                startingNode = *i;
                currentNode = startingNode;
                break;
            }
        }
    }

    if(!unvisitedNodes.empty()){
        do{
            if(currentNode.neighbours.size() > 0){
                for(auto i : currentNode.neighbours){
                    //std::cout << i->station->name << std::endl;
                    if((i->station->visited == false) && (i->weight < tempWeight)){
                        tempWeight = i->weight;    
                        tempNode = *i->station;
                    }
                }
                tempPath.emplace_back(&currentNode);
                tempDistance += tempWeight;
                currentNode = tempNode;
            }
            currentNode.visited = true;
            visitedNodes.emplace_back(&currentNode);
        }while(unvisitedNodes.size() != visitedNodes.size());
        
        path = tempPath;
        distance = tempDistance;

        return std::make_pair(path, distance);
    }
    
    return std::make_pair(path, distance);
}