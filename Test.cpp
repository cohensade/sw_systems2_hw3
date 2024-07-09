#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Player.hpp"
#include "Catan.hpp"
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Board.hpp"
#include "Edge.hpp"
#include "DevelopmentCard.hpp"

// Test case for initializing the game and basic functionality
TEST_CASE("Initialization and basic functionality tests") {
    // Creating players
    Player* p1 = new Player("Amit");
    Player* p2 = new Player("Yossi");
    Player* p3 = new Player("Dana");
    std::vector<Player*> players = {p1, p2, p3};

    // Creating a Catan game instance
    Catan game(players);
    Board* board = game.getBoard();
    
    // Sub-case for testing player initialization
    SUBCASE("Player initialization test") {
        REQUIRE(players.size() == 3);
        REQUIRE(players[0]->getName() == "Amit");
        REQUIRE(players[1]->getName() == "Yossi");
    }

    // Sub-case for testing board initialization
    SUBCASE("Board init test") {
        CHECK(board->getEdges().at(0).getIsTaken() == false);
    }

    // Cleaning up dynamically allocated players
    for (Player* player : players) {
        delete player;
    }
}

// Test case for Edge class functionality
TEST_CASE("Edge functionality tests") {
    // Creating vertices
    Vertex v1(1), v2(2);

    // Creating an edge between the vertices
    Edge edge(0, &v1, &v2);

    // Sub-case for testing edge initialization
    SUBCASE("Edge initialization") {
        REQUIRE(edge.getVertex1()->getId() == 1);
        REQUIRE(edge.getVertex2()->getId() == 2);
        REQUIRE(edge.getId() == 0);
        REQUIRE(edge.getOwner() == nullptr);
    }

    // Sub-case for testing setting and getting the owner of an edge
    SUBCASE("Setting and getting owner") {
        Player player("TestPlayer");
        edge.setOwner(&player);
        REQUIRE(edge.getOwner()->getName() == "TestPlayer");
    }
}

// Test case for Vertex class functionality
TEST_CASE("Vertex functionality tests") {
    // Creating a vertex
    Vertex vertex(0);

    // Sub-case for testing vertex initialization
    SUBCASE("Vertex initialization") {
        REQUIRE(vertex.getId() == 0);
        REQUIRE(vertex.getOwner() == nullptr);
    }

    // Sub-case for testing setting and getting the owner and settlement of a vertex
    SUBCASE("Setting and getting owner and settlement") {
        Player player("TestPlayer");
        vertex.setOwner(&player);
        REQUIRE(vertex.getOwner()->getName() == "TestPlayer");
    }

    // Sub-case for testing adding and retrieving adjacent tiles
    SUBCASE("Adding and retrieving adjacent tiles") {
        Tile tile(0, "Grain", 8);
        vertex.addAdjacentTile(&tile);
        REQUIRE(vertex.getAdjacentTiles().size() == 1);
        REQUIRE(vertex.getAdjacentTiles()[0]->getId() == 0);
    }

    // Sub-case for testing adding and retrieving adjacent vertices
    SUBCASE("Adding and retrieving neighbors") {
        Vertex v1(1), v2(2);
        vertex.addAdjacentVertex(&v1);
        vertex.addAdjacentVertex(&v2);
        REQUIRE(vertex.getAdjacentVertices().size() == 2);
        REQUIRE(vertex.isAdjacemt(v1));
        REQUIRE(vertex.isAdjacemt(v2));
    }

    // Sub-case for testing adding and retrieving edges
    SUBCASE("Adding and retrieving edges") {
        Edge edge(0, &vertex, &vertex);
        vertex.addEdge(&edge);
        REQUIRE(vertex.getEdges().size() == 1);
        REQUIRE(vertex.getEdges()[0]->getId() == 0);
    }
}

// Test case for DevelopmentCard class functionality
TEST_CASE("DevelopmentCard functionality tests") {
    // Creating a development card
    DevelopmentCard card("Knight");
    
    // Sub-case for testing development card initialization
    SUBCASE("DevelopmentCard initialization") {
        REQUIRE(card.getType() == "Knight");
    }

    
}
