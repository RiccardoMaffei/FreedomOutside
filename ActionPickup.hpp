/* 
 * File:   ActionPickup.h
 * Author: fede
 *
 * Created on 27 dicembre 2015, 14.59
 */

#ifndef ACTIONPICKUP_H
#define	ACTIONPICKUP_H

#include "Action.hpp"
#include "Player.hpp"
#include "Item.hpp"

/**
 * The action of pickup an item from a room and put it in the invenory of a player.
 */
class ActionPickup : Action{
public:
    /**
     * Construct an action of pickup an item from a room and put it in the invenory of a player.
     * @param player Player* : the player that pickup the item
     * @param itemToPickup Item* : the item to pickup.
     */
    ActionPickup(Player* player,Item* itemToPickup);
    
    /**
     * ActionPickup deconstructor.
     */
    virtual ~ActionPickup();
    
    /**
     * Pickup an item 
     */
    virtual void execute();
    
    /**
     * Get the Action description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]);


protected:
    Player* player;
    Item* itemToPickup;
};

#endif	/* ACTIONPICKUP_H */

