/* 
 * File:   Game.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.59
 */

#include "Game.hpp"
#include "ConsoleView.hpp"
#include "ActionRelativeMovement.hpp"

Game::Game() {
    //call the init with number of player = 4
    this -> init(4);
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
    //call the init with the give number of player
    this -> init(nPlayer);
}

void Game::init(int nPlayer) {
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
    //TODO: complete implementation.
    
    //the result list
    FedeList<Action*>* result = new FedeList<Action*>();
    //add the north relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_NORTH, this -> map));
    //add the south relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_SOUTH, this -> map));
    //add the east relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_EAST, this -> map));
    //add the west relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_WEST, this -> map));
    
    //TODO: add combat
    //TODO: add item pickup/drop
    //TODO: add armor wear/unwear
    
    //return the result list
    return result;
}
