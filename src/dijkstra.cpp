#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> &graph, const Node *start, const Node *dest){
    std::vector<Node*> visitedNodes; 
    std::vector<Node*> path;
    std::vector<Node*> tempPath;
    Node *currentNode;
    Node *startingNode;
    Node *tempNode;
    int pathDistance = 0;
    int tempDistance = 0;
    int currentLowestWeight = 999;
	
	for(int i = 0; i < graph.size(); i++){
		std::cout << graph.at(i) << " " << graph.at(i)->name << std::endl;
		for(auto j : graph.at(i)->neighbours){
			if(j->station != nullptr){
				std::cout << j->station << " " << j->station->name << std::endl;
			}
		}
	}	

    if(!graph.empty()){
        for(auto i : graph){
            if(i->name == start->name){
                startingNode = &*i;
                currentNode = startingNode;
                break;
            }
		}
    }
	path.emplace_back(startingNode);
    
    if(!graph.empty()){
        do{
            if(currentNode->neighbours.size() > 0){
				//std::cout << currentNode << " " << currentNode->name << std::endl;
                for(auto i : currentNode->neighbours){
					if(i->station != nullptr && i->station->distance > pathDistance + i->weight){
						i->station->distance = pathDistance + i->weight;
					}
                    if((i->station != nullptr) && (i->station->visited == false) &&
						(i->weight < currentLowestWeight)){ 
                        tempNode = &*i->station;
                        currentLowestWeight = i->weight;
                    }
                } 
				currentNode->visited = true;
				visitedNodes.emplace_back(currentNode);
				path.emplace_back(tempNode);
				pathDistance += currentLowestWeight;
				currentNode = tempNode;
				currentLowestWeight = 999;
				if(currentNode->name == dest->name){
					break;
				}
			}
			else{
				break;
			}
        }while(visitedNodes.size() != graph.size());
        
        return std::make_pair(path, pathDistance);
    }
    return std::make_pair(path, pathDistance);
}
