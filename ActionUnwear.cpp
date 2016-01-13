/* 
 * File:   ActionUnwear.cpp
 * Author: Federico Bertani
 * 
 * Created on 29 dicembre 2015, 18.46
 */

#include "ActionUnwear.hpp"

ActionUnwear::ActionUnwear(Player* player) {
    //copy the player
    this->player = player;
    //get a pointer to the armor from the player
    this->itemArmor = player->getArmor();
}

ActionUnwear::~ActionUnwear() {
    //do nothing
}

void ActionUnwear::execute() {
    //remove the armor from the player
    player->setArmor(NULL);
    //put the armor in the inventory of the player
    player->getInventory()->push_back(itemArmor);
}

void ActionUnwear::getDescription(char dest[]) {
    //copy the fist part of the description
    strcpy(dest,"Unwear ");
    //create a buffer to contain the armor description
    char armorDescription[256];
    //get the armor description
    itemArmor->getDescription(armorDescription);
    //concat the armor description
    strcat(dest,armorDescription);
}

FedeList<char*>* ActionUnwear::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "Now you are not wearing ";
    char armorName[50];
    itemArmor->getName(armorName);
    const char* secondPart = " anymore";
    char* line = new char[strlen(firstPart)+strlen(armorName)+strlen(secondPart)+1];
    strcpy(line,firstPart);
    strcat(line,armorName);
    strcat(line,secondPart);
    result->push_back(line);
    return result;      
}



