#ifndef node
#define node 

#include <string>

struct Edge;

struct Node{
    bool visited = false;
    std::string name = "NULL";
    Edge *next;
    Edge *prev;
};

struct Edge{
    int weight = 999;
    Node *neighbour = nullptr;
};

#endif