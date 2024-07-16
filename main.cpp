#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "classes/dijkstra.hpp"
#include "classes/node.hpp"
#include "utility/reader.hpp"

int main(int argc, char* argv[]){
    
    if(argc < 4){
        std::cout << "Usage: ./program.exe file.txt start destination\n";
        return 1;
    }

    std::map<std::string, std::vector<Node>> *graph  = new std::map<std::string, std::vector<Node>>;
    createGraph(graph, argv[1]);

    Node *start = new Node;
    start->name = argv[2];
    start->weight = 0;

    Node *dest = new Node;
    dest->name = argv[3];

    findPath(graph, start, dest);

    if(graph->count("U1")){
        std::cout << "true" << std::endl;
    }
    else{
        std::cout << "false" << std::endl;
    }

    delete(start);
    delete(dest);
    //TODO: iterate through graph to delete all data structures
    delete(graph);

    return 0;
}