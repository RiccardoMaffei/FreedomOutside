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
 * File:   ActionCombat.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 27 dicembre 2015, 14.58
 */

#include <math.h>

#include "../model/ActionCombat.hpp"
#include "../model/ItemDestructiveWeapon.hpp"

ActionCombat::ActionCombat(Player* attacker, ItemWeapon* weapon, FedeList<Player*>* listOfPlayers) {
    //save the attacker
    this -> attacker = attacker;
    //save the weapon
    this -> weapon = weapon;
    //save the list of attacked players
    this -> attackedPlayers = listOfPlayers;
    //create a list for damages
    this -> inflictedDamages = new FedeList<int>();
    //set to default that the strenght has not increased (for now)
    strengthIncreased = false;
}

ActionCombat::~ActionCombat() {
    //delete the list of attacked player
    delete (this -> attackedPlayers);
    //delete the list of damages inflicted
    delete (this -> inflictedDamages);
}

void ActionCombat::execute() {
    //for all attacked players
    for (int i = 0; i < (this -> attackedPlayers -> getSize()); i++) {
        //compute damage FE(it may vary. E.g.: in destruptive weapon)
        int damage = (this -> attacker -> getStrength()) * (this -> weapon -> getDamageValue());

        //if the attacked is the attacker
        if (this -> attacker == this -> attackedPlayers -> get(i)) {
            //divide the damage by the agility
            damage = floor(damage / (this -> attacker -> getAgility()));
        }
        //damage the player
        int inflictedDamage = this -> attackedPlayers -> get(i) -> damage(damage);
        //save the damage inflicted
        this -> inflictedDamages -> push_back(inflictedDamage);
    }
    //get the player strength
    double strength = this -> attacker -> getStrength();
    //check if the player strength is below max level
    if (strength < Player::MAX_STRENGTH) {
        //increase it
        strength += 0.2;
        //set the new strength to the player
        attacker -> setStrength(strength); 
        //set that the strenght has increased
        strengthIncreased = true;
    }
    //if the weapon was a destruptive weapon
    if (dynamic_cast<ItemDestructiveWeapon*>(this -> weapon)){
        //remove the weapon from the attacker inventory
        this -> attacker -> getInventory() -> removeByElement(this -> weapon);
        //delete the weapon
        delete (this -> weapon);
    }
}

void ActionCombat::getDescription(char dest[]) {
    //copy the first part
    strcpy(dest, "Combat with ");
    //a temporary buffer
    char buffer[100];
    //get the weapon description
    this -> weapon -> getDescription(buffer);
    //concatenate the description
    strcat(dest, buffer);
    //concat. the 2nd part of the message
    strcat(dest, " angainst:");
    for (int i = 0; i < this -> attackedPlayers -> getSize(); i++) {
        //get the player name description
        this -> attackedPlayers -> get(i) -> getUsername(buffer);
        //concatenate the name
        strcat(dest, buffer);
        //if not last loop
        if (i < (this -> attackedPlayers -> getSize() - 1)) {
            //concatenate a comma
            strcat(dest, ", ");
        }
    }

}

FedeList<char*>* ActionCombat::getOutcome() {
    FedeList<char*>* result = new FedeList<char*>;
    //for every attacked player i create a line of output describing the damage done.
    for (int i = 0; i < (this -> attackedPlayers -> getSize()); i++) {
        const char* firstPart = "You inflicted ";
        const char* secondPart = " damage points to ";
        //declare a buffer for contain the string rapresenting the inflictedDamage
        char inflictedDamage[5];
        itoa(this -> inflictedDamages -> get(i), inflictedDamage);
        char username[50];
        //TODO say yourself if the attacked player is yourself
        this -> attackedPlayers -> get(i) -> getUsername(username);
        //dynamically create a buffer of the right size
        char* line = new char[strlen(firstPart) + strlen(inflictedDamage) + strlen(secondPart) + strlen(username)+1];
        strcpy(line, firstPart);
        strcat(line, inflictedDamage);
        strcat(line, secondPart);
        strcat(line, username);
        result->push_back(line);
    }
    //get te attacker strenght
    double strength = this -> attacker -> getStrength();
    //if the strenght is integer number and the strenght has incresed(not reached max)
    if (((int)(strength*10) % 10) == 0 && this -> strengthIncreased) {
        const char* third = "Fighting, you have increased your strenght to ";
        char strengthString[5];
        //converting the double to string.
        dtoaTwo(strength,strengthString);
        //dynamically create a buffer of the right size
        char* line = new char[strlen(third)+strlen(strengthString)];
        strcpy(line,third);
        strcat(line,strengthString);
        result->push_back(line);
    }
    return result;
}

