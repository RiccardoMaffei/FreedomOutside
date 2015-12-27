/* 
 * File:   ItemWeapon.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.37
 */

#include "ItemSimpleWeapon.hpp"
using namespace std;

ItemSimpleWeapon::ItemSimpleWeapon(char name[], int damageValue): Item(name) {
    //if the damage value is not value (damageValue<=0)
    if (damageValue <= 0){
        //set as 1
        damageValue = 1;
    }
    //save the damage value
    this -> damageValue = damageValue;
}

ItemSimpleWeapon::~ItemSimpleWeapon() {
}

int ItemSimpleWeapon::getDamageValue() {
    //return the damage value
    return this -> damageValue;
}

void ItemSimpleWeapon::getDescription(char dest[]) {
    //the string value
    char value[50];
    //convert the value to string
    itoa(this -> damageValue, value);
    //copy the description with data
    strcpy(dest, "A weapon called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with ");
    strcat(dest, value);
    strcat(dest, " base damage value.");
}
