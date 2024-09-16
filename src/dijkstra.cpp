#include <iostream>
#include <stdexcept>
#include <cstring>
#include "../include/dijkstra.hpp"

std::vector<Node>* findPath(const std::unordered_multimap<std::string, Node*> *graph, const Node *start, const Node *dest){
    std::unordered_multimap<std::string, Node*> unvisitedNodes = *graph; 
    //std::vector<Node> *visitedNodes = new std::vector<Node>;
    std::vector<Node> *path = new std::vector<Node>;
    Node currentNode = *start;
    int distance = 0;

    if(!unvisitedNodes.empty()){
        for(auto i = unvisitedNodes.begin(); i != unvisitedNodes.end(); i++){
            if(i->second->name == currentNode.name){
                currentNode = *i->second;
                std::cout << &currentNode << " " << i->second << std::endl;
                break;
            }
        }
    }

    /*
    if(unvisitedNodes->empty() || (currentNode->next->neighbour == nullptr && currentNode->prev->neighbour == nullptr)){
        throw std::exception();
    }
    */

    //delete(visitedNodes);
    return path;
}