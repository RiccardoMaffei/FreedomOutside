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
    //instance the player list
    this -> playerList = new FedeList<Player*>();
}


void Game::play() {
    //show the splash screen
    this -> view -> showSplash();
    //show the prologue
    this -> view -> showPrologue();
    //for the number of player
    for (int i = 0; i < this -> nPlayer; i++) {
        //the username
        char username[50];
        //get the username
        this -> view -> getUsername(username);
        //instance a new player
        Player* player = new Player(username, this -> map -> getEntryPoint());
        //add the player to the player list
        this -> playerList -> push_back(player);
    }
    //while should run
    while(shouldRun()){
        //TODO: implement
    }
    
}

bool Game::shouldRun() {
    //player alive
    int pAlive = 0;
    //counter
    int i = 0;
    //while player alive are less than 2 and the list is not finished
    while (pAlive < 2 && i < (this -> playerList -> getSize())){
        //if the health is greater than 0
        if(this -> playerList -> get(i) -> getHealth() > 0){
            //increase the alive player counter
            pAlive++;
        }
        //increase the counter
        i++;
    }
    //return true if pAlive is greater than 1
    return (pAlive > 1);
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
