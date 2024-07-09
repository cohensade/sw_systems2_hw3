#include "Catan.hpp"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

// Constructor
Catan::Catan(std::vector<Player*>& players) : players(players), currentPlayerIndex(0) {
    initializeBoard();
    initializeDevelopmentDeck();
}

Board* Catan::getBoard() {
    return &gameBoard;
}

// initialize the development deck
void Catan::initializeDevelopmentDeck() {
    // add development cards to the deck
    for (int i = 0; i < 14; ++i) developmentDeck.emplace_back(DevelopmentCard::Type::Knight);
    for (int i = 0; i < 5; ++i) developmentDeck.emplace_back(DevelopmentCard::Type::VictoryPoint);
    for (int i = 0; i < 2; ++i) {
        developmentDeck.emplace_back(DevelopmentCard::Type::Monopoly);
        developmentDeck.emplace_back(DevelopmentCard::Type::RoadBuilding);
        developmentDeck.emplace_back(DevelopmentCard::Type::YearOfPlenty);
    }
    shuffleDevelopmentDeck();
}

// Shuffle the development deck
void Catan::shuffleDevelopmentDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(developmentDeck.begin(), developmentDeck.end(), g);
}

// Initialize the game board
void Catan::initializeBoard() {
    gameBoard.initializeBoard();
}



// Distribute resources based on dice roll
void Catan::distributeResources(int diceRoll) {
    for (auto& tile : gameBoard.getTiles()) {
        if (tile.getNumber() == diceRoll) {
            for (auto vertex : tile.getVertices()) {
                // Check if the vertex has a settlement or city
                if (vertex->getOwner() != nullptr) {
                    Player* owner = vertex->getOwner();
                    std::string resourceType = tile.getResourceType();

                    // Determine the amount of resource based on the type of building
                    int resourceAmount = 0;
                    if (vertex->getBuild() == 1) {
                        resourceAmount = 1;
                    } else if (vertex->getBuild() == 2) {
                        resourceAmount = 2;
                    }

                    // Add resources to the player
                    owner->addResource(resourceType, resourceAmount);
                    std::cout << owner->getName() << " received " << resourceAmount << " " << resourceType << "(s) from tile " << tile.getId() << std::endl;
                }
            }
        }
    }
}

// Draw a development card
DevelopmentCard Catan::drawDevelopmentCard() {
    if (developmentDeck.empty()) {
        throw std::out_of_range("Development deck is empty");
    }
    DevelopmentCard card = developmentDeck.back();
    developmentDeck.pop_back();
    return card;
}

// End the game
void Catan::endGame() {
    std::cout << "Game over. Player " << players[currentPlayerIndex]->getName() << " wins!" << std::endl;
}

// Proceed to the next turn
void Catan::nextTurn() {
    players[currentPlayerIndex]->finishTurn(*this);
    currentPlayerIndex++;
    if (currentPlayerIndex >= players.size()) {
        currentPlayerIndex = 0;
    }
    players[currentPlayerIndex]->beginTurn();
}

// Roll dice
int Catan::rollDice() {
    // Create a random device to seed the random number generator
    std::random_device rd;

    // Initialize a default random engine with the seed
    std::default_random_engine generator(rd());

    // Create a uniform integer distribution to simulate a six-sided die
    std::uniform_int_distribution<int> distribution(1, 6);

    // Generate two random numbers between 1 and 6
    int dice1 = distribution(generator);
    int dice2 = distribution(generator);

    // Return the sum of the two dice rolls
    return dice1 + dice2;
}

void Catan::whostart(){
    players[currentPlayerIndex]->beginTurn();
}

//give resources to players based on the strating settlements of the players
void Catan::giveStartingResources() {
    for (Player* player : players) {
        for (Vertex* settlement : player->getSettlements()) {
            for (Tile* tile : settlement->getAdjacentTiles()) {
                player->addResource(tile->getResourceType(), 1);
            }
        }
    }
}

std::vector<Player*>& Catan::getPlayers() {
    return players;
}

void Catan::getWinner() {
    for (auto* player : players) {
        if (player->getVictoryPoints() >= 10) {
            std::cout << "The winner is: " << player->getName() << std::endl;
            return;
        }
    }
    std::cout << "No player has reached 10 points yet." << std::endl;
}
