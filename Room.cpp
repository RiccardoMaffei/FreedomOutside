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

