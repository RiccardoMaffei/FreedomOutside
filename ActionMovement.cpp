/* 
 * File:   ActionMovement.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 25 dicembre 2015, 16.22
 */

#include "ActionMovement.hpp"

ActionMovement::ActionMovement(Player* playerToMove, Room* targetRoom) {
    //if all the argument are not NULL
    if(playerToMove != NULL && targetRoom != NULL){
        //save the player
        this -> playerToMove = playerToMove;
        //save the target room
        this -> targetRoom = targetRoom;
    }
    //otherwise
    else{
        //throw an invalid argument exception
        throw(std::invalid_argument("player and target room must be not NULL"));
    }

}


ActionMovement::~ActionMovement() {
    //do nothing
}

void ActionMovement::execute() {
    //set the target room as the player's current room
    this -> playerToMove -> setCurrentRoom(this -> targetRoom);
}

void ActionMovement::getDescription(char dest[]) {
    //copy the description and then concat the direction
    strcpy(dest, "Go to ");
    //if the target is the north of the current room
    if(this -> playerToMove -> getCurrentRoom() -> getNorth() == this -> targetRoom){
        //concat "north"
        strcat(dest, "north.");
    }
    //else if the target is the south of the current room
    else if(this -> playerToMove -> getCurrentRoom() -> getSouth() == this -> targetRoom){
        //concat "south"
        strcat(dest, "south.");
    }
    //else if the target is the east of the current room
    else if(this -> playerToMove -> getCurrentRoom() -> getEast() == this -> targetRoom){
        //concat "east"
        strcat(dest, "east.");
    }
    //else if the target is the west of the current room
    else if(this -> playerToMove -> getCurrentRoom() -> getWest() == this -> targetRoom){
        //concat "west"
        strcat(dest, "west.");
    }
    //else (room far away)
    else{
        //concat "somewhere"
        strcat(dest, "somewhere.");
    }
    //this is the "relative" implemetation.
    //the "absolute" implementation returns the coordinates.
}

FedeList<char*>* ActionMovement::getOutcome() {
    
}




