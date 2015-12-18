/* 
 * File:   Room.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.57
 */

#include "Room.hpp"

Room::Room(int x, int y, Room* north, Room* south, Room* east, Room* west) {
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
}

Room::~Room() {
}

Room::setNorth(Room* north){
    //set the north room pointer
    this -> north = north;
}

Room::setSouth(Room* south){
    //set the south room pointer
    this -> south = south;
}

Room::setEast(Room* east){
    //set the east room pointer
    this -> east = east;
}

Room::setWest(Room* west){
    //set the west room pointer
    this -> west = west;
}

Room::getNorth(){
    //return the north room pointer
    return this -> north;
}

Room::getSouth(){
    //return the south room pointer
    return this -> south;
}

Room::getEast(){
    //return the east room pointer
    return this -> east;
}

Room::getWest(){
    //return the west room pointer
    return this -> west;
}

Room::getX(){
    //return the x coordinate
    return this -> x;
}

Room::getY(){
    //return the y coordinate
    return this -> y;
}