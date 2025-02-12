#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include "../include/parser.hpp"

Node* createNode(std::string stationName, int weight){
    Node *newNode = new Node();
    Edge *newEdge = new Edge();
    Node *nextNeighbour;
    Node *prevNeighbour;

    newEdge->next = nextNeighbour;
    newEdge->prev = prevNeighbour;
    newEdge->weight = weight;

    newNode->neighbours.emplace_back(newEdge);

    newNode->name = stationName;

    return newNode;
}

void parseAndAdd(std::string line, std::vector<Node*> &graph){
    Node *currentNode = nullptr;
    Node *prevNode = nullptr;
    std::string lineDelimiter = ": ";
    std::string stationDelimiter = "\"";
    std::string weightDelimiter = " ";
    std::string lineName, stationName, tempWeight = "NULL";
    int weight = 0;

    //split string for train number e.g U1, U2 etc. and then erase it
    lineName = line.substr(0, line.find(lineDelimiter));
    line.erase(0, line.find(lineDelimiter) + lineDelimiter.length()+1);

    while(!line.empty()){
        //split string for station name e.g Leopoldau etc. and then erase it
        stationName = line.substr(0, line.find(stationDelimiter));
        line.erase(0, line.find(stationDelimiter) + stationDelimiter.length()+1);
        if(!line.empty()){
            //split string for edge weight and then erase it
            tempWeight = line.substr(0, line.find(weightDelimiter));
            weight = std::stoi(tempWeight);
            line.erase(0, line.find(weightDelimiter) + weightDelimiter.length()+1);
        }

        currentNode = createNode(stationName, weight);

        if(prevNode != nullptr){
            prevNode->neighbours.at(0)->next = currentNode;
            currentNode->neighbours.at(0)->weight = prevNode->neighbours.at(0)->weight;
            currentNode->neighbours.at(0)->prev = prevNode;
        }
        graph.emplace_back(currentNode);
        prevNode = currentNode;
        currentNode = nullptr;
    }
    prevNode = nullptr;
    currentNode = nullptr;
}

void createGraph(std::vector<Node*> &graph, std::string stops){
    std::string line;
    std::ifstream myFile;
    myFile.open(stops);

    if(myFile.is_open()){
        while(!myFile.eof()){
            getline(myFile, line);
            parseAndAdd(line, graph);
        }
    }
    else{
        std::cout << "Could not open file \n";
    }

    myFile.close();

    Node *tempNode;
    std::vector<Node*> tempGraph = graph;
    //graph.at(i) = stop 
    //graph.at(i).neighbours = adjacent stops
    if(!tempGraph.empty()){
        for(int i = 0; i < tempGraph.size(); i++){
            //std::cout << graph.at(i)->name << std::endl;
            for(int j = i+1; j < tempGraph.size(); j++){
                if((tempGraph.at(i)->name == tempGraph.at(j)->name)){
                    //merge neighbouring stops for nodes with the same name
                    tempGraph.at(i)->neighbours.insert(tempGraph.at(i)->neighbours.end(), tempGraph.at(j)->neighbours.begin(), tempGraph.at(j)->neighbours.end());
                    tempGraph.erase(tempGraph.begin() + j);
                    //TODO: replace all nodes with same name in original graph after they have all the same neighbours
                    tempNode = tempGraph.at(i);
                }
            }
            
        }
    }
 
    for(int i = 0; i < graph.size(); i++){
        std::cout << "Station Name: " << graph.at(i)->name << std::endl;
        for(int j = 0; j < graph.at(i)->neighbours.size(); j++){
            std::cout << graph.at(i)->neighbours.at(j) << std::endl;
        }
        std::cout << std::endl;
    }
}