#include "Player.hpp"
#include "Catan.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>

// Constructor
Player::Player(const std::string& name) 
    : playerName(name), myTurn(false), victoryPoints(0), totalResources(0), totalKnights(0), largestArmy(false) {}

// Get player name
const std::string& Player::getName() const {
    return playerName;
}

// Get victory points
int Player::getVictoryPoints() const {
    return victoryPoints;
}

// Get total resources
int Player::getTotalResources() const {
    return totalResources;
}

// Get total knights
int Player::getTotalKnights() const {
    return totalKnights;
}

// Check if player has largest army
bool Player::hasLargestArmy() const {
    return largestArmy;
}

// Start the player's turn
void Player::beginTurn() {
    myTurn = true;
    std::cout << playerName << "'s turn starts." << std::endl;
}

// End the player's turn
void Player::finishTurn(Catan& game) {
    myTurn = false;
    std::cout << playerName << "'s turn ends." << std::endl;
}

// Roll dice and distribute resources based on the outcome
void Player::rollDice(Catan& game) {
    int diceRoll = game.rollDice();
    std::cout << playerName << " rolled a " << diceRoll << "." << std::endl;
    game.distributeResources(diceRoll);
}

// Add resource to player's inventory
void Player::addResource(const std::string& resource, int amount) {
    resources[resource] += amount;
    totalResources += amount;
}

// Remove resource from player's inventory
void Player::removeResource(const std::string& resource, int amount) {
    if (resources[resource] < amount) {
        std::cout << "Not enough resources" << std::endl;
        return;
    }
    resources[resource] -= amount;
    totalResources -= amount;
}

// Get amount of a specific resource
int Player::getResourceCount(const std::string& resource) const {
    auto it = resources.find(resource);
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}

// Get all resources
const std::map<std::string, int>& Player::getAllResources() const {
    std::cout << playerName << " resources are: ";
    for (const auto& [resource, amount] : resources) {
        std::cout << resource << ": " << amount << " ";
    }
    std::cout << std::endl;
    return resources;
}

// Check if player has required resources
bool Player::hasRequiredResources(const std::map<std::string, int>& requiredResources) const {
    for (const auto& [resource, amount] : requiredResources) {
        if (getResourceCount(resource) < amount) {
            return false;
        }
    }
    return true;
}

// Place initial settlement
void Player::placeInitialSettlement(int vertexId, Board* board) {
    if (vertexId < 0 || vertexId > 53) {
        std::cout << getName() + ", you can't place a settlement, this vertex is not on the board!" << std::endl;
        return;
    }

    Vertex* vertex = &board->getVertices().at(vertexId);
    if (vertex->getOwner() != nullptr) {
        std::cout << getName() + ", you can't place a settlement here, this vertex is already taken." << std::endl;
        return;
    }

    // Check if all adjacent vertices are free
    const std::vector<Vertex*>& adjacentVertices = vertex->getAdjacentVertices();
    for (Vertex* adjVertex : adjacentVertices) {
        if (adjVertex->getBuild() != 0) {
            std::cout << getName() + ", you can't place a settlement here, there isn't a distance of 2 edges minimum from other buildings." << std::endl;
            return;
        }
    }

    // Place the settlement
    vertex->setBuild(1, this);
    settlements.push_back(vertex);
    incrementVictoryPoints();
    std::cout << getName() << " successfully placed an initial settlement on vertex ID: " << vertexId << std::endl;
}

// Place initial road
void Player::placeInitialRoad(int edgeId, Board* board) {
    if (edgeId < 0 || edgeId > 71) {
        std::cout << getName() + ", you can't place a road, this edge is not on the board!" << std::endl;
        return;
    }

    Edge* edge = &board->getEdges().at(static_cast<size_t>(edgeId));
    if (edge->getOwner() != nullptr) {
        std::cout << getName() + ", you can't place a road here, this edge is already occupied." << std::endl;
        return;
    }

    // Check if the road is connected to a settlement or another road
    bool canBuild = false;
    if ((edge->getVertex1()->getOwner() == this || edge->getVertex2()->getOwner() == this)) {
        canBuild = true;
    }
    for (Edge* road : roads) {
        if (edge->isNighnor(road)) {
            canBuild = true;
            break;
        }
    }
    if (!canBuild) {
        std::cout << getName() + ", you can't place a road here, it's not connected to your settlements or roads." << std::endl;
        return;
    }

    // Place the road
    edge->setOwner(this);
    roads.push_back(edge);
    std::cout << getName() << " successfully placed an initial road on edge ID: " << edgeId << std::endl;
}

