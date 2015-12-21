/* 
 * File:   Room.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.57
 */

#include <stddef.h>
#include "Room.hpp"

Room::Room(int x, int y, Room* north, Room* south, Room* east, Room* west, list<Item*>* items) {
    //save the given x
    this -> x = x;
    //save the given y
    this -> y = y;
    //save the given north pointer
    this -> north = north;
    //save the given south pointer
    this -> south = south;
    //save the given east pointer
    this -> east = east;
    //save the given west pointer
    this -> west = west;
    //if the northern room is not NULL
    if (this -> north != NULL){
        //set this room as its southern (we can use the setter or directly access members)
        this -> north -> south = this;
    }
    //if the southern room is not NULL
    if (this -> south != NULL){
        //set this room as its northern (we can use the setter or directly access members)
        this -> south -> north = this;
    }
    //if the eastern room is not NULL
    if (this -> east != NULL){
        //set this room as its western (we can use the setter or directly access members)
        this -> east -> west = this;
    }
    //if the western room is not NULL
    if (this -> west != NULL){
        //set this room as its eastern (we can use the setter or directly access members)
        this -> west -> east = this;
    }
    //if the given item list pointer is not null
    if(items != NULL){
        //save the given pointer
        this -> items = items;
    }
    //otherwise
    else{
        //construct and save a new empty list
        this -> items = new list<Item*>();
    }
}

Room::~Room() {
}

void Room::setNorth(Room* north){
    //set the north room pointer
    this -> north = north;
}

void Room::setSouth(Room* south){
    //set the south room pointer
    this -> south = south;
}

void Room::setEast(Room* east){
    //set the east room pointer
    this -> east = east;
}

void Room::setWest(Room* west){
    //set the west room pointer
    this -> west = west;
}

Room* Room::getNorth(){
    //return the north room pointer
    return this -> north;
}

Room* Room::getSouth(){
    //return the south room pointer
    return this -> south;
}

Room* Room::getEast(){
    //return the east room pointer
    return this -> east;
}

Room* Room::getWest(){
    //return the west room pointer
    return this -> west;
}

int Room::getX(){
    //return the x coordinate
    return this -> x;
}

int Room::getY(){
    //return the y coordinate
    return this -> y;
}

list<Item*>* Room::getItemList(){
    //return a pointer to the list
    return this -> items;
}