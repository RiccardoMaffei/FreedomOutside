/* 
 * File:   ItemWeapon.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 21 dicembre 2015, 21.37
 */

#include "ItemWeapon.hpp"

ItemWeapon::ItemWeapon(char name[], int damageValue): Item(name) {
    //if the damage value is not value (damageValue<=0)
    if (damageValue <= 0){
        //set as 1
        damageValue = 1;
    }
    //save the damage value
    this -> damageValue = damageValue;
}

ItemWeapon::~ItemWeapon() {
}

int ItemWeapon::getDamageValue() {
    //return the damage value
    return this -> damageValue;
}

