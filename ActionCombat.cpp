/* 
 * File:   ActionCombat.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 27 dicembre 2015, 14.58
 */

#include <math.h>

#include "ActionCombat.hpp"

ActionCombat::ActionCombat(Player* attacker, ItemWeapon* weapon, FedeList<Player*>* listOfPlayers){
    //save the attacker
    this -> attacker = attacker;
    //save the weapon
    this -> weapon = weapon;
    //save the list of attacked players
    this -> attackedPlayers = attackedPlayers;
}

ActionCombat::~ActionCombat() {
    //delete the list
    delete (this -> attackedPlayers);
}

void ActionCombat::execute(){
    //for all attacked players
    for (int i = 0; i < (this -> attackedPlayers -> getSize()); i++) {
        //compute damage (it may vary. E.g.: in destruptive weapon)
        int damage = (this -> attacker -> getStrength()) * (this -> weapon -> getDamageValue());
        //if the attacked is the attacker
        if (this -> attacker == this -> attackedPlayers -> get(i)){
            //divide the damage by the agility
            damage = floor(damage / (this -> attacker -> getAgility()));
        }
        //damage the item
        this -> attackedPlayers -> get(i) -> damage(damage);
    }
}

void ActionCombat::getDescription(char dest[]) {
    //copy the first part
    strcpy(dest, "Combat with ");
    //a temporary buffer
    char buffer[50];
    //get the weapon description
    this -> weapon -> getDescription(buffer);
    //concatenate the description
    strcat(dest, buffer);
    //concat. the 2nd part of the message
    strcat(dest, " angainst:");
    for(int i = 0; i < this -> attackedPlayers -> getSize(); i++){
        //get the player name description
        this -> attackedPlayers -> get(i) -> getUsername(buffer);
        //concatenate the name
        strcat(dest, buffer);
        //if not last loop
        if(i < (this -> attackedPlayers -> getSize() -1)){
            //concatenate a comma
            strcat(dest, ", ");
        }
    }
    
}
