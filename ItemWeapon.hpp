/* 
 * File:   ItemWeapon.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 15.42
 */

#ifndef ITEMWEAPON_HPP
#define ITEMWEAPON_HPP

#include "Item.hpp"

/**
 * A weapon interface. Extension of Item.
 */
class ItemWeapon: public Item {
public:
    ItemWeapon(char name[]);
    virtual ~ItemWeapon();
    
    /**
     * Get the base value of damage.
     * @return int: base damage value.
     */
    virtual int getDamageValue() = 0;
private:

};

#endif /* ITEMWEAPON_HPP */

