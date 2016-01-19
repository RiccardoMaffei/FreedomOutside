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
 * File:   ItemArmor.hpp
 * Author: Riccardo Maffei
 *
 * Created on 18 dicembre 2015, 12.33
 */

#ifndef ITEMARMOR_HPP
#define ITEMARMOR_HPP

#include "../model/Item.hpp"

/**
 * An armor. Extension of Item.
 */
class ItemArmor : public Item {
public:
    
    /**
     * Construct an armor with the given name and protection factor.
     * @param name char[]: name (max 49 char).
     * @param protectionFactor double: armor protection factor greater than 1.
     */
    ItemArmor(const char name[], double protectionFactor);
    
    /**
     * Item destructor.
     */
    virtual ~ItemArmor();
    
    /**
     * Get the protection factor.
     * @return double: armor protection factor.
     */
    double getProtectionFactor();

    /**
     * Get the armor description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    void getDescription(char dest[]);
    
protected:
    /**
     * double: armor protection factor
     */
    double protectionFactor;
};

#endif /* ITEMARMOR_HPP */

