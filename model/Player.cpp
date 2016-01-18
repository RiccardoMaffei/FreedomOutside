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
 * File:   Player.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include <string.h>
#include <math.h>
#include "../model/Player.hpp"

//initialize the static idCounter
int Player::idCounter = 1;

Player::Player(char username[], Room* currentRoom) {
    //copy the username
    strcpy(this -> username, username);
    //save the id and then increase the static id counter
    this -> id = (Player::idCounter)++;
    //save the current room
    this -> currentRoom = currentRoom;
    //set the health at the max
    this -> health = MAX_HEALTH;
    //set the armor as NULL
    this -> armor = NULL;
    //instance an empty inventory
    this -> inventory = new FedeList<Item*>();
    //set the strength as the minimum
    this -> strength = MIN_STRENGTH;
    //set the agility as the minimum
    this -> agility = MIN_AGILITY;
}

Player::~Player() {
    //when a player is destructed also his items in his inventory are being destructed
    //for the list size of the inventory
    for (int i = 0; i < (this -> inventory -> getSize()); i++) {
        //delete the item
        delete (this -> inventory -> get(i));
    }
    //delete the list
    delete (this -> inventory);
    //delete the armor
    delete (this -> armor);
}

void Player::getUsername(char dest[]) {
    //copy the username in the given dest
    strcpy(dest, this -> username);
}

void Player::setCurrentRoom(Room* currentRoom) {
    //save the given room pointer as the current room
    this -> currentRoom = currentRoom;
}

Room* Player::getCurrentRoom() {
    //return the pointer to the current room
    return this -> currentRoom;
}

int Player::getId() {
    //return the id
    return this -> id;
}

void Player::setStrength(double strength) {
    //check if is not valid (strength < minimum)
    if (strength < MIN_STRENGTH){
        //set as the minimum
        strength = MIN_STRENGTH;
    }
    //check if is not valid (strength > maximum)
    else if (strength > MAX_STRENGTH){
        //set as the maximum
        strength = MAX_STRENGTH;
    }
    //set the given strength
    this -> strength = strength;
}

double Player::getStrength() {
    //return the strength
    return this -> strength;
}

void Player::setAgility(double agility) {
    //check if is not valid (agility < minimum)
    if (agility < MIN_AGILITY){
        //set as the minumum
        agility = MIN_AGILITY;
    }
    //check if is not valid (agility > maximum)
    else if (agility > MAX_AGILITY){
        //set as the maximum
        agility = MAX_AGILITY;
    }
    //set the given agility
    this -> agility = agility;
}

double Player::getAgility() {
    //return the agility
    return this -> agility;
}

void Player::setArmor(ItemArmor* armor) {
    //set the given armor
    this -> armor = armor;
}

ItemArmor* Player::getArmor() {
    //return the armor
    return this -> armor;
}

FedeList<Item*>* Player::getInventory() {
    //return the inventory pointer
    return this -> inventory;
}

int Player::getHealth() {
    //return the health
    return this -> health;
}

int Player::heal(int toHeal) {
    //check if "overflows"
    if ((this -> health + toHeal) > 100){
        //set the points to heal as the difference
        toHeal = 100 - this -> health;
    }
    //else if is zero or invalid
    else if(toHeal <= 0){
        //do not throw an exception.
        //set to heal as zero
        toHeal = 0;
    }
    //else (0<toHeal<=max possible earning)
        //do nothing
    //heal the player
    this -> health += toHeal;
    //return the points to heal
    return toHeal;
}

int Player::damage(int damage) {
    //the damage to inflict
    int toInflict;
    //the armor protection factor. default 1 (1 = no further protection)
    double armorProtFact = 1;
    //if there is an armor
    if(this -> armor != NULL){
        //get the protection factor
        armorProtFact = (this -> armor -> getProtectionFactor());
    }
    //compute damage to inflict (use double and then ceil)
    toInflict = ceil(((double) damage) / (((double) this -> agility) * armorProtFact));
    //if the damage to inflict are greater or equal to the health (will die)
    if(toInflict >= this -> health){
        //set damage to inflict as the health
        toInflict = this -> health;
    }
    //subtract the damage to inflict from the health
    this -> health -= toInflict;
    //return the damage to inflict
    return toInflict;
}

bool Player::isAlive() {
    //return true if the health is greater than zero
    return (health > 0) ? true : false;
}


