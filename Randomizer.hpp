/* 
 * File:   Randomizer.hpp
 * Author: Riccardo Maffei
 *
 * Created on 29 dicembre 2015, 2.23
 */

#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include "FedeList.hpp"
#include "Item.hpp"
/**
 * This class contains Game randomization core. Every random generation in the game should be handled here.
 * This class may use game difficulty to edit statistics.
 */
class Randomizer {
public:
    
    /**
     * Generate a random list of items and save it to the given list.
     * This is used for room generation.
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    static void generateRoomItems(FedeList<Item*>* items);
private:
    /**
     * Create a randomizer object.Useless because Ranzomizer has only static method.
     */
    Randomizer();
    
    /**
     * Destroy a randomizer object.Useless because Randomizer has only static mehtods.
     */
    virtual ~Randomizer();
    
    /**
     * Generate a simple weapong with given name and damage if the given probability is hit.
     * @param name const char name[]: the name of the weapon to create
     * @param damage int: the damage of the weapon
     * @param probability int: the probability that the weapon have to appear
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    static void generateSimpleWeapon(const char name[],int damage,int probability,FedeList<Item*>* items);
    
    /**
     * Generate a destructive weapon with the given name and damage range if the given probability is hit.
     * @param name const char name[]: the name of the weapon to create
     * @param damageMin int: the minimum damage the destructive weapon can create.
     * @param damageMax int: the maximium damage the destructive weapon can create.
     * @param probability int: the probability that the weapon have to appear
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to.
     */
    static void generateDestructiveWeapon(const char name[],int damageMin,int damageMax,int probability,FedeList<Item*>* items);
    
    /**
     * Generate an armor item with the given name and protection factor if the given probability is hit.
     * @param name const char name[]: the name of the armor to create
     * @param protectionFactor double: the protection factor of the armor
     * @param probability int: the probability that the armor have to appear
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to
     */
    static void generateArmorItem(const char name[],double protectionFactor,int probability,FedeList<Item*>* items);
    
    /**
     * Generate a health kit with the given name and healing value if the given probability is hit.
     * @param name const char name[]: the name of the healith kit to create
     * @param healingValue int: the number of point of health that the health kit is capable of restore.
     * @param probability int: the probability that the healith kit have to appear
     * @param items FedeList&lt;Item*&gt;*: the list where add the items to
     */
    static void generateHealthKit(const char name[],int healingValue,int probability,FedeList<Item*>* items);
    
    /**
     * This function say if a given probability is hit or not.
     * @param probability int: the probability that the function return true
     * @return bool: true if the probability is hit, false otherwise.
     */
    static bool isToGenerate(int probability);
};

#endif /* RANDOMIZER_HPP */

