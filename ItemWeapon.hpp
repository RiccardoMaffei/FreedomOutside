/* 
 * File:   ItemWeapon.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.37
 */

#ifndef ITEMWEAPON_HPP
#define ITEMWEAPON_HPP

#include "Item.hpp"

class ItemWeapon: public Item{
public:
    
    /**
     * Construct a weapon with the given name and base value of damage.
     * @param name char[]: name of the wapon (max 49 char).
     * @param damageValue int: base value of damage greater than 0.
     */
    ItemWeapon(char name[], int damageValue);
    
    /**
     * Itemaweapon destructor
     */
    virtual ~ItemWeapon();
    
    /**
     * Get the base value of damage.
     * @return int: base damage value.
     */
    int getDamageValue();
private:
    //the damage base value
    int damageValue;
};

#endif /* ITEMWEAPON_HPP */

