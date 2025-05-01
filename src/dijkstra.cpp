#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> &graph, const Node *start, const Node *dest){
    //std::vector<Node*> unvisitedNodes = graph;
    std::vector<Node*> visitedNodes; 
    std::vector<Node*> path;
    std::vector<Node*> tempPath;
    Node *currentNode;
    Node *startingNode;
    Node *tempNode;
    int distance = 999;
    int tempDistance = 0;
    int currentLowestWeight = 999;
	
    std::cout << &graph.at(0) << std::endl;
    
    if(!graph.empty()){
        for(auto i : graph){
            if(i->name == start->name){
                startingNode = &*i;
                currentNode = startingNode;
                break;
            }
	}
    }
    
    if(!graph.empty()){
        do{
            if(currentNode->neighbours.size() > 0){
                for(auto i : currentNode->neighbours){
                    if(i->station != nullptr && i->station->visited == false){
                	std::cout << i->station->name << std::endl;
                        std::cout << i->station->visited << std::endl;
                        std::cout << &i->station << std::endl;
                    }
                    if((i->station != nullptr) && (i->station->visited == false) && (i->weight < currentLowestWeight)){ 
                        tempNode = &*i->station;
                        currentLowestWeight = i->weight;
                    }
                } 
            }
            currentLowestWeight = 999;
            currentNode->visited = true;
            std::cout << currentNode->name << std::endl;
            std::cout << currentNode->visited << std::endl;
            std::cout << &currentNode << std::endl;
            currentNode = tempNode;
        }while(currentNode->name != dest->name);
        
        return std::make_pair(path, distance);
    }
    return std::make_pair(path, distance);
}
