/* 
 * File:   ItemHealthKit.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.42
 */

#include "ItemHealthKit.hpp"

ItemHealthKit::ItemHealthKit(char name[], int healingValue): Item(name){
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
