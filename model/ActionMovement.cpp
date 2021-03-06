/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   ActionMovement.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 25 dicembre 2015, 16.22
 */

#include "../model/ActionMovement.hpp"

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
    //get the x coordinate
    char xCoordinate[10];
    //trasfor it to string
    itoa(targetRoom->getX(),xCoordinate);
    //get the y coordinate
    char yCoordinate[10];
    //trasform it to string
    itoa(targetRoom->getY(),yCoordinate);
    const char* secondPart = " ";
    //create dinamically a buffer of the right size
    int lineLenght = strlen(firstPart)+strlen(xCoordinate)+strlen(secondPart)+strlen(yCoordinate)+1;
    char* line = new char[lineLenght];
    //concat all the part for forming the final string
    strcpy(line,firstPart);
    strcat(line,xCoordinate);
    strcat(line,secondPart);
    strcat(line,yCoordinate);
    result->push_back(line);
    //get the player agility
    double agility = this -> playerToMove -> getAgility();
    //if the agility is a integer number and if the agility has incresed(not reached tha max value)
    if (((int)(agility*10) % 10) == 0 && this -> agilityIncreased) {
        const char* third = "Walking, you have increased your agility to ";
        char agilityString[5];
        //converting the double to string
        dtoaTwo(agility,agilityString);
        line = new char[strlen(third)+strlen(agilityString)];
        strcpy(line,third);
        strcat(line,agilityString);
        //adding this as new line
        result->push_back(line);
    }
    return result;
}




