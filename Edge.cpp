//mail: danielcohen1717@gmail.com
#include "Edge.hpp"

//to create edge we need its id and its 2 vertices
Edge::Edge(int id, Vertex* vertex1, Vertex* vertex2) : id(id), owner(nullptr), isTaken(false), vertex1(vertex1), vertex2(vertex2) {}

//return id of the edge
int Edge::getId() const {
    return id;
}
//get the owner of the edge
Player* Edge::getOwner() const {
    return owner;
}

//get the vertices
Vertex* Edge::getVertex1() const { return vertex1; }

Vertex* Edge::getVertex2() const { return vertex2; }

//set the owner of the edge
void Edge::setOwner(Player* player) {
    owner = player;
    isTaken = true;
}

//function to check if this edge is adjecancy to other edge
bool Edge::isNighnor(Edge* other)  {
    if (this == other) {
        return false; // same edge, not adjacent
    }
    //if they  atleast shering one vertex they are adjecancy
    return (vertex1 == other->vertex1 || vertex1 == other->vertex2 ||
            vertex2 == other->vertex1 || vertex2 == other->vertex2);
}

//check if the edgge already taken
bool Edge::getIsTaken() {
    return isTaken;
}
