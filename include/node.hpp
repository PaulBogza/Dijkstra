#ifndef node
#define node 

#include <string>
#include <vector>

struct Edge;

struct Node{
    bool visited = false;
    std::string name = "NULL";
    std::vector<Edge*> neighbours;
};

struct Edge{
    //nodes with at 0 or even array indices are next (node.neighbours.at(0))
    //uneven are previous (node.neighbours.at(1))
    int weight = 999;
    Node *station = nullptr;
};

#endif