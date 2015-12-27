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
    //do nothing
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
