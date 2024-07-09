//mail: danielcohen1717@gmail.com

#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "Player.hpp"
#include "Board.hpp"
#include "DevelopmentCard.hpp"
using namespace std;



class Catan {
public:
    Catan(std::vector<Player*>& players);//constructor
    void nextTurn(); //
    void endGame();//ending the game
    int rollDice(); //rolldice
    void distributeResources(int diceRoll); //get each player the resource according to the dice
    DevelopmentCard drawDevelopmentCard(); //drawing the cards
    void initializeBoard(); //create board
    void whostart(); //select the starting player
    Board* getBoard(); //get the board
    void giveStartingResources(); //give starting resources  according to the initial settlements
    void getWinner(); //get game winner
    std::vector<Player*>& getPlayers();

private:
    std::vector<Player*> players; //players that play the game
    vector<DevelopmentCard> developmentDeck; //deck of development cards
    Board gameBoard; //the board
    int currentPlayerIndex; //the index of the current palyer

    void initializeDevelopmentDeck(); //building the deck
    void shuffleDevelopmentDeck(); //shuffle the deck
};

#endif // CATAN_HPP
