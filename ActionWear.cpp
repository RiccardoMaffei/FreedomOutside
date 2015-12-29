/* 
 * File:   ActionWear.cpp
 * Author: fede
 * 
 * Created on 29 dicembre 2015, 18.36
 */

#include "ActionWear.hpp"

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



