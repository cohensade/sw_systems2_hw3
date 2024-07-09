//mail: danielcohen1717@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main() {
    Player* p1 = new Player("Amit");
    Player* p2 = new Player("Yossi");
    Player* p3 = new Player("Dana");
    std::vector<Player*> players = {p1, p2, p3};
    Catan game(players);

    // Starting of the game. Every player places two settlements and two roads.
    Board* board = game.getBoard(); // get the board of the game.

    p1->placeInitialSettlement(3, board);
    p1->placeInitialRoad(3, board);
    p1->placeInitialSettlement(12, board);
    p1->placeInitialRoad(8, board);

    p2->placeInitialSettlement(50, board);
    p2->placeInitialRoad(69, board);
    p2->placeInitialSettlement(52, board);
    p2->placeInitialRoad(71, board);

    p3->placeInitialSettlement(30, board);
    p3->placeInitialRoad(42, board);
    p3->placeInitialSettlement(32, board);
    p3->placeInitialRoad(43, board);

    game.giveStartingResources();

    // Print out each player's resources
    std::cout << p1->getName() << " has the following resources:\n";
    for (const auto& [resource, amount] : p1->getAllResources()) {
        // std::cout << resource << ": " << amount << "\n";
    }

    std::cout << p2->getName() << " has the following resources:\n";
    for (const auto& [resource, amount] : p2->getAllResources()) {
        // std::cout << resource << ": " << amount << "\n";
    }

    std::cout << p3->getName() << " has the following resources:\n";
    for (const auto& [resource, amount] : p3->getAllResources()) {
        // std::cout << resource << ": " << amount << "\n";
    }

    std::cout << p1->getName() << " has " << p1->getVictoryPoints() << " points after initial placement.\n";
    std::cout << p2->getName() << " has " << p2->getVictoryPoints() << " points after initial placement.\n";
    std::cout << p3->getName() << " has " << p3->getVictoryPoints() << " points after initial placement.\n";

    // Conduct one round of the game
    for (Player* player : players) {
        std::cout << player->getName() << "'s turn.\n";

        // Player rolls the dice
        player->rollDice(game);

        // Player tries to build a settlement if they have enough resources
        if (player->hasRequiredResources({{Tile::Wood, 1}, {Tile::Brick, 1}, {Tile::Wheat, 1}, {Tile::Wool, 1}})) {
            try {
                if (player->getName() == "Amit") {
                    player->buildSettlement(10, board);
                } else if (player->getName() == "Yossi") {
                    player->buildSettlement(48, board);
                } else if (player->getName() == "Dana") {
                    player->buildSettlement(28, board);
                }
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }

        // Player tries to purchase a development card if they have enough resources
        if (player->hasRequiredResources({{Tile::Ore, 1}, {Tile::Wheat, 1}, {Tile::Wool, 1}})) {
            try {
                player->purchaseDevelopmentCard(game);
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }

        // Player tries to upgrade settlements to cities if they have enough resources
        std::vector<int> cityUpgradeVertices = {3, 12, 50, 52, 30};
        for (int vertex : cityUpgradeVertices) {
            if (player->hasRequiredResources({{Tile::Ore, 3}, {Tile::Wheat, 2}})) {
                try {
                    player->upgradeToCity(vertex, board);
                } catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }

        // Player plays any development cards they have
        for (const auto& card : player->getDevelopmentCards()) {
            try {
                player->playDevelopmentCard(card.getType(), game);
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }

        // Print out each player's resources
        std::cout << player->getName() << " has the following resources:\n";
        for (const auto& [resource, amount] : player->getAllResources()) {
            std::cout << resource << ": " << amount << "\n";
        }

        // Print out each player's victory points
        std::cout << p1->getName() << " has " << p1->getVictoryPoints() << " points.\n";
        std::cout << p2->getName() << " has " << p2->getVictoryPoints() << " points.\n";
        std::cout << p3->getName() << " has " << p3->getVictoryPoints() << " points.\n";

        // Finish player's turn
        player->finishTurn(game);
    }

    // Free memory
    for (Player* player : players) {
        delete player;
    }

    return 0;
}
