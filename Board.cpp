#include "Board.hpp"
#include <iostream>
#include <stdexcept>

// constructor to initialize the board
Board::Board() {
    vertices.reserve(54); // Reserve space to avoid reallocations
    edges.reserve(72);    // Reserve space to avoid reallocations
    tiles.reserve(19); // Reserve space to avoid reallocations
    
    
}

// Get all tiles
std::vector<Tile>& Board::getTiles() {
    return tiles;
}

// Get all vertices
std::vector<Vertex>& Board::getVertices() {
    return vertices;
}

// Get all edges
std::vector<Edge>& Board::getEdges() {
    return edges;
}

// init the entire board
void Board::initializeBoard() {
    std::cout << "Initializing tiles...\n";
    initializeTiles();
    std::cout << "Number of tiles after initialization: " << tiles.size() << "\n";
    
    std::cout << "Initializing vertices(54)...\n";
    initializeVertices();
    
    std::cout << "Initializing edges...\n";
    initializeEdges();
    
    std::cout << "Adding edges to vertices...\n";
    addEdgesToVertices();
    
    std::cout << "Adding vertices and edges to tiles...\n";
    addVerticesAndEdgesToTiles();
}

// init tiles
void Board::initializeTiles() {
    tiles.emplace_back(1, Tile::AgriculturalLand, 10);
    tiles.emplace_back(2, Tile::Forest, 2);
    tiles.emplace_back(3, Tile::AgriculturalLand, 9);
    tiles.emplace_back(4, Tile::Hills, 12);
    tiles.emplace_back(5, Tile::Forest, 6);
    tiles.emplace_back(6, Tile::AgriculturalLand, 4);
    tiles.emplace_back(7, Tile::Forest, 10);
    tiles.emplace_back(8, Tile::PastureLand, 9);
    tiles.emplace_back(9, Tile::Forest, 11);
    tiles.emplace_back(10, Tile::Desert, 0);
    tiles.emplace_back(11, Tile::PastureLand, 3);
    tiles.emplace_back(12, Tile::Mountains, 8);
    tiles.emplace_back(13, Tile::AgriculturalLand, 8);
    tiles.emplace_back(14, Tile::PastureLand, 3);
    tiles.emplace_back(15, Tile::Mountains, 4);
    tiles.emplace_back(16, Tile::Hills, 5);
    tiles.emplace_back(17, Tile::PastureLand, 5);
    tiles.emplace_back(18, Tile::Hills, 6);
    tiles.emplace_back(19, Tile::Mountains, 11);

    std::cout << "Tiles initialized, total: " << tiles.size() << "\n";
}

