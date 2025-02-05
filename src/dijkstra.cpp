#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::tuple<std::vector<Node>, int> findPath(const std::unordered_multimap<std::string, Node*> *graph, const Node *start, const Node *dest){
    std::unordered_multimap<std::string, Node*> unvisitedNodes = *graph; 
    //std::vector<Node> *visitedNodes = new std::vector<Node>;
    std::vector<Node> path = new std::vector<Node>;
    Node currentNode = *start;
    Node startingNode = *start;
    int distance = 0;

    if(!unvisitedNodes.empty()){
        //check if starting node is in the graph
        for(auto i = unvisitedNodes.begin(); i != unvisitedNodes.end(); i++){
            if(i->second->name == start->name){
                currentNode = *i->second;
                startingNode = *i->second;
                currentNode.weight = 0;
                startingNode.weight = 0;
                break;
            }
            else{
                path = nullptr; 
                return std::make_pair(path, distance);
            }
        }
        //find shortest path
        
    }

    /*
    if(unvisitedNodes->empty() || (currentNode->next->neighbour == nullptr && currentNode->prev->neighbour == nullptr)){
        throw std::exception();
    }
    */

    return std::make_pair(path, distance);
}