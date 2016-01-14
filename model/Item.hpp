/* 
 * File:   Item.hpp
 * Author: Riccardo Maffei
 *
 * Created on 17 dicembre 2015, 14.14
 */

#ifndef ITEM_HPP
#define	ITEM_HPP

#include <string.h>
#include "../model/StringUtils.hpp"

/**
 * An abstract Item. It can be on the ground or held.
 */
class Item {
public:
    
    /**
     * Construct an Item with the given name.
     * @param name char[]: the Item's name max 49 char.
     */
    Item(const char name[]);
    
    /**
     * Item destructor
     */
    virtual ~Item();
    
    /**
     * Get the Item name.
     * @param dest char[]: destination array. Must be big enough (max string length 49).
     */
    void getName(char dest[]);
    
    /**
     * Get the Item description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]) = 0;

protected:
    /**
     * char[50]: the name of the item
     */
    char name[50];
};

#endif	/* ITEM_HPP */

