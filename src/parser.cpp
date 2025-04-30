#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include "../include/parser.hpp"

Node* createNode(std::string stationName, int weight){
    Node *newNode = new Node;
    Edge *newNextEdge = new Edge;
    Edge *newPrevEdge = new Edge;

    newNextEdge->weight = weight;

    newNode->neighbours.emplace_back(newNextEdge);
    newNode->neighbours.emplace_back(newPrevEdge);

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
            prevNode->neighbours.at(0)->station = currentNode;
            currentNode->neighbours.at(1)->station = prevNode;
            currentNode->neighbours.at(1)->weight = prevNode->neighbours.at(0)->weight;
        }
        graph.emplace_back(currentNode);
        prevNode = currentNode;
        currentNode = nullptr;
        //delete(currentNode);
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

    //graph.at(i) = stop 
    //graph.at(i).neighbours = adjacent stops
    if(!graph.empty()){
        for(int i = 0; i < graph.size(); i++){
            for(int j = i+1; j < graph.size(); j++){
                if((graph.at(i)->name == graph.at(j)->name)){
                    //merge neighbouring stops for nodes with the same name
                    graph.at(i)->neighbours.insert(graph.at(i)->neighbours.end(), graph.at(j)->neighbours.begin(), graph.at(j)->neighbours.end());
                    graph.erase(graph.begin() + j);
                }
            }
        }
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph.at(i)->neighbours.size(); j++){
                for(int k = 0; graph.at(i+1)->neighbours.size(); k++){
        	    if(){
			
		    }
                }
            }
        }
    }
}
