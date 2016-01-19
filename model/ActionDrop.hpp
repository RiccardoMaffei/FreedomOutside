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