// Build settlement
void Player::buildSettlement(int vertexId, Board* board) {
    // Check if it's the player's turn
    if (!myTurn) {
        std::cout << getName() + ", you can't build a settlement, it's not your turn!" << std::endl;
        return;
    }

    // Check for a valid vertex ID
    if (vertexId < 0 || vertexId > 53) {
        std::cout << getName() + ", you can't build a settlement, this vertex is not on the board!" << std::endl;
        return;
    }

    Vertex* vertex = &board->getVertices()[vertexId];

    // Check if the vertex is already taken
    if (vertex->getOwner() != nullptr) {
        std::cout << getName() + ", you can't place a settlement here, the vertex is already taken!" << std::endl;
        return;
    }

    // Check if all adjacent vertices are free
    const std::vector<Vertex*>& adjacentVertices = vertex->getAdjacentVertices();
    for (Vertex* adjVertex : adjacentVertices) {
        if (adjVertex->getBuild() != 0) {
            std::cout << getName() + ", you can't place a settlement here, there isn't a distance of 2 edges minimum from another building." << std::endl;
            return;
        }
    }

    // Define the price of a settlement
    std::map<std::string, int> price = {
        {Tile::Wood, 1},
        {Tile::Brick, 1},
        {Tile::Wheat, 1},
        {Tile::Wool, 1}
    };

    // Check if the player has the required resources
    if (!hasRequiredResources(price)) {
        std::cout << getName() + ", you can't build a settlement, not enough resources." << std::endl;
        return;
    }

    // Deduct the resources from the player's inventory
    for (const auto& resourceAndAmount : price) {
        removeResource(resourceAndAmount.first, resourceAndAmount.second);
    }

    // Set the owner of the vertex to the current player
    settlements.push_back(vertex);
    vertex->setBuild(1, this);  // 1 indicates a settlement
    incrementVictoryPoints();
    std::cout << getName() + " successfully built a settlement at vertex " << vertexId << "!\n";
}

// Build road
void Player::buildRoad(int edgeId, Board* board) {
    if (!myTurn) {
        std::cout << getName() + ", you can't build a road, it's not your turn!" << std::endl;
        return;
    }
    if (edgeId < 0 || edgeId > 71) {
        std::cout << getName() + ", you can't build a road, this edge is not on the board!" << std::endl;
        return;
    }
    Edge* edge = &board->getEdges()[edgeId];

    if (edge->getOwner() != nullptr) {
        std::cout << getName() + ", you can't build a road, this edge is already occupied." << std::endl;
        return;
    }

    bool canBuild = false;
    if ((edge->getVertex1()->getOwner() == this || edge->getVertex2()->getOwner() == this)) {
        canBuild = true;
    }
    for (Edge* road : roads) {
        if (edge->isNighnor(road)) {
            canBuild = true;
            break;
        }
    }
    if (!canBuild) {
        std::cout << getName() + ", you can't build a road, it's not allowed by the rules." << std::endl;
        return;
    }

    std::map<std::string, int> price = {
        {Tile::Wood, 1},
        {Tile::Brick, 1}
    };
    if (!hasRequiredResources(price)) {
        std::cout << "You can't build a road, not enough resources." << std::endl;
        return;
    }

    for (const auto& resourceAndAmount : price) {
        removeResource(resourceAndAmount.first, resourceAndAmount.second);
    }

    edge->setOwner(this);
    roads.push_back(edge);
    std::cout << getName() << " successfully built a road on edge ID: " << edgeId << std::endl;
}

// Upgrade settlement to city
void Player::upgradeToCity(int vertexId, Board* board) {
    if (hasRequiredResources({{Tile::Ore, 3}, {Tile::Wheat, 2}}) && myTurn) {
        Vertex* vertex = &board->getVertices()[static_cast<unsigned long>(vertexId - 1)];
        if (vertex && vertex->getOwner() == this && vertex->getBuild() != 2) {
            vertex->setBuild(2, this);
            cities.push_back(vertex);
            settlements.erase(std::remove(settlements.begin(), settlements.end(), vertex), settlements.end());
            incrementVictoryPoints();
            removeResource(Tile::Ore, 3);
            removeResource(Tile::Wheat, 2);
            std::cout << playerName << " upgraded a settlement to a city." << std::endl;
        } else {
            std::cout << "Invalid vertex for upgrading to city." << std::endl;
        }
    } else {
        std::cout << "Not enough resources to upgrade to city." << std::endl;
    }
}

