/* 
 * File:   ItemArmor.cpp
 * Author: Riccardo Maffei
 * 
 * Created on 18 dicembre 2015, 12.33
 */

#include "ItemArmor.hpp"

ItemArmor::ItemArmor(char name[], double protectionFactor): Item(name){
    //if the protection factor is less than 1
    if(protectionFactor < 1){
        //set the protection factor as 1
        protectionFactor = 1;
    }
    //save the protection factor
    this -> protectionFactor = protectionFactor;
}

ItemArmor::~ItemArmor() {
}

double ItemArmor::getProtectionFactor() {
    //return the protection factor
    return this -> protectionFactor;
}

void ItemArmor::getDescription(char dest[]) {
    //the string min value
    char value[50];
    //convert the value to string
    dtoaTwo(this -> protectionFactor, value);
    //copy the description with data
    strcpy(dest, "an armor called \"");
    strcat(dest, this -> name);
    strcat(dest, "\" with ");
    strcat(dest, value);
    strcat(dest, " protection factor.");
}