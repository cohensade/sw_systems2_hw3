# Catan Game

## Author
My name is Daniel Cohen Sade.  
Email: danielcohen1717@gmail.com

## Overview
This project is a C++ implementation of the Catan game. The game includes 3 players, each of whom can perform actions such as trading with each other, building settlements, roads, and cities, buying development cards, and other actions.

## File Structure
The project is organized into several header and source files, each representing different components and functionalities of the game.

- `Board.hpp`: Defines the `Board` class, which manages the game board, including tiles, vertices, and edges.
- `Catan.hpp`: Defines the `Catan` class, which manages the overall game, including players and the game board.
- `DevelopmentCard.hpp`: Defines the `DevelopmentCard` class, which represents development cards that players can purchase and use.
- `Edge.hpp`: Defines the `Edge` class, which represents edges on the game board where players can build roads.
- `Player.hpp`: Defines the `Player` class, which represents a player in the game.
- `Tile.hpp`: Defines the `Tile` class, which represents resource tiles on the game board.
- `Vertex.hpp`: Defines the `Vertex` class, which represents vertices on the game board where players can build settlements and cities.
- `Test.cpp`: Contains unit tests for the various classes using the `doctest` framework.

## Dependencies
- C++17 standard
- `doctest` framework for unit testing

## Compilation
The project uses a `Makefile` for compilation. The makefile defines targets for building the main game, demo, and test binaries.

## Running the Game
To compile and run the game, follow these steps:

1. **Compile the project:**
    ```sh
    make
    ```

2. **Run the tests:**
    ```sh
    ./test
    ```

3. **Run the demo:**
    ```sh
    ./demo
    ```

### Example Output
The demo will simulate one round of the game.

## Detailed File Descriptions

### Board.hpp
- Manages the game board, including initialization of tiles, vertices, and edges.
- Functions include:
  - `initializeBoard()`: Initializes the board with tiles, vertices, and edges.
  - `getEdges()`: Retrieves the edges on the board.
  - `getVertices()`: Retrieves the vertices on the board.
  - `getTiles()`: Retrieves the tiles on the board.

### Catan.hpp
- Manages the overall game state, including players and the board.
- Functions include:
  - `Catan(std::vector<Player*>& players)`: Constructor to initialize the game with players.
  - `getBoard()`: Retrieves the game board.
  
  

### DevelopmentCard.hpp
- Represents development cards in the game.
- Functions include:
  - `DevelopmentCard(const std::string& type)`: Constructor to initialize a development card with a type.
  - `getType()`: Retrieves the type of the development card.

### Edge.hpp
- Represents edges on the game board where players can build roads.
- Functions include:
  - `Edge(int id, Vertex* vertex1, Vertex* vertex2)`: Constructor to initialize an edge with an ID and connected vertices.
  - `getId()`: Retrieves the ID of the edge.
  - `getVertex1()`: Retrieves the first vertex connected to the edge.
  - `getVertex2()`: Retrieves the second vertex connected to the edge.
  - `getIsTaken()`: Checks if the edge is taken.
  - `getOwner()`: Retrieves the owner of the edge.
  - `setOwner(Player* player)`: Sets the owner of the edge.

### Player.hpp
- Represents a player in the game.
- Functions include:
  - `Player(const std::string& playerName)`: Constructor to initialize a player with a name.
  - `getName()`: Retrieves the name of the player.
  - `addResource(const std::string& resource, int amount)`: Adds resources to the player's inventory.
  - `removeResource(const std::string& resource, int amount)`: Removes resources from the player's inventory.
  - `getResources()`: Retrieves the player's resources.
  - `buildSettlement(Vertex* vertex)`: Builds a settlement at the given vertex.
  - `buildRoad(Edge* edge)`: Builds a road at the given edge.
  - `buyDevelopmentCard()`: Buys a development card for the player.

### Tile.hpp
- Represents resource tiles on the game board.
- Functions include:
  - `Tile(int id, const std::string& type, int number)`: Constructor to initialize a tile with an ID, type, and number.
  - `getId()`: Retrieves the ID of the tile.
  - `getType()`: Retrieves the type of the tile.
  - `getNumber()`: Retrieves the number of the tile.
  - `addVertex(Vertex* vertex)`: Adds a vertex to the tile.
  - `getVertices()`: Retrieves the vertices associated with the tile.

### Vertex.hpp
- Represents vertices on the game board where players can build settlements and cities.
- Functions include:
  - `Vertex(int id)`: Constructor to initialize a vertex with an ID.
  - `getId()`: Retrieves the ID of the vertex.
  - `getOwner()`: Retrieves the owner of the vertex.
  - `setOwner(Player* player)`: Sets the owner of the vertex.
  - `addAdjacentTile(Tile* tile)`: Adds an adjacent tile to the vertex.
  - `getAdjacentTiles()`: Retrieves the adjacent tiles of the vertex.
  - `addAdjacentVertex(Vertex* vertex)`: Adds an adjacent vertex.
  - `getAdjacentVertices()`: Retrieves the adjacent vertices.
  - `isNighbor(Vertex& vertex)`: Checks if the given vertex is adjacent.
  - `addEdge(Edge* edge)`: Adds an edge to the vertex.
  - `getEdges()`: Retrieves the edges associated with the vertex.

## Detailed File Descriptions

### Board.hpp
- Manages the game board, including initialization of tiles, vertices, and edges.
- Functions include initialization, retrieving edges, and managing game state.

### Catan.hpp
- Manages the overall game state, including players and the board.
- Functions include game setup, turn management, and action execution.

### DevelopmentCard.hpp
- Represents development cards in the game.
- Functions include initialization and card type retrieval.

### Edge.hpp
- Represents edges on the game board where players can build roads.
- Functions include initialization, setting and getting the owner, and retrieving connected vertices.

### Player.hpp
- Represents a player in the game.
- Functions include managing player resources, actions, and status.

### Tile.hpp
- Represents resource tiles on the game board.
- Functions include initialization, resource type retrieval, and managing associated vertices.

### Vertex.hpp
- Represents vertices on the game board where players can build settlements and cities.
- Functions include initialization, setting and getting the owner, managing adjacent tiles and vertices, and checking adjacency.

### Test.cpp
- Contains unit tests for the various classes using the `doctest` framework.
- Tests include initialization and basic functionality for `Board`, `Catan`, `DevelopmentCard`, `Edge`, `Player`, `Tile`, and `Vertex`.