// Purchase development card
void Player::purchaseDevelopmentCard(Catan& game) {
    if (hasRequiredResources({{Tile::Ore, 1}, {Tile::Wheat, 1}, {Tile::Wool, 1}}) && myTurn) {
        DevelopmentCard card = game.drawDevelopmentCard();
        developmentCards.push_back(card);
        removeResource(Tile::Ore, 1);
        removeResource(Tile::Wheat, 1);
        removeResource(Tile::Wool, 1);
        std::cout << playerName << " purchased a development card." << std::endl;
    } else {
        std::cout << "Not enough resources to purchase a development card." << std::endl;
    }
}

// Play development card
void Player::playDevelopmentCard(const std::string& cardType, Catan& game) {
    auto it = std::find_if(developmentCards.begin(), developmentCards.end(), 
        [&cardType](const DevelopmentCard& card) {
            return card.getType() == cardType;
        });
    
    if (it != developmentCards.end()) {
        std::cout << playerName << " plays a development card: " << DevelopmentCard::getCardTypeString(cardType) << std::endl;
        if (cardType == DevelopmentCard::Type::Monopoly) {
            // Monopoly logic
            playMonopoly(game);
        } else if (cardType == DevelopmentCard::Type::RoadBuilding) {
            // Road Building logic
            playRoadBuilding(game);
        } else if (cardType == DevelopmentCard::Type::YearOfPlenty) {
            // Year of Plenty logic
            playYearOfPlenty();
        } else if (cardType == DevelopmentCard::Type::Knight) {
            incrementKnights();
            
        } else if (cardType == DevelopmentCard::Type::VictoryPoint) {
            incrementVictoryPoints();
        }
        developmentCards.erase(it);
    } else {
        std::cout << "Player does not have the specified development card." << std::endl;
    }
}

// Get settlements
std::vector<Vertex*> Player::getSettlements() const {
    return settlements;
}

// Get development cards
std::vector<DevelopmentCard> Player::getDevelopmentCards() const {
    return developmentCards;
}

// Get roads
std::vector<Edge*> Player::getRoads() const {
    return roads;
}

// Get cities
std::vector<Vertex*> Player::getCities() const {
    return cities;
}

// Trade resources
void Player::tradeResources(Player* other, const std::string& giveType, int giveAmount, const std::string& receiveType, int receiveAmount) {
    if (getResourceCount(giveType) >= giveAmount && other->getResourceCount(receiveType) >= receiveAmount) {
        removeResource(giveType, giveAmount);
        other->addResource(giveType, giveAmount);
        addResource(receiveType, receiveAmount);
        other->removeResource(receiveType, receiveAmount);
        std::cout << playerName << " traded " << giveAmount << " " << giveType << " for " << receiveAmount << " " << receiveType << " with " << other->getName() << std::endl;
    } else {
        std::cout << "Not enough resources for trade." << std::endl;
    }
}

void Player::incrementVictoryPoints() {
    victoryPoints++;
}

void Player::decrementVictoryPoints() {
    victoryPoints--;
}

void Player::incrementKnights() {
    totalKnights++;
}

void Player::decrementKnights() {
    totalKnights--;
}

void Player::playMonopoly(Catan& game) {
    std::string resource;
    std::cout << "Choose a resource type to monopolize: ";
    std::cin >> resource;
    
    int totalResource = 0;
    for (const auto& player : game.getPlayers()) {
        if (player != this) {
            int resourceAmount = player->getResourceCount(resource);
            player->removeResource(resource, resourceAmount);
            totalResource += resourceAmount;
        }
    }
    addResource(resource, totalResource);
    std::cout << playerName << " has monopolized " << totalResource << " units of " << resource << "!\n";
}

void Player::playRoadBuilding(Catan& game) {
    for (int i = 0; i < 2; ++i) {
        int edgeId;
        std::cout << "Choose an edge to build a road (road " << i + 1 << "): ";
        std::cin >> edgeId;
        buildRoad(edgeId, game.getBoard());
    }
}

void Player::playYearOfPlenty() {
    for (int i = 0; i < 2; ++i) {
        std::string resource;
        std::cout << "Choose a resource to gain (resource " << i + 1 << "): ";
        std::cin >> resource;
        addResource(resource, 1);
    }
}
