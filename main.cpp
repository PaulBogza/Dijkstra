#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "include/dijkstra.hpp"
#include "include/parser.hpp"

int main(int argc, char* argv[]){
    
    if(argc < 4){
        std::cout << "Usage: ./program.exe file.txt start destination\n";
        return 1;
    }

    std::vector<Node*> graph;

    createGraph(graph, argv[1]);

    Node *start = new Node;
    start->name = argv[2];
    start->visited = true;

    Node *dest = new Node;
    dest->name = argv[3];

    std::tuple<std::vector<Node*>, int> result = findPath(graph, start, dest);

    delete(start);
    delete(dest);

    if(std::get<1>(result) == 999){
        std::cout << "No path could be found" << std::endl;
        return 1;
    }

    return 0;
}