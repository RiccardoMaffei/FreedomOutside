/* 
 * File:   Item.hpp
 * Author: Riccardo Maffei
 *
 * Created on 17 dicembre 2015, 14.14
 */

#ifndef ITEM_HPP
#define	ITEM_HPP

/**
 * An Item. It can be on the ground or held.
 */
class Item {
public:
    
    /**
     * Construct an Item with the given name.
     * @param name char[]: the Item's name max 49 char.
     */
    Item(char name[]);
    
    /**
     * Item destructor
     */
    virtual ~Item();
private:
    //the name of the item
    char name[50];
};

#endif	/* ITEM_HPP */

