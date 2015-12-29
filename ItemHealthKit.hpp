/* 
 * File:   ItemHealthKit.hpp
 * Author: Riccardo Maffei
 *
 * Created on 21 dicembre 2015, 21.42
 */

#ifndef ITEMHEALTHKIT_HPP
#define ITEMHEALTHKIT_HPP
#include "Item.hpp"

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
    //healing power (not a factor but measured in health point).
    int healingValue;
};

#endif /* ITEMHEALTHKIT_HPP */

