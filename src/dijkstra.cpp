#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

Node* backTracking(std::vector<Node*> &tempPath, Node* startingNode, Node* currentNode){
    for(int i = tempPath.size()-1; i > 0; i--){
        for(int j = 0; j < tempPath.at(i)->neighbours.size(); j++){
            if(tempPath.at(i)->neighbours.at(j)->station != nullptr && tempPath.at(i)->neighbours.at(j)->station->visited == false){
                currentNode = tempPath.at(i)->neighbours.at(j)->station;
                return currentNode;
            }
        }
        tempPath.pop_back();
    }
    return startingNode;
}

std::tuple<std::vector<Node*>, int> Dijkstra(const std::vector<Node*> &graph, const Node *start, const Node *dest, std::vector<Node*> &visitedNodes){
    std::vector<Node*> tempPath;
    Node *currentNode;
    Node *startingNode;
    Node *tempNode;
    int tempDistance = 0;
    int currentLowestWeight = 999;
    std::vector<Node*> candidates;
    bool found = false;

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
            for(int i = 0; i < currentNode->neighbours.size(); i++){
                if(currentNode->neighbours.at(i)->station != nullptr){
                    //update distance from starting node to this node if shorter one is found
                    if(currentNode->neighbours.at(i)->station->distance > currentNode->distance + currentNode->neighbours.at(i)->weight){
                        currentNode->neighbours.at(i)->station->distance = currentNode->distance + currentNode->neighbours.at(i)->weight;
                    }
                }
            }
            for(int i = 0; i < currentNode->neighbours.size(); i++){
                //Pick node with lowest distance to move to
                if(currentNode->neighbours.at(i)->station != nullptr){
                    if(currentNode->neighbours.at(i)->station->visited == false && currentNode->neighbours.at(i)->weight < currentLowestWeight){ 
                        tempNode = currentNode->neighbours.at(i)->station;
                        currentLowestWeight = currentNode->neighbours.at(i)->weight;
                        found = true;
                    }
                }
            }

            if(found == false){
                currentNode->visited = true;
                visitedNodes.emplace_back(currentNode);
                currentLowestWeight = 999;

                currentNode = backTracking(tempPath, startingNode, currentNode);
                tempPath.emplace_back(currentNode);
            }
            if(found == true){
                currentNode->visited = true;
                visitedNodes.emplace_back(currentNode);
                tempDistance += currentLowestWeight; 
                currentLowestWeight = 999;
                currentNode = tempNode;
                tempPath.emplace_back(currentNode);
            }
            //std::cout << "Node: " << tempNode->line << " " << tempNode->name << " " << tempNode->distance << std::endl;
            found = false;
        }while(currentNode->name != dest->name);
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
        std::cout << "Tempdist: " << tempDist << std::endl;
        std::cout << "Dist: " << dist << std::endl;
        std::cout << "visited nodes size: " << visitedNodes.size() << std::endl;

        tempResult = Dijkstra(graph, start, dest, visitedNodes);
        tempDist = std::get<1>(tempResult);

        if(tempDist <= dist){
            result.swap(tempResult);
        }
        /*
        else{
            break;
        }
        */
        //tempDist = 0;
    //}while(visitedNodes.size() != graph.size());

    return result;
}
