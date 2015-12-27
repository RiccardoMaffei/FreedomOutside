/* 
 * File:   ActionDrop.h
 * Author: fede
 *
 * Created on 27 dicembre 2015, 14.36
 */

#ifndef ACTIONDROP_H
#define	ACTIONDROP_H

#include "Action.hpp"
#include "Player.hpp"
#include "Item.hpp"

/**
 * The action to drop an item from the inventory of a player to the floor.
 */
class ActionDrop : public Action{
public:
    /**
     * Construct an action to drop an item from the inventory of a player
     * @param player Player*: the player that drop the item
     * @param itemToDrop Item*: the item to drop on the floor
     */
    ActionDrop(Player* player,Item* itemToDrop);
    
    /**
     * ActionDrop destructor.
     */
    virtual ~ActionDrop();
    
    /**
     * Drop the item on the floor of the room.
     */
    virtual void execute();
    
    /**
     * Get the Action description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]);

protected:
    Player* player;
    Item* itemToDrop;
};

#endif	/* ACTIONDROP_H */

