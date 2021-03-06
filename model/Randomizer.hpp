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
 * File:   Randomizer.hpp
 * Author: Riccardo Maffei
 *
 * Created on 29 dicembre 2015, 2.23
 */

#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include "../model/FedeList.hpp"
#include "../model/Item.hpp"
/**
 * This class contains Game randomization core. Every random generation in the game should be handled here.
 * This class may use game difficulty to edit statistics.
 * This class is singletone.
 */
class Randomizer {
public:
    
    /**
     * Get the singleton instance of the randomizer.
     * @return Randomizer*: the randomizer instance
     */
    static Randomizer* getInstance();
    
    /**
     * Destroy a randomizer object.
     */
    virtual ~Randomizer();
    
    /**
     * Generate a random list of items and save it to the given list.
     * This is used for room generation.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    void generateRoomItems(FedeList<Item*>* items);

protected:
    /**
     * Create a randomizer object.
     */
    Randomizer();
    
    
    /**
     * Generate a simple weapong with given name and damage if the given probability is hit.
     * @param name const char name[]: the name of the weapon to create.
     * @param damage int: the damage of the weapon.
     * @param probability int: the probability that the weapon have to appear.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    void generateSimpleWeapon(const char name[],int damage,int probability,FedeList<Item*>* items);
    
    /**
     * Generate a destructive weapon with the given name and damage range if the given probability is hit.
     * @param name const char name[]: the name of the weapon to create.
     * @param damageMin int: the minimum damage the destructive weapon can create.
     * @param damageMax int: the maximium damage the destructive weapon can create.
     * @param probability int: the probability that the weapon have to appear.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    void generateDestructiveWeapon(const char name[],int damageMin,int damageMax,int probability,FedeList<Item*>* items);
    
    /**
     * Generate an armor item with the given name and protection factor if the given probability is hit.
     * @param name const char name[]: the name of the armor to create.
     * @param protectionFactor double: the protection factor of the armor.
     * @param probability int: the probability that the armor have to appear.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    void generateArmorItem(const char name[],double protectionFactor,int probability,FedeList<Item*>* items);
    
    /**
     * Generate a health kit with the given name and healing value if the given probability is hit.
     * @param name const char name[]: the name of the healith kit to create.
     * @param healingValue int: the number of point of health that the health kit is capable of restore.
     * @param probability int: the probability that the healith kit have to appear.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    void generateHealthKit(const char name[],int healingValue,int probability,FedeList<Item*>* items);
    
    /**
     * This function say if a given probability is hit or not.
     * @param probability int: the probability that the function return true in %.
     * @return bool: true if the probability is hit, false otherwise.
     */
    bool shouldGenerate(int probability);
    
    /**
     * Randomizer*: the singleton instance
     */
    static Randomizer* instance;
};

#endif /* RANDOMIZER_HPP */

