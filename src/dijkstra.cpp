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

	/*
	for(int i = 0; i < graph.size(); i++){
		for(int j = i+1; j < graph.size(); j++){
			for(int k = 0; k < graph.at(j)->neighbours.size(); k++){
				if(graph.at(j)->neighbours.at(k)->station != nullptr && 
						graph.at(i)->name == graph.at(j)->neighbours.at(k)->station->name){
					std::cout << graph.at(i) << " " << graph.at(i)->name << std::endl;
					std::cout << graph.at(j)->neighbours.at(k)->station << " " 
					<< graph.at(j)->neighbours.at(k)->station->name << std::endl;
				}
			}
		}
	}
	*/

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
                    if((i->station != nullptr) && (i->station->visited == false) && 
						(i->weight < currentLowestWeight)){ 
                        tempNode = &*i->station;
                        currentLowestWeight = i->weight;
                    }
                } 
            }
            currentLowestWeight = 999;
            currentNode->visited = true;
			visitedNodes.emplace_back(currentNode);
            //std::cout << currentNode->name << std::endl;
            //std::cout << currentNode->visited << std::endl;
            //std::cout << &currentNode << std::endl;
            currentNode = tempNode;
        }while(visitedNodes.size() != graph.size());
        
        return std::make_pair(path, distance);
    }
    return std::make_pair(path, distance);
}
