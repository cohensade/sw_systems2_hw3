#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"

// Define static members
const string Tile::Wood = "Wood"; //etz
const string Tile::Brick = "Brick"; //levena
const string Tile::Wool = "Wool"; //tzemer
const string Tile::Wheat = "Wheat"; //hita
const string Tile::Ore = "Ore"; //barzel
const string Tile::None = "None"; //nada

const string Tile::Forest = "Forest"; 
const string Tile::Hills = "Hills";
const string Tile::PastureLand = "PastureLand";
const string Tile::AgriculturalLand = "AgriculturalLand";
const string Tile::Mountains = "Mountains";
const string Tile::Desert = "Desert";

// Constructor
Tile::Tile(int id, const string& type, int number)
    : id(id), tileType(type), resourceType(typeToResource(type)), number(number) {}

// Getters
int Tile::getId() const {
    return id;
}

string Tile::getResourceType() const {
    return resourceType;
}

int Tile::getNumber() const {
    return number;
}

string Tile::getTileTypeString() const {
    return tileType;
}

string Tile::getResourceTypeString() const {
    return resourceType;
}

// static function to map tile type to resource type
string Tile::getResourceTypeString(const string& type) {
    if (type == Forest) return Wood;
    if (type == Hills) return Brick;
    if (type == PastureLand) return Wool;
    if (type == AgriculturalLand) return Wheat;
    if (type == Mountains) return Ore;
    return None;
}

const vector<Vertex*>& Tile::getVertices() const {
    return vertices;
}

const vector<Edge*>& Tile::getEdges() const {
    return edges;
}

void Tile::addVertex(Vertex* vertex) {
    vertices.push_back(vertex);
}

void Tile::addEdge(Edge* edge) {
    edges.push_back(edge);
}

// helper function to map tile type to resource type
string Tile::typeToResource(const string& type) const {
    return getResourceTypeString(type);
}
