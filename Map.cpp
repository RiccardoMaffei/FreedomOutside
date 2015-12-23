/* 
 * File:   Map.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include "Map.hpp"
#include "FedeList.hpp"

//initialize the instance
Map* Map::instance = NULL;

Map::Map() {
    //construct an empty list
    this -> roomList = FedeList<Room*>();
    //construct the main room. We can't use generateRoom becaure it generates the items.
    Room* main = new Room(0, 0, NULL, NULL, NULL, NULL, NULL);
    //save the main room pointer to the entry point
    this -> entryPoint = main;
    //add the main room to the room list
    this -> roomList.push_back(main);
    //set the side left and side top to 0
    this -> sideLeft = this -> sideTop = 0;
}

Map::Map(const Map& orig) {
}

Map::~Map() {
    //destroy all the room of the map when the map is destroyed
    roomList.~FedeList();
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

Room* Map::generateRoom(int x,int y){
    //construct an empty item list
    FedeList<Item*>* itemList = new FedeList<Item*>();
    
    //TODO: add item random generation (spawning) logic
    //NOTE: in this implementation we don't check for existence for performace reasons.
    
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
}

Room* Map::findRoomByCoordinates(int x, int y) {

}

void Map::insertRoom(Room* r) {

}

