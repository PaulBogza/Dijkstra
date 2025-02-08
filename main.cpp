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

    std::vector<Node*> *graph  = new std::vector<Node*>;

    createGraph(graph, argv[1]);

    Node *start = new Node;
    start->name = argv[2];
    start->visited = true;

    Node *dest = new Node;
    dest->name = argv[3];

    std::tuple<std::vector<Node*>, int> result = findPath(graph, start, dest);

    if(graph != nullptr){
        for(int i = 0; i < sizeof(graph); i++){
            std::cout << graph->at(i) << std::endl;
            for(int j = 0; j < sizeof(graph->at(i)); j++){
                for(int k = 0; k < sizeof(graph->at(i)->neighbours.at(j)); k++){
                    delete(graph->at(i)->neighbours.at(j)->next);
                    delete(graph->at(i)->neighbours.at(j)->prev);
                }
                delete(graph->at(i)->neighbours.at(j));
            }
            delete(graph->at(i));
        }
    }
    
    delete(start);
    delete(dest);
    //delete(graph);

    if(std::get<1>(result) == 999){
        std::cout << "No path could be found" << std::endl;
        return 1;
    }

    return 0;
}