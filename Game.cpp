/* 
 * File:   Game.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.59
 */

#include "Game.hpp"
#include "ConsoleView.hpp"
#include "ActionMovement.hpp"

Game::Game() {
    //call the constructor with number of player = 4
    Game(4);
}


Game::~Game() {
    //destruct the map
    delete (this -> map);
    //delete the view
    delete (this -> view);
    //for the list size
    for (int i = 0; i < (this -> playerList -> getSize()); i++) {
        //delete the player
        delete (this -> playerList -> get(i));
    }
    //delete the list
    delete (this -> playerList);
}

Game::Game(int nPlayer) {
    //if nPlayer is less than 2
    if(nPlayer < 2){
        //set as 2
        nPlayer = 2;
    }
    //save the number of player
    this -> nPlayer = nPlayer;
    //get the map singleton instance
    this -> map = Map::getInstance();
    //instance the view
    this -> view = new ConsoleView();
}

void Game::play() {
    
}

FedeList<Action*>* Game::computePlayerActions(Player* currentPlayer) {
    //create an empy list of action
    FedeList<Action*>* playerActions = new FedeList<Action*>();
    //get the room where the player is located and save it in a local variable
    Room* currentPlayerRoom = currentPlayer->getCurrentRoom();
    //add to the list the action to move east
    playerActions->push_back(new ActionMovement(currentPlayer,currentPlayerRoom->getEast()));
    //add to the list the action to move north
    playerActions->push_back(new ActionMovement(currentPlayer,currentPlayerRoom->getNorth()));
    //add to the list the action to move south
    playerActions->push_back(new ActionMovement(currentPlayer,currentPlayerRoom->getSouth()));
    //add to the list the action to move west
    playerActions->push_back(new ActionMovement(currentPlayer,currentPlayerRoom->getWest()));
    //return the list of action that the player can do
    return playerActions;
}

