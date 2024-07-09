//mail: danielcohen1717@gmail.com
#include "Vertex.hpp"
#include "Player.hpp"

Vertex::Vertex(int id) : id(id), owner(nullptr), build(0),isTaken(false) {}
//return id of the vertex
int Vertex::getId() const {
    return id;
}
//return building of the vertex
int Vertex::getBuild() const {
    return build;
}
//return owner of the vertex
Player* Vertex::getOwner()  {
    return owner;
}

//return a string represent the building on this vertex
string Vertex::getBuildingString() const {
    if(build == 0) {
        return "There is no settlement or city on this vertex. ";
    }
    if (build == 1)
    {
        return "There is a settlement on this vertex that belong to " + owner->getName() + ". ";
    }
    if (build == 2)
    {
        return "There is a city on this vertex that belong to " + owner->getName() + ". ";
    }
    return "";
}

//get adjacent vertices of the vertex
const vector<Vertex*>& Vertex::getAdjacentVertices() const {
    return adjacentVertices;
}

//get edges of the vertex
const vector<Edge*>& Vertex::getEdges() const {
    return edgesOfVertex;
}


//get adjacent Tiles of the vertex
const vector<Tile*>& Vertex::getAdjacentTiles() const {
    return adjacentTiles;
}
//add Tile to the adjacent Tiles of the vertex
void Vertex::addAdjacentTile(Tile* Tile) {
    adjacentTiles.push_back(Tile);
}

//add edge to the vertex
void Vertex::addEdge(Edge* edge) {
    edgesOfVertex.push_back(edge);
}

//add a vertex to the adjacent vertices of the vertex
void Vertex::addAdjacentVertex(Vertex* vertex) {
    adjacentVertices.push_back(vertex);
}

//set building on the vertex
void Vertex::setBuild(int bld, Player* player) {
     build = bld;
    owner = player;
    isTaken = true;
}

//function to check if a vertex is adjacent to this vertex
bool Vertex::isAdjacemt(Vertex &vertex) {
    for (Vertex* ver : adjacentVertices) {
        //check if one of the adjectives vertices have the same id as the vertex we want to check if he is adjective
        if (vertex.getId() == ver->getId()) {
            return true;
        }
    }
    return false;
}

//return if the vertex is build by any owner
bool Vertex::getIsTaken() {
    return isTaken;
}

void Vertex::setOwner(Player* player){
    owner = player;
}