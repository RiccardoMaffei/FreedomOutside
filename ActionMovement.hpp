/* 
 * File:   ActionMovement.hpp
 * Author: Riccardo Maffei
 *
 * Created on 25 dicembre 2015, 16.22
 */

#ifndef ACTIONMOVEMENT_HPP
#define ACTIONMOVEMENT_HPP

#include "Action.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include <stdexcept>

/**
 * 
 * @param playerToMove
 * @param targetRoom
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
     */
    void execute();
    
    /**
     * Get the Action escription. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    void getDescription(char dest[]);

private:
    //the player
    Player* playerToMove;
    //the target room
    Room* targetRoom;
};

#endif /* ACTIONMOVEMENT_HPP */

