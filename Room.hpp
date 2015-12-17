/* 
 * File:   Room.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.57
 */

#ifndef ROOM_HPP
#define	ROOM_HPP

#include <list>
#include "Action.hpp"

using namespace std;

/**
 * A simple game room with 4 doors.
 */
class Room {
public:
    /**
     * Construct an empty room w/ the given doors (room pointers)
     * @param x int: the x coordinate
     * @param y int: the x coordinate
     * @param north Room*: the northern room
     * @param south Room*: the southern room
     * @param east Room*: the eastern room
     * @param west Room*: the western room
     */
    Room(int x, int y, Room* north, Room* south, Room* east, Room* west);
    
    /**
     * Clone the given room
     * @param orig Room&: room to clone
     */
    Room(const Room& orig);
    
    /**
     * Room destructor
     */
    virtual ~Room();
    
    /**
     * Returns a lisf of possible actions for the room.
     * @return list&ltAction*&gt*: a list of possible actions for the room.
     */
    list<Action*>* getActions();
private:

protected:
    //the x coordinate of the room
    int x;
    //the y coordinate of the room
    int y;
    //north room pointer (aka north door)
    Room* north;
    //south room pointer (aka south door)
    Room* south;
    //east room pointer (aka east door)
    Room* east;
    //west room pointer (aka west door)
    Room* west;
};

#endif	/* ROOM_HPP */

