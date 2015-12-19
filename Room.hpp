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
#include "Item.hpp"

using namespace std;

/**
 * A simple game room with 4 doors.
 */
class Room {
public:
    /**
     * Construct an empty room w/ the given doors (room pointers), coordinates and items list.
     * @param x int: the x coordinate.
     * @param y int: the x coordinate.
     * @param north Room*: the northern room.
     * @param south Room*: the southern room.
     * @param east Room*: the eastern room.
     * @param west Room*: the western room.
     * @param items list&lt;Item*&gt;*: a pointer to the room's list of items. If null, an empty list will be added.
     */
    Room(int x, int y, Room* north, Room* south, Room* east, Room* west, list<Item*>* items);
    
    /**
     * Room destructor.
     */
    virtual ~Room();
    
    /**
     * Get the east room pointer.
     * @return Room*: returns the pointer to the east room or NULL if it has not been set yet.
     */
    Room* getEast();

    /**
     * Set the given Room pointer as the east room.
     * @param east Room*: east room.
     */
    void setEast(Room* east);

    /**
     * Get the north room pointer.
     * @return Room*: returns the pointer to the north room or NULL if it has not been set yet.
     */
    Room* getNorth();

    /**
     * Set the given Room pointer as the north room.
     * @param north Room*: north room.
     */
    void setNorth(Room* north);

    /**
     * Get the south room pointer.
     * @return Room*: returns the pointer to the south room or NULL if it has not been set yet.
     */
    Room* getSouth();

    /**
     * Set the given Room pointer as the south room.
     * @param south Room*: south room.
     */
    void setSouth(Room* south);

    /**
     * Get the west room pointer.
     * @return Room*: returns the pointer to the west room or NULL if it has not been set yet.
     */
    Room* getWest();

    /**
     * Set the given Room pointer as the west room.
     * @param west Room*: west room.
     */
    void setWest(Room* west);

    /**
     * Get the x coordinate of this room.
     * @return int: x coordinate.
     */
    int getX();

    /**
     * Get the y coordinate of this room.
     * @return int: y coordinate.
     */
    int getY();
    
    /**
     * Get the item list.
     * @return list&lt;Item*&gt;*: a pointer to the room's list of items.
     */
    list<Item*>* getItemList();

    
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
    //the list of items in the room (E.g.: on the ground)
    list<Item*>* items;
};

#endif	/* ROOM_HPP */

