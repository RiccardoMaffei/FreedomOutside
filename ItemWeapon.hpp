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
    ItemWeapon(char name[]);
    virtual ~ItemWeapon();
private:

};

#endif /* ITEMWEAPON_HPP */

