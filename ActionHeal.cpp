/* 
 * File:   ActionHeal.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 27 dicembre 2015, 19.08
 */

#include "ActionHeal.hpp"

ActionHeal::ActionHeal(ItemHealthKit* kit, Player* playerToHeal) {
    //save the player
    this -> playerToHeal = playerToHeal;
    //save the kit
    this -> kit = kit;
}

ActionHeal::~ActionHeal() {
    //do nothing
}

void ActionHeal::execute() {
    //heal the player
    this -> playerToHeal -> heal(this -> kit ->getHealingValue());
    //remove the kit from the player inventory
    this -> playerToHeal -> getInventory() -> removeByElement(this -> kit);
    //delete the kit
    delete (this -> kit);
}

void ActionHeal::getDescription(char dest[]) {
    //copy the first part
    strcpy(dest, "Heal yourself with ");
    //a temporary buffer
    char buffer[100];
    //get the kit description
    this -> kit -> getDescription(buffer);
    //concatenate the description
    strcat(dest, buffer);
    //concat. the 2nd part of the message
    strcat(dest, " healing value:");
    //convert the healing value to string
    itoa(this -> kit -> getHealingValue(), buffer);
    //concatenate the healing value
    strcat(dest, buffer);
}

FedeList<char*>* ActionHeal::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    const char* firstPart = "You increased your health by ";
    //concat the healing point
    char healingValue[5];
    itoa(kit->getHealingValue(),healingValue);
    const char* secondPart = " points.";
    //create dinamically a buffer of the right size
    char* line = new char[strlen(firstPart)+strlen(healingValue)+strlen(secondPart)+1];
    strcpy(line,firstPart);
    strcat(line,healingValue);
    strcat(line,secondPart);
    result->push_back(line);
    return result;
}
