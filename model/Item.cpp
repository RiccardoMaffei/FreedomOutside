/* 
 * File:   Item.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 17 dicembre 2015, 14.14
 */

#include <string.h>
#include "../model/Item.hpp"

Item::Item(const char name[]) {
    //copy the given name
    strcpy(this -> name, name);
}

Item::~Item() {
}

void Item::getName(char dest[]) {
    //copy the name in the destination array
    strcpy (dest, name);
}
