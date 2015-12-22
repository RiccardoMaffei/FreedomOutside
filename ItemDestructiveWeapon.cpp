/* 
 * File:   ItemDestructiveWeapon.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.39
 */

#include <stdlib.h>
#include <ctime>
#include "ItemDestructiveWeapon.hpp"

ItemDestructiveWeapon::ItemDestructiveWeapon(char name[], int min, int max): Item(name){
    //if min is less than 1
    if(min < 1){
        //set min as 1
        min = 1;
    }
    //if the max is less than min
    if(max < min){
        //set max as the min value
        max = min;
    }
    //save the minimum
    this -> minDamage = min;
    //save the maximum
    this -> maxDamage = max;
}

ItemDestructiveWeapon::~ItemDestructiveWeapon() {
}

int ItemDestructiveWeapon::getDamageValue() {
    //set random seed with current time
    srand(time(NULL));
    //compute the random damage between min and max
    int randDamage = rand()%((this ->maxDamage) - (this -> minDamage) + 1) + (this -> minDamage);
    //return the computed value
    return randDamage;
}
