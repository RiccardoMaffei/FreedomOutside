/* 
 * File:   Item.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 17 dicembre 2015, 14.14
 */

#include <string.h>
#include "Item.hpp"

Item::Item(char name[]) {
    //copy the given name
    strcpy(this -> name, name);
    
}

Item::~Item() {
}

