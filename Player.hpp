//mail: danielcohen1717@gmail.com
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include "DevelopmentCard.hpp"
#include "Tile.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Board.hpp"

class Catan; // Forward declaration
class Board;

using namespace std;

class Player {  
 private:
    string playerName; //name of the player
    bool myTurn; //turn
    int victoryPoints; //points
    int totalResources; //
    int totalKnights; //how many knights player have
    bool largestArmy; //if he have the largest army
    map<string, int> resources; //map that represent each resource of player for example {"ore" , 10}
    vector<Vertex*> settlements; //player's settlements
    vector<Vertex*> cities; //player's cities
    vector<Edge*> roads; //player's roads
    vector<DevelopmentCard> developmentCards; //player's development cards

    void incrementVictoryPoints(); //add 1 point
    void decrementVictoryPoints(); //decrease one point
    void incrementKnights(); //add 1 knight
    void decrementKnights(); //decrease 1 knight
    

public:
    Player(const string& playerName); //constructor

    const string& getName() const; //get the player's name
    int getVictoryPoints() const;//get player's points
    int getTotalResources() const;// get playre's resources
    int getTotalKnights() const; //get player's knights

    void rollDice(Catan& game); //player roll dice 
    void beginTurn();//starting the turn
    void finishTurn(Catan& game);//finish the player's turn
    bool hasLargestArmy() const;//largest army

    // Resource management
    void addResource(const string& resourceType, int amount); //adding resource
    void removeResource(const string& resourceType, int amount); //remove ""
    int getResourceCount(const string& resourceType) const; 
    const std::map<std::string, int>& getAllResources() const;
    bool hasRequiredResources(const map<string, int>& requiredResources) const;//has the amount he needed for action

    // Building management
    //place the starting settlements
    void placeInitialSettlement(int vertexId, Board* board);
    //place the starting roads
    void placeInitialRoad(int edgeId, Board* board);
    //build the settlements
    void buildSettlement(int vertexId, Board* board);
    //build roads
    void buildRoad(int edgeId, Board* board);
    //build city 
    void upgradeToCity(int vertexId, Board* board);

    // Development cards
    void purchaseDevelopmentCard(Catan& game);//buy dev card
    void playDevelopmentCard(const string& cardType, Catan& game);//play dev card
    void playMonopoly(Catan& game); // play monopoly dev card
    void playRoadBuilding(Catan& game); //play road dev card
    void playYearOfPlenty(); // play yop dev card
    
    // Getters for game elements
    vector<Vertex*> getSettlements() const; //gets player's sett
    vector<DevelopmentCard> getDevelopmentCards() const;// get player's dev cards
    vector<Edge*> getRoads() const;//get player's roads
    vector<Vertex*> getCities() const; //get player's cities
    

    // Trading
    void tradeResources(Player* other, const string& giveType, int giveAmount, const string& receiveType, int receiveAmount);
    //void tradeDevelopmentCards(Player* other, const string& giveCardType, const string& receiveCardType);
};

#endif // PLAYER_HPP
