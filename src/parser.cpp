#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "../include/parser.hpp"

void parseAndAdd(int counter, std::string line, std::map<std::string, std::vector<Node>> *graph){
    std::vector<Node> tempVector;
    Node tempNode;
    std::string lineDelimiter = ":";
    std::string stationDelimiter = "\"";
    std::string weightDelimiter = " ";
    std::string lineName = NULL;
    std::string stationName = NULL;
    std::string tempWeight = NULL;
    int weight = 0;

    //split string for train number e.g U1, U2 etc. and then erase it
    lineName = line.substr(0, line.find(lineDelimiter));
    line.erase(0, line.find(weightDelimiter) + weightDelimiter.length()+1);

    while(!line.empty()){
        //split string for station name e.g Leopoldau etc. and then erase it
        stationName = line.substr(2, line.find(stationDelimiter));
        //stationName = stationName.substr(1, stationName.size()-2);
        line.erase(0, line.find(weightDelimiter) + weightDelimiter.length()+1);

        //split string for edge weight and then erase it
        tempWeight = line.substr(0, line.find(weightDelimiter));
        weight = std::stoi(tempWeight, &sz);
        line.erase(0, line.find(weightDelimiter) + weightDelimiter.length()+1);

        //tempNode.name = stationName;
        //tempNode.weight = weight;

        //tempVector.push_back(tempNode);
    }
    //graph->insert({lineName, tempVector});
}

void createGraph(std::map<std::string, std::vector<Node>> *graph, std::string stops){
    std::string line;
    std::ifstream myFile;
    myFile.open(stops);

    if(myFile.is_open()){
        int counter = 0;
        //while(!myFile.eof()){
            getline(myFile, line);
            //std::cout << line << "\n";
            parseAndAdd(counter, line, graph);
            counter++;
        //}
    }
    else{
        std::cout << "Could not open file \n";
    }

    myFile.close();
}