/* 
 * File:   ItemSimpleWeapon.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.37
 */

#ifndef ITEMSIMPLEWEAPON_HPP
#define ITEMSIMPLEWEAPON_HPP

#include "ItemWeapon.hpp"

/**
 * A standard weapon. Extension of Item.
 */
class ItemSimpleWeapon: public ItemWeapon{ 
public:
    
    /**
     * Construct a weapon with the given name and base value of damage.
     * @param name char[]: name of the wapon (max 49 char).
     * @param damageValue int: base value of damage greater than 0.
     */
    ItemSimpleWeapon(char name[], int damageValue);
    
    /**
     * ItemSimpleWeapon destructor
     */
    virtual ~ItemSimpleWeapon();
    
    /**
     * Get the base value of damage.
     * @return int: base damage value.
     */
    int getDamageValue();
    
    /**
     * Get the weapon description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    void getDescription(char dest[]);
    
protected:
    //the damage base value
    int damageValue;
};

#endif /* ITEMSIMPLEWEAPON_HPP */

