/* 
 * File:   ItemArmor.hpp
 * Author: Riccardo Maffei
 *
 * Created on 18 dicembre 2015, 12.33
 */

#ifndef ITEMARMOR_HPP
#define ITEMARMOR_HPP

#include "Item.hpp"

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

