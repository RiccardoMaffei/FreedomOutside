/* 
 * File:   Game.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.59
 */

#include "Game.hpp"
#include "ConsoleView.hpp"
#include "ActionRelativeMovement.hpp"
#include "ActionDrop.hpp"
#include "ItemSimpleWeapon.hpp"
#include "ItemDestructiveWeapon.hpp"
#include "ItemHealthKit.hpp"
#include "ActionCombat.hpp"
#include "ActionHeal.hpp"
#include "ActionPickup.hpp"
#include "ActionWear.hpp"
#include "ActionUnwear.hpp"
#include "ActionWait.hpp"

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
    //init cur player
    this -> currPlayer = -1;
}


void Game::play() {
    //show the splash screen
    this -> view -> showSplash();
    //show the prologue with the accurate number of player
    this -> view -> showPrologue(this->nPlayer);
    //populate the list of player
    populatePlayers();
    //the current player
    Player* curP = NULL;
    //while should run
    while(shouldRun()){
        //clear the view
        this -> view -> clear();
        //get the next player
        curP = getNextPlayer();
        //show the map
        this ->view -> showMap(this -> map, curP);
        //get the roommates
        FedeList<Player*>* roomMates = this -> getRoomMates(curP);
        //show player info
        this -> view -> showPlayerInfo(curP);
        //show players in this room
        this -> view -> showShortInfo(roomMates);
        //copute player actions
        FedeList<Action*>* actions = this -> computePlayerActions(curP);
        //get the action selected by the user
        Action* actionToExecute = this -> view -> selectAction(actions);
        //execute the action
        actionToExecute->execute();
        //show action outcome
        this -> view -> showActionOutcome(actionToExecute);
        //for the list of actions
        for(int i = 0; i < actions -> getSize(); i++){
            //delete the action at i
            delete (actions -> get(i));
        }
        //delete the list itself
        delete actions;
        //delete the list of roommates
        delete roomMates;
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
        if(this -> playerList -> get(i) -> isAlive()){
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
    //the result list
    FedeList<Action*>* result = new FedeList<Action*>();
    //add the action of doing nothing
    result -> push_back(new ActionWait());
    //add the north relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_NORTH, this -> map));
    //add the south relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_SOUTH, this -> map));
    //add the east relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_EAST, this -> map));
    //add the west relative movement
    result -> push_back(new ActionRelativeMovement(currentPlayer, TO_WEST, this -> map));
    //get the player inventory
    FedeList<Item*>* inventory = currentPlayer -> getInventory();
    //get the room mates
    FedeList<Player*>* roomMates = this -> getRoomMates(currentPlayer);
    //for the inventory list
    for(int i = 0; i < inventory -> getSize(); i++){
        //current item
        Item* curItem = inventory -> get(i);
        //add the drop action for the current item
        result -> push_back(new ActionDrop(currentPlayer, curItem));
        //if the item is a simple weapon
        if (dynamic_cast<ItemSimpleWeapon*>(curItem)){
            //for all room mates
            for(int i = 0; i < roomMates -> getSize(); i++){
                //add the combat action for the current item
                result -> push_back(new ActionCombat(currentPlayer, (ItemSimpleWeapon*) curItem, new FedeList<Player*>(roomMates -> get(i))));
            }
        }
        //else if the item is a destructive weapon
        else if (dynamic_cast<ItemDestructiveWeapon*>(curItem)){
            //get another list with room mates and add myself
            FedeList<Player*>* fullList = this -> getRoomMates(currentPlayer) -> push_front(currentPlayer);
            //add the combat action for the current item
            result -> push_back(new ActionCombat(currentPlayer, (ItemSimpleWeapon*) curItem, fullList));
        }
        //else if the item is an health kit
        else if (dynamic_cast<ItemHealthKit*>(curItem)){
            //add the heal action for the current item
            result -> push_back(new ActionHeal((ItemHealthKit*) curItem, currentPlayer));
        }
        //else if the item is an armor
        else if (dynamic_cast<ItemArmor*>(curItem)){
            //if the player is not wearing an armor
            if (currentPlayer -> getArmor() == NULL){
                result->push_back(new ActionWear(currentPlayer,(ItemArmor*)curItem));
            }
        }
    }
    //if the inventori is not full
    if(inventory -> getSize() < 5){
        //get the items on the ground
        FedeList<Item*>* itemsOnGround = currentPlayer -> getCurrentRoom() -> getItemList();
        //for the list of items on the ground
        for(int i = 0; i < itemsOnGround -> getSize(); i++){
            //add the pickup action for the current item
            result -> push_back(new ActionPickup(currentPlayer, itemsOnGround -> get(i)));
        }
        //if the player is wearing an armor
        if (currentPlayer -> getArmor() != NULL){
            result->push_back(new ActionUnwear(currentPlayer));
        }
    }
    //return the result list
    return result;
}

void Game::populatePlayers() {
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
}

Player* Game::getNextPlayer(){
    //create and initialize the return Player pointer
    Player* nextPlayer = NULL;
    //create and initialize playerList's index to the next player in playerList
    int i = this -> currPlayer + 1;
    //number the player checked 
    int checked = 0;
    //while the player has not been found and chacked less than the whole list of player
    while(checked < playerList -> getSize() && nextPlayer == NULL){
        //if i went ot of bound
        if(i > (playerList -> getSize() -1)){
            //reset to 0 (simulate circularity)
            i = 0;
        }
        //if the i-th Player in playerList is alive
        if(playerList -> get(i)->isAlive()){
            //the return Player pointer is update to the i-th Player alive in playerList
            nextPlayer = playerList ->get(i);
            //the index of the current Player is updated
            this -> currPlayer = i;
        }
        //else (the current is dead)
        else{
            //increase the index
            i++;
        }
        //increase the checked counter
        checked++;
    }
    //return the pointer to the next alive Player in playerList, if i'ts NULL, all players are dead
    return nextPlayer;
}

FedeList<Player*>* Game::getRoomMates(Player* player) {
    //the result list
    FedeList<Player*>* result = new FedeList<Player*>();
    //for the player list
    for(int i = 0; i < this -> playerList -> getSize(); i++){
        //get the player at i
        Player* p = this -> playerList -> get(i);
        //if is not the given player and they are on the same room
        if(player != p && (p -> getCurrentRoom() == player -> getCurrentRoom()) && p->isAlive()){
            //add to the list
            result -> push_back(p);
        }
    }
    //return the rsult
    return result;
}