// init vertices
void Board::initializeVertices() {
    // create the 54 vertices we have on the board
    for (int i = 0; i <= 53; ++i) {
        vertices.emplace_back(i);
    }

    // for each vertex, add the adjacent vertices
    vertices[0].addAdjacentVertex(&vertices[1]);
    vertices[0].addAdjacentVertex(&vertices[8]);
    vertices[1].addAdjacentVertex(&vertices[0]);
    vertices[1].addAdjacentVertex(&vertices[2]);
    vertices[2].addAdjacentVertex(&vertices[1]);
    vertices[2].addAdjacentVertex(&vertices[3]);
    vertices[2].addAdjacentVertex(&vertices[10]);
    vertices[3].addAdjacentVertex(& vertices[2]);
    vertices[3].addAdjacentVertex(& vertices[4]);
    vertices[4].addAdjacentVertex(& vertices[3]);
    vertices[4].addAdjacentVertex(& vertices[5]);
    vertices[4].addAdjacentVertex(& vertices[12]);
    vertices[5].addAdjacentVertex(& vertices[4]);
    vertices[5].addAdjacentVertex(& vertices[6]);
    vertices[6].addAdjacentVertex(& vertices[5]);
    vertices[6].addAdjacentVertex(& vertices[14]);
    vertices[7].addAdjacentVertex(& vertices[8]);
    vertices[7].addAdjacentVertex(& vertices[17]);
    vertices[8].addAdjacentVertex(& vertices[0]);
    vertices[8].addAdjacentVertex(& vertices[7]);
    vertices[8].addAdjacentVertex(& vertices[9]);
    vertices[9].addAdjacentVertex(& vertices[8]);
    vertices[9].addAdjacentVertex(& vertices[10]);
    vertices[9].addAdjacentVertex(& vertices[19]);
    vertices[10].addAdjacentVertex(& vertices[2]);
    vertices[10].addAdjacentVertex(& vertices[9]);
    vertices[10].addAdjacentVertex(& vertices[11]);
    vertices[11].addAdjacentVertex(& vertices[10]);
    vertices[11].addAdjacentVertex(& vertices[12]);
    vertices[11].addAdjacentVertex(& vertices[21]);
    vertices[12].addAdjacentVertex(& vertices[4]);
    vertices[12].addAdjacentVertex(& vertices[11]);
    vertices[12].addAdjacentVertex(& vertices[13]);
    vertices[13].addAdjacentVertex(& vertices[12]);
    vertices[13].addAdjacentVertex(& vertices[14]);
    vertices[13].addAdjacentVertex(& vertices[23]);
    vertices[14].addAdjacentVertex(& vertices[6]);
    vertices[14].addAdjacentVertex(& vertices[13]);
    vertices[14].addAdjacentVertex(& vertices[15]);
    vertices[15].addAdjacentVertex(& vertices[14]);
    vertices[15].addAdjacentVertex(& vertices[25]);
    vertices[16].addAdjacentVertex(& vertices[17]);
    vertices[16].addAdjacentVertex(& vertices[27]);
    vertices[17].addAdjacentVertex(& vertices[7]);
    vertices[17].addAdjacentVertex(& vertices[16]);
    vertices[17].addAdjacentVertex(& vertices[18]);
    vertices[18].addAdjacentVertex(& vertices[17]);
    vertices[18].addAdjacentVertex(& vertices[19]);
    vertices[18].addAdjacentVertex(& vertices[29]);
    vertices[19].addAdjacentVertex(& vertices[9]);
    vertices[19].addAdjacentVertex(& vertices[18]);
    vertices[19].addAdjacentVertex(& vertices[20]);
    vertices[20].addAdjacentVertex(& vertices[19]);
    vertices[20].addAdjacentVertex(& vertices[21]);
    vertices[20].addAdjacentVertex(& vertices[31]);
    vertices[21].addAdjacentVertex(& vertices[11]);
    vertices[21].addAdjacentVertex(& vertices[20]);
    vertices[21].addAdjacentVertex(& vertices[22]);
    vertices[22].addAdjacentVertex(& vertices[21]);
    vertices[22].addAdjacentVertex(& vertices[23]);
    vertices[22].addAdjacentVertex(& vertices[33]);
    vertices[23].addAdjacentVertex(& vertices[13]);
    vertices[23].addAdjacentVertex(& vertices[22]);
    vertices[23].addAdjacentVertex(& vertices[24]);
    vertices[24].addAdjacentVertex(& vertices[23]);
    vertices[24].addAdjacentVertex(& vertices[25]);
    vertices[24].addAdjacentVertex(& vertices[35]);
    vertices[25].addAdjacentVertex(& vertices[15]);
    vertices[25].addAdjacentVertex(& vertices[24]);
    vertices[25].addAdjacentVertex(& vertices[26]);
    vertices[26].addAdjacentVertex(& vertices[25]);
    vertices[26].addAdjacentVertex(& vertices[37]);
    vertices[27].addAdjacentVertex(& vertices[16]);
    vertices[27].addAdjacentVertex(& vertices[28]);
    vertices[28].addAdjacentVertex(& vertices[27]);
    vertices[28].addAdjacentVertex(& vertices[29]);
    vertices[28].addAdjacentVertex(& vertices[38]);
    vertices[29].addAdjacentVertex(& vertices[18]);
    vertices[29].addAdjacentVertex(& vertices[28]);
    vertices[29].addAdjacentVertex(& vertices[30]);
    vertices[30].addAdjacentVertex(& vertices[29]);
    vertices[30].addAdjacentVertex(& vertices[31]);
    vertices[30].addAdjacentVertex(& vertices[40]);
    vertices[31].addAdjacentVertex(& vertices[20]);
    vertices[31].addAdjacentVertex(& vertices[30]);
    vertices[31].addAdjacentVertex(& vertices[32]);
    vertices[32].addAdjacentVertex(& vertices[31]);
    vertices[32].addAdjacentVertex(& vertices[33]);
    vertices[32].addAdjacentVertex(& vertices[42]);
    vertices[33].addAdjacentVertex(& vertices[22]);
    vertices[33].addAdjacentVertex(& vertices[32]);
    vertices[33].addAdjacentVertex(& vertices[34]);
    vertices[34].addAdjacentVertex(& vertices[33]);
    vertices[34].addAdjacentVertex(& vertices[35]);
    vertices[34].addAdjacentVertex(& vertices[44]);
    vertices[35].addAdjacentVertex(& vertices[24]);
    vertices[35].addAdjacentVertex(& vertices[34]);
    vertices[35].addAdjacentVertex(& vertices[36]);
    vertices[36].addAdjacentVertex(& vertices[35]);
    vertices[36].addAdjacentVertex(& vertices[37]);
    vertices[36].addAdjacentVertex(& vertices[46]);
    vertices[37].addAdjacentVertex(& vertices[26]);
    vertices[37].addAdjacentVertex(& vertices[36]);
    vertices[38].addAdjacentVertex(& vertices[28]);
    vertices[38].addAdjacentVertex(& vertices[39]);
    vertices[39].addAdjacentVertex(& vertices[38]);
    vertices[39].addAdjacentVertex(& vertices[40]);
    vertices[39].addAdjacentVertex(& vertices[47]);
    vertices[40].addAdjacentVertex(& vertices[30]);
    vertices[40].addAdjacentVertex(& vertices[39]);
    vertices[40].addAdjacentVertex(& vertices[41]);
    vertices[41].addAdjacentVertex(& vertices[40]);
    vertices[41].addAdjacentVertex(& vertices[42]);
    vertices[41].addAdjacentVertex(& vertices[49]);
    vertices[42].addAdjacentVertex(& vertices[32]);
    vertices[42].addAdjacentVertex(& vertices[41]);
    vertices[42].addAdjacentVertex(& vertices[43]);
    vertices[43].addAdjacentVertex(& vertices[42]);
    vertices[43].addAdjacentVertex(& vertices[44]);
    vertices[43].addAdjacentVertex(& vertices[51]);
    vertices[44].addAdjacentVertex(& vertices[34]);
    vertices[44].addAdjacentVertex(& vertices[43]);
    vertices[44].addAdjacentVertex(& vertices[45]);
    vertices[45].addAdjacentVertex(& vertices[44]);
    vertices[45].addAdjacentVertex(& vertices[46]);
    vertices[45].addAdjacentVertex(& vertices[53]);
    vertices[46].addAdjacentVertex(& vertices[36]);
    vertices[46].addAdjacentVertex(& vertices[45]);
    vertices[47].addAdjacentVertex(& vertices[39]);
    vertices[47].addAdjacentVertex(& vertices[48]);
    vertices[48].addAdjacentVertex(& vertices[47]);
    vertices[48].addAdjacentVertex(& vertices[49]);
    vertices[49].addAdjacentVertex(& vertices[41]);
    vertices[49].addAdjacentVertex(& vertices[48]);
    vertices[49].addAdjacentVertex(& vertices[50]);
    vertices[50].addAdjacentVertex(& vertices[49]);
    vertices[50].addAdjacentVertex(& vertices[51]);
    vertices[51].addAdjacentVertex(& vertices[43]);
    vertices[51].addAdjacentVertex(& vertices[50]);
    vertices[51].addAdjacentVertex(& vertices[52]);
    vertices[52].addAdjacentVertex(& vertices[51]);
    vertices[52].addAdjacentVertex(& vertices[53]);
    vertices[53].addAdjacentVertex(& vertices[45]);
    vertices[53].addAdjacentVertex(& vertices[52]);
}

