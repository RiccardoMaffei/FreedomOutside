/* 
 * File:   Map.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include "Map.hpp"

//initialize the instance
Map* Map::instance = NULL;

Map::Map() {
    //construct an empty list
    this -> roomList = list<Room*>();
    //construct the main room. We can't use generateRoom becaure it generates the items.
    Room* main = new Room(0, 0, NULL, NULL, NULL, NULL, NULL);
    //save the main room pointer to the entry point
    this -> entryPoint = main;
    //add the main room to the room list
    this -> roomList.push_back(main);
}

Map::Map(const Map& orig) {
}

Map::~Map() {
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

