#include <iostream>
#include "../include/dijkstra.hpp"

std::vector<Node>* findPath(std::unordered_multimap<std::string, Node*> *graph, Node *start, Node *dest){
    std::vector<Node> *visitedNodes = new std::vector<Node>;
    std::vector<Node> *path = new std::vector<Node>;

    std::unordered_multimap<std::string, Node*>::iterator i;

    if(graph != nullptr){
        for(i = graph->begin(); i != graph->end(); i++){
            std::cout << i->first +": "+ i->second->name << " next stop: "<< i->second->next->neighbour->name << std::endl;
        }
    }

    delete(visitedNodes);
    return path;
}