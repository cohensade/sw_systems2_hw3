#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Player.hpp"

class Board {
private:
    std::vector<Tile> tiles; // vector to store all the tiles
    std::vector<Vertex> vertices; // vector to store all the vertices
    std::vector<Edge> edges; // vector to store all the edges

public:
    Board(); // constructor to initialize the board

    std::vector<Tile>& getTiles(); // get all the tiles
    std::vector<Vertex>& getVertices(); // get all the vertices
    std::vector<Edge>& getEdges(); // get all the edges

    void printBoard() const; // print the board
    void initializeTiles(); // initialize tiles
    void initializeVertices(); // initialize vertices
    void initializeEdges(); // initialize edges
    void addEdgesToVertices(); // add edges to vertices
    void addVerticesAndEdgesToTiles(); // add vertices and edges to tiles
    void initializeBoard(); // initialize the entire board
};

#endif // BOARD_HPP
