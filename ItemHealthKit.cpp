/* 
 * File:   ItemHealthKit.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.42
 */

#include "ItemHealthKit.hpp"

ItemHealthKit::ItemHealthKit(const char name[], int healingValue): Item(name){
    //if the healing value is negative
    if(healingValue < 0){
        //set the healing value as 0
        healingValue = 0;
    }
    //save the healing value
    this -> healingValue = healingValue;
}

ItemHealthKit::~ItemHealthKit() {
}

int ItemHealthKit::getHealingValue() {
    //return the healing value
    return this -> healingValue;
}

void ItemHealthKit::getDescription(char dest[]) {
    //the string min value
    char value[50];
    //convert the value to string
    itoa(this -> healingValue, value);
    //copy the description with data
    strcpy(dest, "a health kit called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with ");
    strcat(dest, value);
    strcat(dest, " of healing value.");
}