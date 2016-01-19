/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   ItemSimpleWeapon.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.37
 */

#ifndef ITEMSIMPLEWEAPON_HPP
#define ITEMSIMPLEWEAPON_HPP

#include "../model/ItemWeapon.hpp"

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
    ItemSimpleWeapon(const char name[], int damageValue);
    
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
    /**
     * int: the base damage value
     */
    int damageValue;
};

#endif /* ITEMSIMPLEWEAPON_HPP */