// init edges
void Board::initializeEdges() {
    // create the 72 edges we have on the board
    edges.emplace_back(0, &vertices[0], &vertices[1]);
edges.emplace_back(1, &vertices[1], &vertices[2]);
edges.emplace_back(2, &vertices[2], &vertices[3]);
edges.emplace_back(3, &vertices[3], &vertices[4]);
edges.emplace_back(4, &vertices[4], &vertices[5]);
edges.emplace_back(5, &vertices[5], &vertices[6]);
edges.emplace_back(6, &vertices[0], &vertices[8]);
edges.emplace_back(7, &vertices[2], &vertices[10]);
edges.emplace_back(8, &vertices[4], &vertices[12]);
edges.emplace_back(9, &vertices[6], &vertices[14]);
edges.emplace_back(10, &vertices[7], &vertices[8]);
edges.emplace_back(11, &vertices[8], &vertices[9]);
edges.emplace_back(12, &vertices[9], &vertices[10]);
edges.emplace_back(13, &vertices[10], &vertices[11]);
edges.emplace_back(14, &vertices[11], &vertices[12]);
edges.emplace_back(15, &vertices[12], &vertices[13]);
edges.emplace_back(16, &vertices[13], &vertices[14]);
edges.emplace_back(17, &vertices[14], &vertices[15]);
edges.emplace_back(18, &vertices[7], &vertices[17]);
edges.emplace_back(19, &vertices[9], &vertices[19]);
edges.emplace_back(20, &vertices[11], &vertices[21]);
edges.emplace_back(21, &vertices[13], &vertices[23]);
edges.emplace_back(22, &vertices[15], &vertices[25]);
edges.emplace_back(23, &vertices[16], &vertices[17]);
edges.emplace_back(24, &vertices[17], &vertices[18]);
edges.emplace_back(25, &vertices[18], &vertices[19]);
edges.emplace_back(26, &vertices[19], &vertices[20]);
edges.emplace_back(27, &vertices[20], &vertices[21]);
edges.emplace_back(28, &vertices[21], &vertices[22]);
edges.emplace_back(29, &vertices[22], &vertices[23]);
edges.emplace_back(30, &vertices[23], &vertices[24]);
edges.emplace_back(31, &vertices[24], &vertices[25]);
edges.emplace_back(32, &vertices[25], &vertices[26]);
edges.emplace_back(33, &vertices[16], &vertices[27]);
edges.emplace_back(34, &vertices[18], &vertices[29]);
edges.emplace_back(35, &vertices[20], &vertices[31]);
edges.emplace_back(36, &vertices[22], &vertices[33]);
edges.emplace_back(37, &vertices[24], &vertices[35]);
edges.emplace_back(38, &vertices[26], &vertices[37]);
edges.emplace_back(39, &vertices[27], &vertices[28]);
edges.emplace_back(40, &vertices[28], &vertices[29]);
edges.emplace_back(41, &vertices[29], &vertices[30]);
edges.emplace_back(42, &vertices[30], &vertices[31]);
edges.emplace_back(43, &vertices[31], &vertices[32]);
edges.emplace_back(44, &vertices[32], &vertices[33]);
edges.emplace_back(45, &vertices[33], &vertices[34]);
edges.emplace_back(46, &vertices[34], &vertices[35]);
edges.emplace_back(47, &vertices[35], &vertices[36]);
edges.emplace_back(48, &vertices[36], &vertices[37]);
edges.emplace_back(49, &vertices[28], &vertices[38]);
edges.emplace_back(50, &vertices[30], &vertices[40]);
edges.emplace_back(51, &vertices[32], &vertices[42]);
edges.emplace_back(52, &vertices[34], &vertices[44]);
edges.emplace_back(53, &vertices[36], & vertices[46]);
edges.emplace_back(54, &vertices[38], &vertices[39]);
edges.emplace_back(55, &vertices[39], &vertices[40]);
edges.emplace_back(56, &vertices[40], &vertices[41]);
edges.emplace_back(57, &vertices[41], &vertices[42]);
edges.emplace_back(58, &vertices[42], &vertices[43]);
edges.emplace_back(59, &vertices[43], &vertices[44]);
edges.emplace_back(60, &vertices[44], &vertices[45]);
edges.emplace_back(61, &vertices[45], &vertices[46]);
edges.emplace_back(62, &vertices[39], &vertices[47]);
edges.emplace_back(63, &vertices[41], &vertices[49]);
edges.emplace_back(64, &vertices[43], &vertices[51]);
edges.emplace_back(65, &vertices[45], &vertices[53]);
edges.emplace_back(66, &vertices[47], &vertices[48]);
edges.emplace_back(67, &vertices[48], &vertices[49]);
edges.emplace_back(68, &vertices[49], &vertices[50]);
edges.emplace_back(69, &vertices[50], &vertices[51]);
edges.emplace_back(70, &vertices[51], &vertices[52]);
edges.emplace_back(71, &vertices[52], &vertices[53]);
}

