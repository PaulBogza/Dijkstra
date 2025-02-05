#ifndef node
#define node 

#include <string>

struct Node{
    bool visited = false;
    std::string name = "NULL";
    int weight = 999;
    Node *next = nullptr;
    Node *prev = nullptr;
};

#endif