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
 * File:   Randomizer.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 29 dicembre 2015, 2.23
 */

#include "../model/Randomizer.hpp"
#include "../model/ItemSimpleWeapon.hpp"
#include "../model/ItemDestructiveWeapon.hpp"
#include "../model/ItemArmor.hpp"
#include "../model/ItemHealthKit.hpp"
#include <time.h>
#include <stdlib.h>

//initialize the instance
Randomizer* Randomizer::instance = NULL;

Randomizer* Randomizer::getInstance() {
    //if the instance pointer is null
    if (Randomizer::instance == NULL){
        //construct a new randomizer and save it to the static instance
        Randomizer::instance = new Randomizer();
    }
    //return the instance pointer
    return Randomizer::instance;
}

Randomizer::Randomizer() {
    //initialize the random seed
    srand(time(NULL));
}

Randomizer::~Randomizer() {
    //set the static instance pointer as NULL
    Randomizer::instance = NULL;
}

void Randomizer::generateRoomItems(FedeList<Item*>* items) {
    //----------------SIMPLE WEAPONS ------------------
    generateSimpleWeapon("Rotten wooden plank", 1, 21, items);
    generateSimpleWeapon("Wooden plank",        2, 20, items);
    generateSimpleWeapon("Sharp wooden plank",  3, 19, items);
    generateSimpleWeapon("Rotten stick",        4, 18, items);
    generateSimpleWeapon("Stick",               5, 17, items);
    generateSimpleWeapon("Rusty iron pipe",     6, 16, items);
    generateSimpleWeapon("Iron pipe",           7, 15, items);
    generateSimpleWeapon("Hammer",              8, 14, items);
    generateSimpleWeapon("Knife",               9, 13, items);
    generateSimpleWeapon("Sword",               10, 12, items);
    generateSimpleWeapon("Spear",               15, 11, items);
    generateSimpleWeapon("Axe",                 20, 10, items);
    generateSimpleWeapon("Iron mace",           30, 9, items);
    generateSimpleWeapon("Blowgun",             29, 8, items);
    generateSimpleWeapon("Bow",                 25, 7, items);
    generateSimpleWeapon("Slingshot",           30, 6, items);
    generateSimpleWeapon("Hunting Bow",         35, 5, items);
    generateSimpleWeapon("Handgun",             45, 4, items);
    generateSimpleWeapon("Rifle",               60, 3, items);
    generateSimpleWeapon("Shotgun",             70, 2, items);
    generateSimpleWeapon("Ak-47",               90, 1, items);
    //--------------END SIMPLE WEAPONS----------------
    //--------------DESTRUCTIVE WEAPONS----------------
    generateDestructiveWeapon("Molotov",    30, 80, 6, items);
    generateDestructiveWeapon("Granade",    35, 85, 5, items);
    generateDestructiveWeapon("TNT",        50, 100, 2, items);
    //------------END DESTRUCTIVE WEAPONS--------------
    //--------------------ARMORS----------------------
    generateArmorItem("Rags armor",     1.1, 20, items);
    generateArmorItem("Leather armor",  1.2, 18, items);
    generateArmorItem("Hide armor",     1.3, 15, items);
    generateArmorItem("Copper armor",   1.4, 9, items);
    generateArmorItem("Bronze armor",   1.5, 7, items);
    generateArmorItem("Iron armor",     1.6, 5, items);
    generateArmorItem("Steel armor",    1.7, 3, items);
    generateArmorItem("Gold armor",     1.8, 2, items);
    generateArmorItem("Diamond armor",  1.9, 1, items);
    //------------------END ARMORS--------------------
    //------------------HEALTH KITS--------------------
    generateHealthKit("Tiny healing potion",    5, 25, items);
    generateHealthKit("Small healing potion",   10, 15, items);
    generateHealthKit("Medium healing potion",  30, 5, items);
    generateHealthKit("Big healing potion",     50, 2, items);
    generateHealthKit("Huge healing potion",    100, 1, items);
    //----------------END HEALTH KITS------------------
}

void Randomizer::generateArmorItem(const char name[], double protectionFactor, int probability, FedeList<Item*>* items) {
    //if should be generated (probability hit)
    if (shouldGenerate(probability)) {
        //generate and push
        items -> push_back(new ItemArmor(name,protectionFactor));
    }
}


void Randomizer::generateDestructiveWeapon(const char name[], int damageMin, int damegeMax, int probability, FedeList<Item*>* items) {
    //if should be generated (probability hit)
    if (shouldGenerate(probability)) {
        //generate and push
        items -> push_back(new ItemDestructiveWeapon(name, damageMin, damegeMax));
    }
}

void Randomizer::generateHealthKit(const char name[], int healingValue, int probability, FedeList<Item*>* items) {
    //if should be generated (probability hit)
    if (shouldGenerate(probability)) {
        //generate and push
        items -> push_back(new ItemHealthKit(name, healingValue));
    }
}


void Randomizer::generateSimpleWeapon(const char name[], int damage, int probability, FedeList<Item*>* items) {
    //if should be generated (probability hit)
    if (shouldGenerate(probability)) {
        //generate and push
        items -> push_back(new ItemSimpleWeapon(name, damage));
    }
}

bool Randomizer::shouldGenerate(int probability) {
    //the result
    bool res = false;
/*    //reset the seed at every call for maximium randomness.
    //also sum to the time a random number, 
    //in this way if we call rand() two times in the same second the result numbers are different.
    srand(time(NULL)+rand());
 */
    //generate the number betwen 1 and 100
    int n = 1 + (rand() % 100);
    //if the probability is hit
    if (n <= probability){
        //set the result as true
        res = true;
    } 
    //return the result
    return res;
}







