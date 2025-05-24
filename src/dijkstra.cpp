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
		for(int j = 0; j< graph.at(i)->neighbours.size(); j++){
			if(graph.at(i)->neighbours.at(j)->station != nullptr){
				std::cout << graph.at(i)->neighbours.at(j)->station << " " << graph.at(i)->neighbours.at(j)->station->name << std::endl;
			}
		}
	}	

    if(!graph.empty()){
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i)->name == start->name){
                startingNode = graph.at(i);
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
                for(int i = 0; i < currentNode->neighbours.size(); i++){
					if(currentNode->neighbours.at(i)->station != nullptr &&
						currentNode->neighbours.at(i)->station->distance > 
						pathDistance + currentNode->neighbours.at(i)->weight){
						currentNode->neighbours.at(i)->station->distance = pathDistance + currentNode->neighbours.at(i)->weight;
					}
                    if((currentNode->neighbours.at(i)->station != nullptr) &&
						(currentNode->neighbours.at(i)->station->visited == false) &&
						(currentNode->neighbours.at(i)->weight < currentLowestWeight)){ 
                        tempNode = currentNode->neighbours.at(i)->station;
                        currentLowestWeight = currentNode->neighbours.at(i)->weight;
                    }
                } 
				currentNode->visited = true;
				visitedNodes.emplace_back(currentNode);
				path.emplace_back(tempNode);
				pathDistance += currentLowestWeight;
				currentNode = tempNode;
				currentLowestWeight = 999;
			}
			else{
				break;
			}
        }while(visitedNodes.size() != graph.size());
        
        return std::make_pair(path, pathDistance);
    }
    return std::make_pair(path, pathDistance);
}
