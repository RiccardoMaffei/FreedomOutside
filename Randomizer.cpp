/* 
 * File:   Randomizer.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 29 dicembre 2015, 2.23
 */

#include "Randomizer.hpp"
#include "ItemSimpleWeapon.hpp"
#include "ItemDestructiveWeapon.hpp"
#include "ItemArmor.hpp"
#include "ItemHealthKit.hpp"
#include <time.h>
#include <stdlib.h>

Randomizer::Randomizer() {
}

Randomizer::~Randomizer() {
}

void Randomizer::generateRoomItems(FedeList<Item*>* items) {
    //----------------SIMPLE WEAPONS ------------------
    generateSimpleWeapon("Rotten wooden plank", 1, 50, items);
    generateSimpleWeapon("Wooden plank", 2, 49, items);
    generateSimpleWeapon("Sharp wooden plank", 3, 47, items);
    generateSimpleWeapon("Rotten stick", 4, 48, items);
    generateSimpleWeapon("stick", 5, 46, items);
    generateSimpleWeapon("Rusty iron pipe", 6, 43, items);
    generateSimpleWeapon("Iron pipe", 7, 40, items);
    generateSimpleWeapon("Hammer", 8, 39, items);
    generateSimpleWeapon("Knife", 9, 30, items);
    generateSimpleWeapon("Sword", 10, 2, items);
    generateSimpleWeapon("Spear", 15, 1, items);
    generateSimpleWeapon("Axe", 20, 1, items);
    generateSimpleWeapon("Iron mace", 30, 7, items);
    generateSimpleWeapon("Bow", 25, 8, items);
    generateSimpleWeapon("Hunting Bow", 35, 5, items);
    generateSimpleWeapon("Slingshot", 30, 6, items);
    generateSimpleWeapon("Blowgun", 29, 7, items);
    generateSimpleWeapon("Handgun", 45, 3, items);
    generateSimpleWeapon("Rifle", 60, 2, items);
    generateSimpleWeapon("Shotgun", 70, 1, items);
    generateSimpleWeapon("Ak-47", 90, 1, items);
    //--------------END SIMPLE WEAPONS----------------
    //--------------DESTRUCTIVE WEAPONS----------------
    generateDestructiveWeapon("Molotov",30,80,6,items);
    generateDestructiveWeapon("Granade",35,85,5,items);
    generateDestructiveWeapon("TNT",50,100,2,items);
    //------------END DESTRUCTIVE WEAPONS--------------
    //--------------------ARMORS----------------------
    generateArmorItem("Rags armor",1.1,50,items);
    generateArmorItem("Leather armor",1.2,35,items);
    generateArmorItem("Hide armor",1.3,27,items);
    generateArmorItem("Copper armor",1.4,20,items);
    generateArmorItem("Bronze armor",1.5,15,items);
    generateArmorItem("Iron armor",1.6,11,items);
    generateArmorItem("Steel armor",1.7,8,items);
    generateArmorItem("Gold armor",1.8,4,items);
    generateArmorItem("Diamond armor",1.9,1,items);
    //------------------END ARMORS--------------------
    //------------------HEALTH KITS--------------------
    generateHealthKit("Tiny healing potion",5,55,items);
    generateHealthKit("Small healing potion",10,45,items);
    generateHealthKit("Medium healing potion",30,30,items);
    generateHealthKit("Big healing potion",50,20,items);
    generateHealthKit("Huge healing potion",100,10,items);
    //----------------END HEALTH KITS------------------
}

void Randomizer::generateArmorItem(const char name[], double protectionFactor, int probability, FedeList<Item*>* items) {
    if (isToGenerate(probability)) {
        items -> push_back(new ItemArmor(name,protectionFactor));
    }
}


void Randomizer::generateDestructiveWeapon(const char name[], int damageMin, int damegeMax, int probability, FedeList<Item*>* items) {
    if (isToGenerate(probability)) {
        items -> push_back(new ItemDestructiveWeapon(name, damageMin, damegeMax));
    }
}

void Randomizer::generateHealthKit(const char name[], int healingValue, int probability, FedeList<Item*>* items) {
    if (isToGenerate(probability)) {
        items -> push_back(new ItemHealthKit(name, healingValue));
    }
}


void Randomizer::generateSimpleWeapon(const char name[], int damage, int probability, FedeList<Item*>* items) {
    if (isToGenerate(probability)) {
        items -> push_back(new ItemSimpleWeapon(name, damage));
    }
}

bool Randomizer::isToGenerate(int probability) {
    //reset the seed at every call for maximium randomness.
    srand(time(NULL));
    //generate the number
    int n = rand() % 100;
    if (n <= probability) return true;
    else return false;
}







