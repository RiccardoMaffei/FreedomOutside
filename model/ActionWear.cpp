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
 * File:   ActionWear.cpp
 * Author: Federico Bertani
 * 
 * Created on 29 dicembre 2015, 18.36
 */

#include "../model/ActionWear.hpp"

ActionWear::ActionWear(Player* player, ItemArmor* armor) {
    //copy the player
    this->player = player;
    //copy the armor
    this->armor = armor;
}

ActionWear::~ActionWear() {
    //do nothing
}

void ActionWear::execute() {
    //wear the armor
    this->player->setArmor(armor);
    //remove the armor from the inventory.
    this->player->getInventory()->removeByElement(armor);
}

void ActionWear::getDescription(char dest[]) {
    //copy the fist part of the description
    strcpy(dest,"Wear ");
    //create a buffer to contain the armor description
    char armorDescription[256];
    //get the armor description
    armor->getDescription(armorDescription);
    //concat the armor description
    strcat(dest,armorDescription);
}

FedeList<char*>* ActionWear::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "You now wear a ";
    //concat the armor name
    char armorName[50];
    armor->getName(armorName);
    char* line = new char[strlen(firstPart)+strlen(armorName)+1];
    strcpy(line,firstPart);
    strcat(line,armorName);
    result->push_back(line);
    return result;    
}




