/* 
 * File:   Map.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include "Map.hpp"
#include "FedeList.hpp"
#include "Randomizer.hpp"
#include <iostream>

//initialize the instance
Map* Map::instance = NULL;

Map::Map() {
    //construct an empty list
    this -> roomList = new FedeList<Room*>();
    //construct the main room. We can't use generateRoom becaure it generates the items.
    Room* main = new Room(0, 0, NULL, NULL, NULL, NULL, NULL);
    //save the main room pointer to the entry point
    this -> entryPoint = main;
    //add the main room to the room list
    this -> roomList -> push_back(main);
    //set the side left and side top to 0
    this -> sideLeft = 0;
}

Map::Map(const Map& orig) {
}

Map::~Map() {
//    //destroy the whole room map recursively
//    delete (this -> entryPoint);
    //for the list of rooms
    for(int i = 0; i < this -> roomList -> getSize(); i++){
        //delete the room at i
        delete (this -> roomList -> get(i));
    }
    //delete the room list
    delete (this -> roomList);
    //set the static instance pointer as NULL
    Map::instance = NULL;
}

Map* Map::getInstance() {
    //if the instance pointer is null
    if (Map::instance == NULL){
        //construct a new map and save it to the static instance
        Map::instance = new Map();
    }
    //return the instance pointer
    return Map::instance;
}

Room* Map::getEntryPoint() {
    //return the entry point
    return this -> entryPoint;
}

int Map::getSideLeft() {
    //return the left side
    return sideLeft;
}

Room* Map::generateRoom(int x,int y){
    //construct an empty item list
    FedeList<Item*>* itemList = new FedeList<Item*>();
    //NOTE: in this implementation we don't check for existence for performace reasons.
    Randomizer::generateRoomItems(itemList);
    //get the northern room (may be NULL)
    Room* n = findRoomByCoordinates(x, y-1);
    //get the southern room (may be NULL)
    Room* s = findRoomByCoordinates(x, y+1);
    //get the eastern room (may be NULL)
    Room* e = findRoomByCoordinates(x+1, y);
    //get the weastern room (may be NULL)
    Room* w = findRoomByCoordinates(x-1, y);
    //construct a room
    Room* roomToInsert = new Room(x, y, n, s, e, w, itemList);
    //insert it in the map taking care of ordering and consistency
    this -> insertRoom(roomToInsert);
    //return the inserted room
    return roomToInsert;
}

Room* Map::findRoomByCoordinates(int searchedX, int searchedY) {
    //the found room (NULL by default)
    Room* foundRoom = NULL;
    //the position starting from 0
    int pos = 0;
    //the should stop searching flag (if passed the searched coordinates)
    bool shouldStop = false;
    //while didn't go beyond the target and the position is less than the size
    while (pos < (this -> roomList -> getSize()) && !shouldStop){
        //get the room at position pos
        Room* got = this -> roomList -> get(pos);
        //if the coordinated are the same as the searched
        if((got -> getX() == searchedX) && (got -> getY() == searchedY)){
            //save the got room as found the room
            foundRoom = got;
        }
        //if the got room is at the searched coordinates or ahed them
        if (((got -> getY() == searchedY) && (got -> getX() >= searchedX)) || (got -> getY() > searchedY)){
            //set should stot as true
            shouldStop = true;
        }
        //increase the counter
        pos++;
    }
    //return the found room (may be NULL if not found)
    return foundRoom;
}

void Map::insertRoom(Room* toInsert) {
    //the position starting from 0
    int pos = 0;
    //the found flag
    bool found = false;
    //while not found and the position is less than the size
    while (pos < (this -> roomList -> getSize()) && !found){
        //get the room at position pos
        Room* got = this -> roomList -> get(pos);
        //if the got room is higher or equal to the room to insert
        //DEBUG NOTE: should never be equal but for debug purpose we put equal rooms
        //one next to the other so we can easily find out that there are duplicates (error)
        if(*got >= *toInsert){
            //set the found as true
            found = true;
        }
        //increase the posintion
        pos++;
    }
    //if the position has been found
    if(found){
        //decrease the position
        pos--;
    }
    //else. (reached the end of the list or never entered (size = 0))
    else{
        //overwrite position with the size of the list. (Append. That is pos. 0 if empty or last position+1)
        pos = this -> roomList -> getSize();
    }
    //insert the room in the position
    this -> roomList -> insert(toInsert, pos);
    //if the inserted X coordinate is lower than the lowest in map so far
    if(toInsert -> getX() < this -> sideLeft){
        //update the lowest (side)
        this -> sideLeft = toInsert -> getX();
    }
}

FedeList<Room*>* Map::getVisibleRooms(Room* center, int radius) {
    //if the radius is less than zero
    if(radius < 0){
        //reset as zero
        radius = 0;
    }
    //the result list
    FedeList<Room*>* result = new FedeList<Room*>();
    //get the center x
    int centerX = center -> getX();
    //get the center y
    int centerY = center -> getY();
    //the position in the room list
    int pos = 0;
    //the current rows from the top of the square.
    int rowsFromTop = 0;
    //not reached the lower side of visibility square and not reached the end of the list of rooms
    while( rowsFromTop < (2*radius)+1 && pos < (this -> roomList -> getSize())){
        //this is a temporary fake room that represent the left limit of the line
        Room minlineTemp = Room(centerX - radius, centerY - radius + rowsFromTop,NULL,NULL,NULL,NULL,new FedeList<Item*>());
        //this is a temporary fake room that represent the right limit of the line
        Room maxlineTemp = Room(centerX + radius, centerY - radius + rowsFromTop,NULL,NULL,NULL,NULL,new FedeList<Item*>());
        //have I reached or passed the right side of the row?
        bool reached = false;
        //while i haven't reached the end of the row and I've not reached the end of the list of rooms
        while (pos < (this -> roomList -> getSize()) && !reached){
            //get the room at position pos
            Room* got = this -> roomList -> get(pos);
            //if the room is between (inclusive) max and min line
            if(*got >= minlineTemp && *got <= maxlineTemp){
                //add to the result list
                result -> push_back(got);
            }
            //if the got room is higher or equal to the max line
            if(*got >= maxlineTemp){
                //set the should stop as true
                reached = true;
            }
            //else
            else{
                //increase the position
                pos++;
            }
        }
        //increase the line
        rowsFromTop++;
    }
    //return the result
    return result;
}
