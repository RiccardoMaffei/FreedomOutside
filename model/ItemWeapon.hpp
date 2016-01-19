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
 * File:   ItemWeapon.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 15.42
 */

#ifndef ITEMWEAPON_HPP
#define ITEMWEAPON_HPP

#include "../model/Item.hpp"

/**
 * A weapon interface. Extension of Item.
 */
class ItemWeapon: public Item {
public:
    ItemWeapon(const char name[]);
    virtual ~ItemWeapon();
    
    /**
     * Get the base value of damage.
     * @return int: base damage value.
     */
    virtual int getDamageValue() = 0;
private:

};

#endif /* ITEMWEAPON_HPP */

