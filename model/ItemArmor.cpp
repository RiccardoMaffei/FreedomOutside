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
 * File:   ItemArmor.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 18 dicembre 2015, 12.33
 */

#include "../model/ItemArmor.hpp"

ItemArmor::ItemArmor(const char name[], double protectionFactor): Item(name){
    //if the protection factor is less than 1
    if(protectionFactor < 1){
        //set the protection factor as 1
        protectionFactor = 1;
    }
    //save the protection factor
    this -> protectionFactor = protectionFactor;
}

ItemArmor::~ItemArmor() {
}

double ItemArmor::getProtectionFactor() {
    //return the protection factor
    return this -> protectionFactor;
}

void ItemArmor::getDescription(char dest[]) {
    //the string min value
    char value[50];
    //convert the value to string
    dtoaTwo(this -> protectionFactor, value);
    //copy the description with data
    strcpy(dest, "an armor called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with ");
    strcat(dest, value);
    strcat(dest, " protection factor.");
}