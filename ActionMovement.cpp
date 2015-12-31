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
    //set to dafault that the agility has not increased (for now)
    agilityIncreased = false;
}


ActionMovement::~ActionMovement() {
    //do nothing
}

void ActionMovement::execute() {
    //set the target room as the player's current room
    this -> playerToMove -> setCurrentRoom(this -> targetRoom);
    //get the player agility
    double agility = this -> playerToMove -> getAgility();
    //if the agility is below max level
    if (agility < Player::MAX_AGILITY) {
        //increase it
        agility += 0.1;
        //and set the new agility to the player
        this -> playerToMove -> setAgility(agility);
        agilityIncreased = true;
    }
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
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "You moved to room ";
    char xCoordinate[5];
    itoa(targetRoom->getX(),xCoordinate);
    char yCoordinate[5];
    itoa(targetRoom->getY(),yCoordinate);
    const char* secondPart = " ";
    int lineLenght = strlen(firstPart)+strlen(xCoordinate)+strlen(secondPart)+strlen(yCoordinate);
    char* line = new char[lineLenght];
    strcpy(line,firstPart);
    strcat(line,xCoordinate);
    strcat(line,secondPart);
    strcat(line,yCoordinate);
    result->push_back(line);
    double agility = this -> playerToMove -> getAgility();
    if (((int)(agility*10) % 10) == 0 && this -> agilityIncreased) {
        const char* third = "Walking, you have increased your agility to ";
        char agilityString[5];
        //converting the double agility in a string (with int casting, but non problem 'cause i call this when agility is int)
        itoa(agility,agilityString);
        line = new char[strlen(third)+strlen(agilityString)];
        strcpy(line,third);
        strcat(line,agilityString);
        result->push_back(line);
    }
    return result;
}




