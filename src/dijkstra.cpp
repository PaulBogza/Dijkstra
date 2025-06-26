#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> Dijkstra(const std::vector<Node*> &graph, const Node *start, const Node *dest, std::vector<Node*> &visitedNodes){
    std::vector<Node*> tempPath;
    Node *currentNode;
    Node *startingNode;
    Node *tempNode;
    int tempDistance = 0;
    int currentLowestWeight = 999;

    if(!graph.empty()){
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i)->name == start->name){
                startingNode = graph.at(i);
                currentNode = graph.at(i);
                break;
            }
		}
    }
	tempPath.emplace_back(startingNode);

    if(!graph.empty()){
        do{
            if(currentNode->neighbours.size() > 0){
                for(int i = 0; i < currentNode->neighbours.size(); i++){
                    if(currentNode->neighbours.at(i)->station != nullptr){
                        //update distance from starting node to this node if shorter one is found
                        if(currentNode->neighbours.at(i)->station->distance > tempDistance + currentNode->neighbours.at(i)->weight){
                            currentNode->neighbours.at(i)->station->distance = tempDistance + currentNode->neighbours.at(i)->weight;
                        }
                        //update lowest weight to next node
                        if((currentNode->neighbours.at(i)->station->visited == false) && (currentNode->neighbours.at(i)->weight < currentLowestWeight)){ 
                            tempNode = currentNode->neighbours.at(i)->station;
                            currentLowestWeight = currentNode->neighbours.at(i)->weight;
                        }
                    }
                } 
                currentNode->visited = true;
                visitedNodes.emplace_back(currentNode);
                tempPath.emplace_back(tempNode);
                tempDistance += currentLowestWeight;
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
    }
    return std::make_pair(tempPath, tempDistance);
}

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> &graph, const Node *start, const Node *dest){
    std::vector<Node*> visitedNodes; 
    std::vector<Node*> path;
    std::tuple<std::vector<Node*>, int> tempResult;
    std::tuple<std::vector<Node*>, int> result(path, 999);
    int tempDist = 0;
    int dist = 0;
    dist = std::get<1>(result);

    do{
        tempResult = Dijkstra(graph, start, dest, visitedNodes);
        tempDist = std::get<1>(tempResult);
        if(tempDist <= dist){
            result.swap(tempResult);
        }
    }while(visitedNodes.size() != graph.size());

    return result;
}
