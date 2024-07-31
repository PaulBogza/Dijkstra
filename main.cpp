#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "include/dijkstra.hpp"
#include "include/parser.hpp"

int main(int argc, char* argv[]){
    
    if(argc < 4){
        std::cout << "Usage: ./program.exe file.txt start destination\n";
        return 1;
    }

    //Create hashmap to find names of stations in graph instantly
    std::map<std::string, std::vector<Node>> *graph  = new std::map<std::string, std::vector<Node>>;

    createGraph(graph, argv[1]);

    Node *start = new Node;
    start->name = argv[2];
    start->visited = true;

    Node *dest = new Node;
    dest->name = argv[3];

    std::vector<Node> *path = findPath(graph, start, dest);

    delete(start);
    delete(dest);
    delete(graph);
    delete(path);

    return 0;
}