// Add edges to vertices
void Board::addEdgesToVertices() {
    vertices[0].addEdge(&edges[0]);
    vertices[0].addEdge(&edges[6]);
    vertices[1].addEdge(&edges[0]);
    vertices[1].addEdge(&edges[1]);
    vertices[2].addEdge(&edges[1]);
    vertices[2].addEdge(&edges[2]);
    vertices[2].addEdge(&edges[7]);
    vertices[3].addEdge(&edges[2]);
    vertices[3].addEdge(&edges[3]);
    vertices[4].addEdge(&edges[3]);
    vertices[4].addEdge(&edges[4]);
    vertices[4].addEdge(&edges[8]);
    vertices[5].addEdge(&edges[4]);
    vertices[5].addEdge(&edges[5]);
    vertices[6].addEdge(&edges[5]);
    vertices[6].addEdge(&edges[9]);
    vertices[7].addEdge(&edges[10]);
    vertices[7].addEdge(&edges[18]);
    vertices[8].addEdge(&edges[6]);
    vertices[8].addEdge(&edges[10]);
    vertices[8].addEdge(&edges[11]);
    vertices[9].addEdge(&edges[11]);
    vertices[9].addEdge(&edges[12]);
    vertices[9].addEdge(&edges[19]);
    vertices[10].addEdge(&edges[7]);
    vertices[10].addEdge(&edges[12]);
    vertices[10].addEdge(&edges[13]);
    vertices[11].addEdge(&edges[13]);
    vertices[11].addEdge(&edges[14]);
    vertices[11].addEdge(&edges[20]);
    vertices[12].addEdge(&edges[8]);
    vertices[12].addEdge(&edges[14]);
    vertices[12].addEdge(&edges[15]);
    vertices[13].addEdge(&edges[15]);
    vertices[13].addEdge(&edges[16]);
    vertices[13].addEdge(&edges[21]);
    vertices[14].addEdge(&edges[9]);
    vertices[14].addEdge(&edges[16]);
    vertices[14].addEdge(&edges[17]);
    vertices[15].addEdge(&edges[17]);
    vertices[15].addEdge(&edges[22]);
    vertices[16].addEdge(&edges[23]);
    vertices[16].addEdge(&edges[33]);
    vertices[17].addEdge(&edges[18]);
    vertices[17].addEdge(&edges[23]);
    vertices[17].addEdge(&edges[24]);
    vertices[18].addEdge(&edges[24]);
    vertices[18].addEdge(&edges[25]);
    vertices[18].addEdge(&edges[34]);
    vertices[19].addEdge(&edges[19]);
    vertices[19].addEdge(&edges[25]);
    vertices[19].addEdge(&edges[26]);
    vertices[20].addEdge(&edges[26]);
    vertices[20].addEdge(&edges[27]);
    vertices[20].addEdge(&edges[35]);
    vertices[21].addEdge(&edges[20]);
    vertices[21].addEdge(&edges[27]);
    vertices[21].addEdge(&edges[28]);
    vertices[22].addEdge(&edges[28]);
    vertices[22].addEdge(&edges[29]);
    vertices[22].addEdge(&edges[36]);
    vertices[23].addEdge(&edges[21]);
    vertices[23].addEdge(&edges[29]);
    vertices[23].addEdge(&edges[30]);
    vertices[24].addEdge(&edges[30]);
    vertices[24].addEdge(&edges[31]);
    vertices[24].addEdge(&edges[37]);
    vertices[25].addEdge(&edges[22]);
    vertices[25].addEdge(&edges[31]);
    vertices[25].addEdge(&edges[32]);
    vertices[26].addEdge(&edges[32]);
    vertices[26].addEdge(&edges[38]);
    vertices[27].addEdge(&edges[33]);
    vertices[27].addEdge(&edges[39]);
    vertices[28].addEdge(&edges[39]);
    vertices[28].addEdge(&edges[40]);
    vertices[28].addEdge(&edges[49]);
    vertices[29].addEdge(&edges[34]);
    vertices[29].addEdge(&edges[40]);
    vertices[29].addEdge(&edges[41]);
    vertices[30].addEdge(&edges[41]);
    vertices[30].addEdge(&edges[42]);
    vertices[30].addEdge(&edges[50]);
    vertices[31].addEdge(&edges[35]);
    vertices[31].addEdge(&edges[42]);
    vertices[31].addEdge(&edges[43]);
    vertices[32].addEdge(&edges[43]);
    vertices[32].addEdge(&edges[44]);
    vertices[32].addEdge(&edges[51]);
    vertices[33].addEdge(&edges[36]);
    vertices[33].addEdge(&edges[44]);
    vertices[33].addEdge(&edges[45]);
    vertices[34].addEdge(&edges[45]);
    vertices[34].addEdge(&edges[46]);
    vertices[34].addEdge(&edges[52]);
    vertices[35].addEdge(&edges[37]);
    vertices[35].addEdge(&edges[46]);
    vertices[35].addEdge(&edges[47]);
    vertices[36].addEdge(&edges[47]);
    vertices[36].addEdge(&edges[48]);
    vertices[36].addEdge(&edges[53]);
    vertices[37].addEdge(&edges[38]);
    vertices[37].addEdge(&edges[48]);
    vertices[38].addEdge(&edges[49]);
    vertices[38].addEdge(&edges[54]);
    vertices[39].addEdge(&edges[54]);
    vertices[39].addEdge(&edges[55]);
    vertices[39].addEdge(&edges[62]);
    vertices[40].addEdge(&edges[50]);
    vertices[40].addEdge(&edges[55]);
    vertices[40].addEdge(&edges[56]);
    vertices[41].addEdge(&edges[56]);
    vertices[41].addEdge(&edges[57]);
    vertices[41].addEdge(&edges[63]);
    vertices[42].addEdge(&edges[51]);
    vertices[42].addEdge(&edges[57]);
    vertices[42].addEdge(&edges[58]);
    vertices[43].addEdge(&edges[58]);
    vertices[43].addEdge(&edges[59]);
    vertices[43].addEdge(&edges[64]);
    vertices[44].addEdge(&edges[52]);
    vertices[44].addEdge(&edges[59]);
    vertices[44].addEdge(&edges[60]);
    vertices[45].addEdge(&edges[60]);
    vertices[45].addEdge(&edges[61]);
    vertices[45].addEdge(&edges[65]);
    vertices[46].addEdge(&edges[53]);
    vertices[46].addEdge(&edges[61]);
    vertices[47].addEdge(&edges[62]);
    vertices[47].addEdge(&edges[66]);
    vertices[48].addEdge(&edges[66]);
    vertices[48].addEdge(&edges[67]);
    vertices[49].addEdge(&edges[63]);
    vertices[49].addEdge(&edges[67]);
    vertices[49].addEdge(&edges[68]);
    vertices[50].addEdge(&edges[68]);
    vertices[50].addEdge(&edges[69]);
    vertices[51].addEdge(&edges[64]);
    vertices[51].addEdge(&edges[69]);
    vertices[51].addEdge(&edges[70]);
    vertices[52].addEdge(&edges[70]);
    vertices[52].addEdge(&edges[71]);
    vertices[53].addEdge(&edges[65]);
    vertices[53].addEdge(&edges[71]);

}

