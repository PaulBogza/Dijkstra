# Dijkstra

Dijsktra's algorhitm in C++

**Dijkstra Steps:**
1. Mark all nodes as unvisited
2. Assign distance as infinite to all nodes
3. Check distance to all unvisited nodes that are neighbours of the current node
4. Update distance if a new shorter distance to a node is found
5. After all neighbouring nodes of the current node have been visited mark it as a visited nodes 
6. Chose a new current node from the unvisited nodes with the shortest distance
7. If there are still unvisited nodes go to step 3.
8. Else break