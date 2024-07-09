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
The demo will simulate one round of the game, showcasing various functionalities and interactions between players.

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

