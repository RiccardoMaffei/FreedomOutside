/* 
 * File:   Map.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include "Map.hpp"

Map::Map() {
}

Map::Map(const Map& orig) {
}

Map::~Map() {
}

Map* Map::getInstance() {
    //if the instance pointer is null
    if (Map::instance == NULL){
        Map::instance = new Map();
    }
    //return the instance pointer
    return Map::instance;
}


