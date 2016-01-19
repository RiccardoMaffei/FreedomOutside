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
 * File:   ItemHealthKit.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.42
 */

#ifndef ITEMHEALTHKIT_HPP
#define ITEMHEALTHKIT_HPP
#include "../model/Item.hpp"

/**
 * A health kit: it heals Players. Extension of Item.
 */
class ItemHealthKit: public Item{
public:
    
    /**
     * Construct an ItemHealtKit with the given name and healing power.
     * @param name char[]: the health kit name (max 49 char).
     * @param healingValue int: the healing power measured in health point (greater than 0).
     */
    ItemHealthKit(const char name[], int healingValue);
    
    /**
     * ItemHealthKit destructor.
     */
    virtual ~ItemHealthKit();
    
    /**
     * Get the healing value.
     * @return int: healing value.
     */
    int getHealingValue();

    /**
     * Get the health kit description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    void getDescription(char dest[]);
    
protected:
    /**
     * int: healing power (not a factor but measured in health point).
     */
    int healingValue;
};

#endif /* ITEMHEALTHKIT_HPP */

