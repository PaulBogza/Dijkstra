#include <iostream>
#include "../include/dijkstra.hpp"

std::vector<Node>* findPath(std::map<std::string, std::vector<Node>> *graph, Node *start, Node *dest){
    std::vector<Node> *visitedNodes = new std::vector<Node>;
    std::vector<Node> *path = new std::vector<Node>;

    std::map<std::string, std::vector<Node>>::iterator i;
    std::vector<Node>::iterator j;

    if(graph != nullptr){
        for(i = graph->begin(); i != graph->end(); i++){
            std::cout   << i->first << ":" << std::endl;
            for(j = i->second.begin(); j != i->second.end(); j++){
                std::cout << j->name << std::endl;
            }
        }
    }

    

    delete(visitedNodes);
    return path;
}