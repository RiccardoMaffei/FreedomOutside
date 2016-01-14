/* 
 * File:   ActionDrop.h
 * Author: Federico Bertani
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 14.36
 */

#ifndef ACTIONDROP_H
#define	ACTIONDROP_H

#include "../model/Action.hpp"
#include "../model/Player.hpp"
#include "../model/Item.hpp"

/**
 * The action of dropping an item from the inventory of a player to the floor.
 */
class ActionDrop : public Action{
public:
    /**
     * Construct an action to drop an item from the inventory of a player.
     * @param player Player*: the player that drop the item.
     * @param itemToDrop Item*: the item to drop on the floor.
     */
    ActionDrop(Player* player, Item* itemToDrop);
    
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
    
    /**
     * Get the action outcome.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual FedeList<char*>* getOutcome();

protected:
    /**
     * Player*: the player.
     */
    Player* player;
    
    /**
     * Item*: the item to drop.
     */
    Item* itemToDrop;
};

#endif	/* ACTIONDROP_H */

