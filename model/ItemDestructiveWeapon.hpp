/* 
 * File:   ItemDestructiveWeapon.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.39
 */

#ifndef ITEMDESTRUCTIVEWEAPON_HPP
#define ITEMDESTRUCTIVEWEAPON_HPP
#include "../model/Item.hpp"
#include "../model/ItemWeapon.hpp"

/**
 * A destructive weapon that should be applied to every near player.
 * This weapon has a random damage value between a range. Extension of Item.
 */
class ItemDestructiveWeapon: public ItemWeapon{
public:
    
    /**
     * Construct a destructive weapon with the given name and damage value.
     * @param name char[]: the weapon name (max 49 char).
     * @param min int: the minimum damage (must be greater than 0).
     * @param max int: the maximum damage (must be greater or equal than the minimum).
     */
    ItemDestructiveWeapon(const char name[], int min, int max);
    
    /**
     * ItemDestructiveWeapon destructor.
     */
    virtual ~ItemDestructiveWeapon();
    
    /**
     * Get the random value of damage.
     * @return int: random damage value.
     */
    int getDamageValue();
    
    /**
     * Get the destructive weapon description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    void getDescription(char dest[]);
    
protected:
    /**
     * int: minimum damage
     */
    int minDamage;
    
    /**
     * int: maximum damage
     */
    int maxDamage;
};

#endif /* ITEMDESTRUCTIVEWEAPON_HPP */

