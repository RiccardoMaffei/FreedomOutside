/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   ItemSimpleWeapon.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.37
 */

#include "../model/ItemSimpleWeapon.hpp"
using namespace std;

ItemSimpleWeapon::ItemSimpleWeapon(const char name[], int damageValue): ItemWeapon(name) {
    //if the damage value is not value (damageValue<=0)
    if (damageValue <= 0){
        //set as 1
        damageValue = 1;
    }
    //save the damage value
    this -> damageValue = damageValue;
}

ItemSimpleWeapon::~ItemSimpleWeapon() {
}

int ItemSimpleWeapon::getDamageValue() {
    //return the damage value
    return this -> damageValue;
}

void ItemSimpleWeapon::getDescription(char dest[]) {
    //the string value
    char value[50];
    //convert the value to string
    itoa(this -> damageValue, value);
    //copy the description with data
    strcpy(dest, "a weapon called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with ");
    strcat(dest, value);
    strcat(dest, " base damage value.");
}