// Add vertices and edges to tiles
void Board::addVerticesAndEdgesToTiles() {
    // Each tile have 6 vertices (the numbers are the id vertices)
    std::vector<std::vector<int>> tileVertices = {
        {0, 1, 2, 8, 9, 10}, {2, 3, 4, 10, 11, 12}, {4, 5, 6, 12, 13, 14},
        {7, 8, 9, 17, 18, 19}, {9, 10, 11, 19, 20, 21}, {11, 12, 13, 21, 22, 23},
        {13, 14, 15, 23, 24, 25}, {16, 17, 18, 27, 28, 29}, {18, 19, 20, 29, 30, 31},
        {20, 21, 22, 31, 32, 33}, {22, 23, 24, 33, 34, 35}, {24, 25, 26, 35, 36, 37},
        {28, 29, 30, 38, 39, 40}, {30, 31, 32, 40, 41, 42}, {32, 33, 34, 42, 43, 44},
        {34, 35, 36, 44, 45, 46}, {39, 40, 41, 47, 48, 49}, {41, 42, 43, 49, 50, 51},
        {43, 44, 45, 51, 52, 53}
    };

    // Each tile have 6 edges (the numbers are the id edges)
    std::vector<std::vector<int>> hexEdges = {
        {0, 1, 6, 7, 11, 12}, {2, 3, 7, 8, 13, 14}, {4, 5, 8, 9, 15, 16},
        {10, 11, 18, 19, 24, 25}, {12, 13, 19, 20, 26, 27}, {14, 15, 20, 21, 28, 29},
        {16, 17, 21, 22, 30, 31}, {23, 24, 33, 34, 39, 40}, {25, 26, 34, 35, 41, 42},
        {27, 28, 35, 36, 43, 44}, {29, 30, 36, 37, 45, 46}, {31, 32, 37, 38, 47, 48},
        {40, 41, 49, 50, 54, 55}, {42, 43, 50, 51, 56, 57}, {44, 45, 51, 52, 58, 59},
        {46, 47, 52, 53, 60, 61}, {55, 56, 62, 63, 66, 67}, {57, 58, 63, 64, 68, 69},
        {59, 60, 64, 65, 70, 71}
    };

    // making sure that the number of tiles match the vertex and edge mappings
    if (tiles.size() != tileVertices.size() || tiles.size() != hexEdges.size()) {
        cout << "number of tiles: " << tiles.size() << endl << "number of tileVertices" 
        << tileVertices.size() << endl;
        throw std::runtime_error("Number of tiles does not match the provided vertex/edge mappings.");
    }

    // For every tile, add its vertices and edges
    for (size_t i = 0; i < tiles.size(); ++i) {
        for (int vertex : tileVertices[i]) {
            tiles[i].addVertex(&vertices.at(vertex));
        }
        for (int edge : hexEdges[i]) {
            tiles[i].addEdge(&edges.at(edge));
        }
    }

    // Set up adjacent tiles for each vertex
    for (Tile& tile : tiles) {
        for (Vertex* vertex : tile.getVertices()) {
            vertex->addAdjacentTile(&tile);
        }
    }
}



