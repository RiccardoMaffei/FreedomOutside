/* 
 * File:   ActionCombat.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 27 dicembre 2015, 14.58
 */

#include <math.h>

#include "ActionCombat.hpp"

ActionCombat::ActionCombat(Player* attacker, ItemWeapon* weapon, FedeList<Player*>* listOfPlayers) {
    //save the attacker
    this -> attacker = attacker;
    //save the weapon
    this -> weapon = weapon;
    //save the list of attacked players
    this -> attackedPlayers = listOfPlayers;
    //create a list for damages
    this -> inflictedDamages = new FedeList<int>();
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
    //increase the strenght
    //TODO check that the strenght is below the max Strenght
    double strenght = attacker -> getStrength();
    strenght += 0.2;
    attacker -> setStrength(strenght);
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
    for (int i = 0; i < (this -> attackedPlayers -> getSize()); i++) {
        const char* firstPart = "You inflicted ";
        const char* secondPart = " damage points to ";
        char inflictedDamage[5];
        itoa(this -> inflictedDamages -> get(i), inflictedDamage);
        char username[255];
        //TODO say yourself if the attacked player is yourself
        this -> attackedPlayers -> get(i) -> getUsername(username);
        //TODO better lenght calc
        char* line = new char[strlen(firstPart) + strlen(inflictedDamage) + strlen(secondPart) + strlen(username)];
        strcpy(line, firstPart);
        strcat(line, inflictedDamage);
        strcat(line, secondPart);
        strcat(line, username);
        result->push_back(line);
    }
    //TODO say if the strenght has increased of a level.
    return result;
}

