

#ifndef EDGE_HPP
#define EDGE_HPP

#include <vector>
#include "Vertex.hpp"

class Player;

class Edge {
private:
    
    int id; // id of the edge
    Player* owner; // owner of the edge
    bool isTaken; //if the edge is own
    Vertex* vertex1; //the first vertex
    Vertex* vertex2; //the second vertex
   


public:
    //constructor(id,ver1,ver2)
    Edge(int id, Vertex* vertex1, Vertex* vertex2);
    
    //get
    int getId() const; //get the id of the edge
    Player* getOwner() const; //get the player who own this edge
    
    Vertex* getVertex1() const; //get the first vertex of the edge
    Vertex* getVertex2() const; //get the second vertex of the edge

    //set
    void setOwner(Player* player); //set the owner of the edge

    //bool
    bool isNighnor(Edge* other);//function to check if this edge is adjecancy to other edge
    bool getIsTaken(); //return if the edge is own alredy or not


};

#endif // EDGE_HPP