// Print the board
void Board::printBoard() const {
    // Print tiles
    std::cout << "Tiles:\n";
    for (Tile hex : tiles) {
        std::cout << "Tile ID: " << hex.getId()
                  << ", type: " << hex.getTileTypeString()
                  << ", resource type: " << hex.getResourceTypeString()
                  << ", Number: " << hex.getNumber() << "\n";
    }

    // Print vertices
    std::cout << "\nVertices:\n";
    for (Vertex vertex : vertices) {
        std::cout << "Vertex ID: " << vertex.getId() << ", Adjacent Vertices: ";
        for (Vertex* adjVertex : vertex.getAdjacentVertices()) {
            std::cout << adjVertex->getId() << " ";
        }
        std::cout << ",   near Tiles ID : ";
        for (Tile* adjHex : vertex.getAdjacentTiles()) {
            std::cout << adjHex->getId() << " ";
        }
        std::cout << "\n";
    }

    // Print edges
    std::cout << "\nEdges:\n";
    for (Edge edge : edges) {
        std::cout << "Edge ID: " << edge.getId()
                  << ", Vertex 1: " << edge.getVertex1()->getId()
                  << ", Vertex 2: " << edge.getVertex2()->getId() << "\n";
    }

    //Print vertices buildings
    std::cout << "\nVertices with buildings:\n";
    for (Vertex vertex : vertices) {
        if (vertex.getBuild() != 0) {
            std::cout << "Vertex ID: " << vertex.getId() << ", his building is : " << vertex.getBuildingString() << "\n";
        }
    }

    //Print edges with roads
    std::cout << "\nEdges with roads:\n";
    for (Edge edge : edges) {
        if (edge.getIsTaken()) {
            std::cout << "Edge ID: " << edge.getId()
                      << ", Vertex 1: " << edge.getVertex1()->getId()
                      << ", Vertex 2: " << edge.getVertex2()->getId()
                      << ", have road"
                      << "\n";
        }
    }
}
