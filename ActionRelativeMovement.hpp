/* 
 * File:   ActionRelativeMovement.hpp
 * Author: Riccardo Maffei
 *
 * Created on 25 dicembre 2015, 20.28
 */

#ifndef ACTIONRELATIVEMOVEMENT_HPP
#define ACTIONRELATIVEMOVEMENT_HPP

#include "Action.hpp"
#include "Room.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "ActionMovement.hpp"

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
    //the map to update
    Map* map;
    //the player to move
    Player* playerToMove;
    //the direction
    movementDirection_t direction;
    //the action movement
    ActionMovement* actionMovement;
};

#endif /* ACTIONRELATIVEMOVEMENT_HPP */

