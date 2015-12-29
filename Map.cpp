/* 
 * File:   Map.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include "Map.hpp"
#include "FedeList.hpp"
#include "Randomizer.hpp"

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
    //destroy the whole room map recursively
    delete (this -> entryPoint);
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
        if(got >= toInsert){
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

