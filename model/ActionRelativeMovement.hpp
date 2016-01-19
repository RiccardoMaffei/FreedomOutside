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
 * File:   ActionRelativeMovement.hpp
 * Author: Riccardo Maffei
 *
 * Created on 25 dicembre 2015, 20.28
 */

#ifndef ACTIONRELATIVEMOVEMENT_HPP
#define ACTIONRELATIVEMOVEMENT_HPP

#include "../model/Action.hpp"
#include "../model/Room.hpp"
#include "../model/Map.hpp"
#include "../model/Player.hpp"
#include "../model/ActionMovement.hpp"

/**
 * The movement direction relative to the position of the pleyer.
 */
enum movementDirection_t{TO_NORTH, TO_SOUTH, TO_EAST, TO_WEST};

/**
 * The action of a player relative movement.
 */
class ActionRelativeMovement: public Action {
public:
    
    /**
     * Construct an ActionRelativeMovement with the given player, direction and map.
     * @param playerToMove Player*: the player to move.
     * @param direction movementDirection_t: the direction.
     * @param map Map*: the game map.
     */
    ActionRelativeMovement(Player* playerToMove, movementDirection_t direction, Map* map);
    
    /**
     * ActionRelativeMovement destructor.
     */
    virtual ~ActionRelativeMovement();
    
    /**
     * Move the player to the target room.
     */
    void execute();
    
    /**
     * Get the Action description. 
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
     * Concat the direction of the action to the string given.
     * @param dest char[]: a string to concat the direction.Must be big enough (>8)
     */
    void concatDirection(char dest[]);
    
    /**
     * Map*: the map to update.
     */
    Map* map;
    
    /**
     * Player*: the player to move.
     */
    Player* playerToMove;
    
    /**
     * movementDirection_t: the direction.
     */
    movementDirection_t direction;
};

#endif /* ACTIONRELATIVEMOVEMENT_HPP */

