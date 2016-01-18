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
 * File:   ActionDrop.cpp
 * Author: Federico Bertani
 * 
 * Created on 27 dicembre 2015, 14.36
 */

#include "../model/ActionDrop.hpp"

ActionDrop::ActionDrop(Player* player, Item* itemToDrop) {
    this->player = player;
    this->itemToDrop = itemToDrop;
}

ActionDrop::~ActionDrop() {
    //do nothing beacuse pointers are automatically deleted.
}

void ActionDrop::execute() {
    //remove the pointer to the item from the inventory.
    player->getInventory()->removeByElement(itemToDrop);
    //add the item pointer to the list of item of the room.
    player->getCurrentRoom()->getItemList()->push_back(itemToDrop);
}

void ActionDrop::getDescription(char dest[]) {
    //copy the description of the action and then concat the descption of the item
    strcpy(dest, "Drop ");
    char itemDescription[256];
    itemToDrop->getDescription(itemDescription);
    strcat(dest, itemDescription);
}

FedeList<char*>* ActionDrop::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "You dropped ";
    //concat the item name
    char itemName[50];
    itemToDrop->getName(itemName);
    const char* secondPart = " on the floor.";
    //create dinamically a buffer of the right size
    char* line = new char[strlen(firstPart)+strlen(itemName)+strlen(secondPart)+1];
    strcpy(line,firstPart);
    strcat(line,itemName);
    strcat(line,secondPart);
    result->push_back(line);
    return result;
}



