#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "include/dijkstra.hpp"
#include "include/node.hpp"
#include "include/parser.hpp"

int main(int argc, char* argv[]){
    
    if(argc < 4){
        std::cout << "Usage: ./program.exe file.txt start destination\n";
        return 1;
    }

    std::map<std::string, std::vector<Node>> *graph  = new std::map<std::string, std::vector<Node>>;
    std::map<std::string, std::vector<Node>>::iterator it;
    std::vector<Node>::iterator i;

    createGraph(graph, argv[1]);

    Node *start = new Node;
    start->name = argv[2];
    start->weight = 0;

    Node *dest = new Node;
    dest->name = argv[3];

    findPath(graph, start, dest);

    if(graph->count("U3")){
        for(it = graph->begin(); it != graph->end(); it++){
            std::cout   << it->first << ":" << std::endl;
            for(i = it->second.begin(); i != it->second.end(); i++){
                std::cout << i->name << std::endl;
            }
        }
    }
    else{
        std::cout << "false" << std::endl;
    }

    delete(start);
    delete(dest);
    delete(graph);

    return 0;
}