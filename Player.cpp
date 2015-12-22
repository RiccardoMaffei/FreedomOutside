/* 
 * File:   Player.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 16 dicembre 2015, 14.58
 */

#include <string.h>
#include "Player.hpp"

//initialize the static idCounter
int Player::idCounter = 1;

Player::Player(char username[], Room* currentRoom) {
    //copy the username
    strcpy(this -> username, username);
    //save the id and then increase the static id counter
    this -> id = (Player::idCounter)++;
    //save the current room
    this -> currentRoom = currentRoom;
    //set the health at 100
    this -> health = 100;
    //set the armor as NULL
    this -> armor = NULL;
    //instance an empty inventory
    this -> inventory = new list<Item*>();
    //set the strength as 1.00
    this -> strength = 1.00;
    //set the agility as 1.00
    this -> agility = 1.00;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::getUsername(char dest[]) {
    //copy the username in the given dest
    strcpy(this -> username, dest);
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
    //check if is not valid !(strength > 0)
    if (strength <= 0){
        //set as 1
        strength = 1;
    }
    //set the given strength
    this -> strength = strength;
}

double Player::getStrength() {
    //return the strength
    return this -> strength;
}

void Player::setAgility(double agility) {
    //check if is not valid !(agility > 0)
    if (agility <= 0){
        //set as 1
        agility = 1;
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

list<Item*>* Player::getInventory() {
    //return the inventory pointer
    return this -> inventory;
}

int Player::getHealth() {
    //return the health
    return this -> health;
}
