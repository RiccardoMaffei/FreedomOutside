/* 
 * File:   ActionRelativeMovement.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 25 dicembre 2015, 20.28
 */

#include "ActionRelativeMovement.hpp"
#include "ActionMovement.hpp"

ActionRelativeMovement::ActionRelativeMovement(Player* playerToMove, movementDirection_t direction, Map* map) {
    //save the player
    this -> playerToMove = playerToMove;
    //save the direction
    this -> direction = direction;
    //save the map
    this -> map = map;
}


ActionRelativeMovement::~ActionRelativeMovement() {
    //do nothing
}

void ActionRelativeMovement::execute() {
    //the target room
    Room* targetRoom = NULL;
    //destination coordinates
    int destX = 0, destY = 0;
    //swicth directions
    switch(this -> direction){
        //case direction is nord
        case TO_NORTH:
            //set the target room as the north
            targetRoom = this -> playerToMove -> getCurrentRoom() -> getNorth();
            //set the destination x
            destX = (this -> playerToMove -> getCurrentRoom() -> getX());
            //set the destination y
            destY = (this -> playerToMove -> getCurrentRoom() -> getY()) - 1;
            break;
        //case direction is south
        case TO_SOUTH:
            //set the target room as the south
            targetRoom = this -> playerToMove -> getCurrentRoom() -> getSouth();
            //set the destination x
            destX = (this -> playerToMove -> getCurrentRoom() -> getX());
            //set the destination y
            destY = (this -> playerToMove -> getCurrentRoom() -> getY()) + 1;
            break;
        //case direction is east
        case TO_EAST:
            //set the target room as the east
            targetRoom = this -> playerToMove -> getCurrentRoom() -> getEast();
            //set the destination x
            destX = (this -> playerToMove -> getCurrentRoom() -> getX()) + 1;
            //set the destination y
            destY = (this -> playerToMove -> getCurrentRoom() -> getY());
            break;
        //case direction is west
        case TO_WEST:
            //set the target room as the west
            targetRoom = this -> playerToMove -> getCurrentRoom() -> getWest();
            //set the destination x
            destX = (this -> playerToMove -> getCurrentRoom() -> getX()) - 1;
            //set the destination y
            destY = (this -> playerToMove -> getCurrentRoom() -> getY());
            break;
    }
    //if the target room doesn't exist
    if (targetRoom == NULL){
        //generate the room
        targetRoom = this -> map -> generateRoom(destX, destY);
    }
    //generate the action movement
    ActionMovement* actionMovement = new ActionMovement(this -> playerToMove, targetRoom);
    //execute the action
    actionMovement -> execute();
    //delete the action
    delete actionMovement;
}

void ActionRelativeMovement::getDescription(char dest[]) {
    //copy the description and then concat the direction
    strcpy(dest, "Go to ");
    concatDirection(dest);
}

FedeList<char*>* ActionRelativeMovement::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>();
    const char* firstPart = "You moved to ";
    //create dinamically a buffer of the right size, i used 7 for the direction
    //cause i don't want to create a buffer only for the direction
    char* line = new char[strlen(firstPart)+7];
    strcpy(line,firstPart);
    concatDirection(line);
    result -> push_back(line);
}

void ActionRelativeMovement::concatDirection(char* dest) {
    //switch directions
    switch(this -> direction){
        //case direction is nord
        case TO_NORTH:
            //concat "north"
            strcat(dest, "north.");
            break;
        //case direction is south
        case TO_SOUTH:
            //concat "south"
            strcat(dest, "south.");
            break;
        //case direction is east
        case TO_EAST:
            //concat "east"
            strcat(dest, "east.");
            break;
        //case direction is west
        case TO_WEST:
            //concat "west"
            strcat(dest, "west.");
            break;
    }
}

