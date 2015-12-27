/* 
 * File:   ActionPickup.cpp
 * Author: fede
 * 
 * Created on 27 dicembre 2015, 14.59
 */

#include "ActionPickup.hpp"

ActionPickup::ActionPickup(Player* player, Item* itemToPickup) {
    this->player = player;
    this->itemToPickup = itemToPickup;
}

ActionPickup::~ActionPickup() {
    //do nothing beacuse pointers are automatically deleted.
}

void ActionPickup::execute() {
    //remove the pointer to the item from the list of items of the room.
    player->getCurrentRoom()->getItemList()->removeByElement(itemToPickup);
    //add the item pointer to the inventory of the player.
    player->getInventory()->push_back(itemToPickup);
}

void ActionPickup::getDescription(char dest[]) {
    //copy the description of the action and then concat the descption of the item
    strcpy(dest,"Pickup ");
    char* itemDescription = new char[256];
    itemToPickup->getDescription(itemDescription);
    strcpy(dest,itemDescription);
    delete itemDescription;
}



