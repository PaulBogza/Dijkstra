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
    int weight = 999;
    Node *station = nullptr;
};

#endif