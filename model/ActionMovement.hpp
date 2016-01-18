/*
 * Freedom Outside: a simple game for the Programming course.
 * Copyright (C) 2016  Riccardo Maffei, Federico Bertani, Danilo Branca.

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   ActionMovement.hpp
 * Author: Riccardo Maffei
 *
 * Created on 25 dicembre 2015, 16.22
 */

#ifndef ACTIONMOVEMENT_HPP
#define ACTIONMOVEMENT_HPP

#include "../model/Action.hpp"
#include "../model/Player.hpp"
#include "../model/Room.hpp"
#include <stdexcept>

/**
 * The action of a player movement between rooms.
 * Moving increase the agility of the player.
 */
class ActionMovement: public Action {
public:
    /**
     * Construct an ActionMovement with the given player and target Room.
     * @param playerToMove Player*: the player to move (must be not NULL).
     * @param targetRoom Room*: the target room (must be not NULL).
     * @throws invalid_argument: throw an invalid argument exception if at least one argument is NULL.
     */
    ActionMovement(Player* playerToMove, Room* targetRoom);

    
    /**
     * ActionMovement destructor.
     */
    virtual ~ActionMovement();
    
    /**
     * Move the player to the target room.
     * Moving increase agility of 0.2 points.
     */
    void execute();
    
    /**
     * Get the Action description. 
     * Say also if the agility has increased over a certain level (every 1 point).
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    void getDescription(char dest[]);
    
    /**
     * Get the action outcome.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual FedeList<char*>* getOutcome();

protected:
    /**
     * Player*: the player.
     */
    Player* playerToMove;
    
    /**
     * Room*: the target room.
     */
    Room* targetRoom;
    
    /**
     * bool: flag if the agility has been increased.
     */
    bool agilityIncreased;
};

#endif /* ACTIONMOVEMENT_HPP */

