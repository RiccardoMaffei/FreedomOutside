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


