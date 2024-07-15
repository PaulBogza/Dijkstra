#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "reader.hpp"

std::map<std::string, std::vector<Node>>* readFile(std::string stops){
    std::map <std::string, std::vector<Node>> *graph = new std::map<std::string, std::vector<Node>>;

    std::ifstream myFile;
    myFile.open(stops);

    if(myFile.is_open()){
        std::string line;
        getline(myFile, line);
        std::cout << line << "\n";
        myFile.close();
    }
    else{
        std::cout << "Could not open file \n";
    } 

    return graph;
}