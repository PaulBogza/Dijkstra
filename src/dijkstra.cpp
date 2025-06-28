#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

Node* backTracking(std::vector<Node*> &tempPath, int &tempDistance, Node* currentNode){
    for(int i = tempPath.size()-1; i > 0; i--){
        for(int j = 0; j < tempPath.at(i)->neighbours.size(); j++){
            if(tempPath.at(i)->neighbours.at(j)->station != nullptr && tempPath.at(i)->neighbours.at(j)->station->visited == false){
                currentNode = tempPath.at(i)->neighbours.at(j)->station;
                tempDistance -= tempPath.at(i)->neighbours.at(j)->weight;
                return currentNode;
            }
        }
    }
    return currentNode;
}

std::tuple<std::vector<Node*>, int> Dijkstra(const std::vector<Node*> &graph, const Node *start, const Node *dest, std::vector<Node*> &visitedNodes){
    std::vector<Node*> tempPath;
    Node *currentNode;
    Node *startingNode;
    Node *tempNode;
    int tempDistance = 0;
    int currentLowestWeight = 999;
    std::vector<Node*> candidates;

    if(!graph.empty()){
        for(int i = 0; i < graph.size(); i++){
            if(graph.at(i)->name == start->name){
                startingNode = graph.at(i);
                currentNode = graph.at(i);
                break;
            }
		}
    }
    startingNode->distance = 0;
	tempPath.emplace_back(startingNode);

    if(!graph.empty()){
        do{
            if(currentNode->name == dest->name) break;
            for(int i = 0; i < currentNode->neighbours.size(); i++){
                if(currentNode->neighbours.at(i)->station != nullptr){
                    //update distance from starting node to this node if shorter one is found
                    if(currentNode->neighbours.at(i)->station->distance > tempDistance + currentNode->neighbours.at(i)->weight){
                        currentNode->neighbours.at(i)->station->distance = tempDistance + currentNode->neighbours.at(i)->weight;
                    }
                    //update lowest weight to next node
                    if(currentNode->neighbours.at(i)->station->visited == false && currentNode->neighbours.at(i)->weight <= currentLowestWeight){ 
                        tempNode = currentNode->neighbours.at(i)->station;
                        currentLowestWeight = currentNode->neighbours.at(i)->weight;
                    }
                    /*
                    if(currentNode->neighbours.at(i)->station->visited == false && currentNode->neighbours.at(i)->weight == currentLowestWeight){
                        candidates.emplace_back(tempNode);
                        candidates.emplace_back(currentNode->neighbours.at(i)->station);
                    }
                    */
                }
            }
            //TODO: Backtracking for final stops
            if(currentNode->neighbours.at(0)->station == nullptr || currentNode->neighbours.at(1)->station == nullptr){
                currentNode = backTracking(tempPath, tempDistance, currentNode);
            }
            else{
                currentNode->visited = true;
                visitedNodes.emplace_back(currentNode);
                tempDistance += currentLowestWeight;
                currentLowestWeight = 999;
                currentNode = tempNode;
                tempPath.emplace_back(currentNode);
                /*
                if(candidates.size() > 1){
                    srand(time(0));
                    int num = rand() % candidates.size();
                    currentNode = candidates.at(num);
                }
                else{
                    currentNode = tempNode;
                }
                tempPath.emplace_back(currentNode);
                */
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

    //do{
        result = Dijkstra(graph, start, dest, visitedNodes);
    //    tempDist = std::get<1>(tempResult);
        //if(tempDist <= dist){
    //        result.swap(tempResult);
        //}
    //}while(visitedNodes.size() != graph.size());

    return result;
}
