/* 
 * File:   ActionPickup.cpp
 * Author: Federico Bertani
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
    char itemDescription[256];
    itemToPickup->getDescription(itemDescription);
    strcat(dest,itemDescription);
}

FedeList<char*>* ActionPickup::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "You picked up ";
    //get and concat the name of the item you picked up
    char itemName[50];
    itemToPickup->getName(itemName);
    const char* secondPart = " from the floor.";
    //create dinamically a buffer of the right size
    char* line = new char[strlen(firstPart)+strlen(itemName)+strlen(secondPart)+1];
    //concat all the parts
    strcpy(line,firstPart);
    strcat(line,itemName);
    strcat(line,secondPart);
    result->push_back(line);
    return result;
}



