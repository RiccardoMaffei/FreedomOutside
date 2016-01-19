/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   ItemHealthKit.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.42
 */

#include "../model/ItemHealthKit.hpp"

ItemHealthKit::ItemHealthKit(const char name[], int healingValue): Item(name){
    //if the healing value is negative
    if(healingValue < 0){
        //set the healing value as 0
        healingValue = 0;
    }
    //save the healing value
    this -> healingValue = healingValue;
}

ItemHealthKit::~ItemHealthKit() {
}

int ItemHealthKit::getHealingValue() {
    //return the healing value
    return this -> healingValue;
}

void ItemHealthKit::getDescription(char dest[]) {
    //the string min value
    char value[50];
    //convert the value to string
    itoa(this -> healingValue, value);
    //copy the description with data
    strcpy(dest, "a health kit called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with ");
    strcat(dest, value);
    strcat(dest, " of healing value.");
}