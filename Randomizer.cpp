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

Randomizer::Randomizer(const Randomizer& orig) {
}

Randomizer::~Randomizer() {
}

void Randomizer::generateRoomItems(FedeList<Item*>* items) {
    /* 
     * For every item reset the seed, generate a ramdom value and if it
     * is in range, generate and add the item.
     * Always reset the seed for an even better randomization.
     */ 
    //TODO: fix with actual value (probability, damage...)
    //the number
    int n = 0;
    //----------------SIMPLE WEAPONS ------------------
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Rotten wooden plank", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Wooden plank", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Sharp wooden plank", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Rotten stick", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("stick", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Rusty iron pipe", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Iron pipe", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Hammer", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Knife", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Sword", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Spear", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Axe", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Iron mace", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Bow", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Hunting Bow", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Slingshot", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Blowgun", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Handgun", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Rifle", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Shotgun", 1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemSimpleWeapon("Ak-47", 1));
    }
    //--------------END SIMPLE WEAPONS----------------
    //--------------DESTRUCTIVE WEAPONS----------------
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 6){
        //generate and add the item
        items -> push_back(new ItemDestructiveWeapon("Molotov", 30, 80));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 5){
        //generate and add the item
        items -> push_back(new ItemDestructiveWeapon("Grenade", 35, 85));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 2){
        //generate and add the item
        items -> push_back(new ItemDestructiveWeapon("TNT", 50, 100));
    }
    //------------END DESTRUCTIVE WEAPONS--------------
    //--------------------ARMORS----------------------
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 50){
        //generate and add the item
        items -> push_back(new ItemArmor("Rags armor", 1.1));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 35){
        //generate and add the item
        items -> push_back(new ItemArmor("Leather armor", 1.2));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 27){
        //generate and add the item
        items -> push_back(new ItemArmor("Hide armor", 1.3));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 20){
        //generate and add the item
        items -> push_back(new ItemArmor("Copper armor", 1.4));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 15){
        //generate and add the item
        items -> push_back(new ItemArmor("Bronze armor", 1.5));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 11){
        //generate and add the item
        items -> push_back(new ItemArmor("Iron armor", 1.6));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 8){
        //generate and add the item
        items -> push_back(new ItemArmor("Steel armor", 1.7));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 4){
        //generate and add the item
        items -> push_back(new ItemArmor("Gold armor", 1.8));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 200;
    //if it is in the probability range
    if (n < 1){ //NOTE that the number in this case 0 <= n <200 so 1 equals to 0.5% probability
        //generate and add the item
        items -> push_back(new ItemArmor("Diamond armor", 1.9));
    }
    //------------------END ARMORS--------------------
    //------------------HEALTH KITS--------------------
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 55){
        //generate and add the item
        items -> push_back(new ItemHealthKit("Tiny healing potion", 5));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 45){
        //generate and add the item
        items -> push_back(new ItemHealthKit("Small healing potion", 10));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 30){
        //generate and add the item
        items -> push_back(new ItemHealthKit("Medium healing potion", 30));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 20){
        //generate and add the item
        items -> push_back(new ItemHealthKit("Big healing potion", 50));
    }
    //reset the seed
    srand(time(NULL));
    //generate the number
    n = rand() % 100;
    //if it is in the probability range
    if (n < 10){
        //generate and add the item
        items -> push_back(new ItemHealthKit("Huge healing potion", 100));
    }
    //----------------END HEALTH KITS------------------
}

