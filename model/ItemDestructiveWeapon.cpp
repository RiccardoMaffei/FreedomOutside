/* 
 * File:   ItemDestructiveWeapon.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.39
 */

#include <stdlib.h>
#include <ctime>
#include "../model/ItemDestructiveWeapon.hpp""

ItemDestructiveWeapon::ItemDestructiveWeapon(const char name[], int min, int max): ItemWeapon(name) {
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
    //set random seed with current time + random: for calling this methods more times in the same seconds
    srand(time(NULL)+rand());
    //compute the random damage between min and max
    int randDamage = rand()%((this -> maxDamage) - (this -> minDamage) + 1) + (this -> minDamage);
    //return the computed value
    return randDamage;
}

void ItemDestructiveWeapon::getDescription(char dest[]) {
    //the string min value
    char minValue[50];
    //convert the value to string
    itoa(this -> minDamage, minValue);
    //the string max value
    char maxValue[50];
    //convert the value to string
    itoa(this -> maxDamage, maxValue);
    //copy the description with data
    strcpy(dest, "a destruptive weapon called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with damage value between ");
    strcat(dest, minValue);
    strcat(dest, " and ");
    strcat(dest, maxValue);
    strcat(dest, ".");
}
