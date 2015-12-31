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
        char username[50];
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
    double strength = this -> attacker -> getStrength();
    if (((int)(strength*10) % 10) == 0 && this -> strengthIncreased) {
        const char* third = "Fighting, you have increased your strenght to ";
        char strengthString[5];
        //converting the double strength in a string (with int casting, but non problem 'cause i call this when strength is int)
        itoa(strength,strengthString);
        char* line = new char[strlen(third)+strlen(strengthString)];
        strcpy(line,third);
        strcat(line,strengthString);
        result->push_back(line);
    }
    return result;
}

