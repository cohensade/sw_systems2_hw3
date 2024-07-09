//mail: danielcohen1717@gmail.com
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include "Tile.hpp"


class Player;

using namespace std;
class Vertex {
private:
    
    int id; // the id of the vertex
    Player* owner; //the owner of the vertex
    int build; //represent the building 0 = none, 1 = settlement, 2 = city
    bool isTaken; //if player already own this vertex
    vector<Vertex*> adjacentVertices; //the adjacent vertices of the vertex
    vector<Edge*> edgesOfVertex; //the edges of the vertex
    vector<Tile*> adjacentTiles; // the adjacent Tiles



public:
    
    //constructor
    Vertex(int id);
    
    //get
    int getId() const; //get the id of the vertex
    int getBuild() const; //get the build on this vertex, 0 = none, 1 = settlement and 2 = city
    Player* getOwner(); //get the owner player of this vertex
    string getBuildingString() const; //
    const vector<Vertex*>& getAdjacentVertices() const; //get all the nighboors vertices of the vertex
    void addAdjacentVertex(Vertex* vertex); //add to the vertex nighboors
    const vector<Edge*>& getEdges() const; // get the edges of the vertex
    const std::vector<Tile*>& getAdjacentTiles() const; //get the nighboors tiles

    //add func
    void addEdge(Edge* edge); //add edge
    void addAdjacentTile(Tile* Tile); //add nighboor tile
    
    //set
    void setBuild(int bld, Player* player); //set the type of the building
    void setOwner(Player* player); //set the owner of the vertex

    //bool
    bool isAdjacemt(Vertex &vertex); //check if vertex is nighbor or not
    bool getIsTaken(); //check if the vertex is already taken




};

#endif // VERTEX_HPP
