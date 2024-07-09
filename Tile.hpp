#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <vector>

class Vertex;
class Edge;

using namespace std;

class Tile {
public:
    // ResourceType definitions
    static const string Wood; //wood for forest
    static const string Brick; //brick for hills
    static const string Wool; // wool for pasture
    static const string Wheat; //wheat for  agricultural
    static const string Ore; //ore for mountains
    static const string None;// none for desert

    // TileType definitions
    static const string Forest; 
    static const string Hills;
    static const string PastureLand;
    static const string AgriculturalLand;
    static const string Mountains;
    static const string Desert;

    // Constructor
    Tile(int id, const string& type, int number);

    // Getters
    int getId() const; //get the id of the tile
    string getResourceType() const; //get the type of the tile
    int getNumber() const; //get the number on the tile (dice represent)
    string getTileTypeString() const; //get the type
    string getResourceTypeString() const; //get the resource
    static string getResourceTypeString(const string& type);

    // Vertices and Edges getters
    const vector<Vertex*>& getVertices() const; //get the vertices that on the tile
    const vector<Edge*>& getEdges() const; //get the edges on the tile

    // Add functions
    void addVertex(Vertex* vertex); //add vertex
    void addEdge(Edge* edge); //add edge

private:
    int id; //index of tile
    string tileType; //type of tile
    string resourceType; //the resource of the type
    int number; //number for dice
    vector<Vertex*> vertices; //vertices of tile (6)
    vector<Edge*> edges; //edges of tile (6)

    string typeToResource(const string& type) const; //get type return the resource
};

#endif // TILE_HPP
