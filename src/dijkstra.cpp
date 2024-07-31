#include <iostream>
#include "../include/dijkstra.hpp"

std::vector<Node>* findPath(std::map<std::string, std::vector<Node>> *graph, Node *start, Node *dest){
    std::vector<Node> *visitedNodes = new std::vector<Node>;
    std::vector<Node> *path = new std::vector<Node>;

    std::map<std::string, std::vector<Node>>::iterator it;
    std::vector<Node>::iterator i;

    if(graph->count("U1")){
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

    /*
    do {
        visited[i] = TRUE; // Knoten markieren
        for each (neighbour m of i){
            if (not visited[m]) {
                // Nachbarknoten in Heap einordnen
                Heap.put(m, m.gewicht + minweg);
            }
        }
        do {
            // Knoten mit minimalem Gewicht aus
            // Heap entfernen, minweg aktualisieren
            i = Heap.get();
            minweg = i.gewicht;
        } while (visited[i]);
    } while (i != j); // Solange Zielknoten nicht erreicht
    */

    delete(visitedNodes);
    return path;
}