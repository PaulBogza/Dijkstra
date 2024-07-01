#include <iostream>
#include "classes/dykstra.hpp"
#include "classes/node.hpp"

int main(int argc, char* argv[]){
    
    if(argc < 4){
        std::cout << "Usage: ./program.exe file.txt start destination\n";
        return 1;
    }

    Node *start = new Node;
    start->name = argv[2];

    Node *dest = new Node;
    dest->name = argv[3];

    findPath(start, dest);


    delete(start);
    delete(dest);

    return 0;
}