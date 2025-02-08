#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node*>, int> findPath(const std::vector<Node*> *graph, const Node *start, const Node *dest){
    std::vector<Node*> unvisitedNodes = *graph; 
    std::vector<Node*> path;
    std::vector<Node*> tempPath;
    Node currentNode = *start;
    Node startingNode = *start;
    int distance = 999;
    int tempDistance = 999;

    if(!unvisitedNodes.empty()){
        //check if starting node is in the graph
        //unvisitedNdes == Head node of adjacency list, neighbours == Vector that stores Edges that connect Nodes
        for(int i = 0; i < sizeof(unvisitedNodes); i++){
            for(int j = 0; j < sizeof(unvisitedNodes.at(i)->neighbours); j++){
                if(unvisitedNodes.at(i)->neighbours.at(j)->next->name == start->name){
                    currentNode = *unvisitedNodes.at(i)->neighbours.at(j)->next;
                    startingNode = *unvisitedNodes.at(i)->neighbours.at(j)->next;
                    break;
                }
                else if(unvisitedNodes.at(i)->neighbours.at(j)->prev->name == start->name){
                    currentNode = *unvisitedNodes.at(i)->neighbours.at(j)->prev;
                    startingNode = *unvisitedNodes.at(i)->neighbours.at(j)->prev;
                    break;
                }
                else{
                    return std::make_pair(path, distance);
                }
            }
        }
        //find shortest path
        return std::make_pair(path, distance);
    }
    

    return std::make_pair(path, distance);
}