/* 
 * File:   ActionPickup.h
 * Author: Federico Bertani
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
class ActionPickup : public Action{
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
    
    /**
     * Get the action outcome.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual void getOutcome(FedeList<char*>* outcome);


protected:
    Player* player;
    Item* itemToPickup;
};

#endif	/* ACTIONPICKUP_H */

