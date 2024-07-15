#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "reader.hpp"

void parseLine(int counter, std::string line){
    std::string lineDelimiter = ":";
    std::string weightDelimiter = " ";

    
}

void createGraph(std::map<std::string, std::vector<Node>> *graph, std::string stops){
    std::string line;
    std::ifstream myFile;
    myFile.open(stops);

    if(myFile.is_open()){
        int counter = 0;
        while(!myFile.eof){
            getline(myFile, line);
            std::cout << line << "\n";
            parseLine(counter, line);
            counter++;
        }
    }
    else{
        std::cout << "Could not open file \n";
    }

    myFile.close();
}