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

    //graph.at(i) = final stop 
    //graph.at(i).neighbours = adjacent stops
    if(!graph.empty()){
        for(int i = 0; i < graph.size(); i++){
            //std::cout << graph.at(i)->name << std::endl;
            for(int j = 1; j < graph.size(); j++){
                if((graph.at(i)->name == graph.at(j)->name) && (!graph.at(i)->neighbours.empty() && !graph.at(j)->neighbours.empty())){
                    //merge neighbouring stops for nodes with the same name
                    //causes infinite loop
                    graph.at(i)->neighbours.insert(graph.at(i)->neighbours.end(), graph.at(j)->neighbours.begin(), graph.at(j)->neighbours.end());
                    graph.at(j)->neighbours = graph.at(i)->neighbours;
                    std::cout << graph.at(j)->name << std::endl;
                }
            }
        }
    }
}