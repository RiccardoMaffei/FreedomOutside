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

