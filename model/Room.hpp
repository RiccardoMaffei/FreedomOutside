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
 * File:   Room.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.57
 */

#ifndef ROOM_HPP
#define	ROOM_HPP

#include "../model/FedeList.hpp"
#include "../model/Action.hpp"
#include "../model/Item.hpp"

using namespace std;

/**
 * A simple game room with 4 doors.
 */
class Room {
public:
    /**
     * Construct an empty room w/ the given doors (room pointers), coordinates and items list.
     * @param x int: the x coordinate (increased going rightwards).
     * @param y int: the x coordinate (increased going downwards).
     * @param north Room*: the northern room.
     * @param south Room*: the southern room.
     * @param east Room*: the eastern room.
     * @param west Room*: the western room.
     * @param items FedeList&lt;Item*&gt;*: a pointer to the room's list of items. If null, an empty list will be added.
     */
    Room(int x, int y, Room* north, Room* south, Room* east, Room* west, FedeList<Item*>* items);
    
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
     * @return FedeList&lt;Item*&gt;*: a pointer to the room's list of items.
     */
    FedeList<Item*>* getItemList();

    /**
     * Overload != operator.
     * @param right Room: rhs room.
     * @return bool: true if lhs != rhs.
     */
    bool operator!=(Room& right);

    /**
     * Overload &lt; operator.
     * @param right Room: rhs room.
     * @return bool: true if lhs &lt; rhs.
     */
    bool operator<(Room& right);

    /**
     * Overload &lt;= operator.
     * @param right Room: rhs room.
     * @return bool: true if lhs &lt;= rhs.
     */
    bool operator<=(Room& right);

    /**
     * Overload == operator.
     * @param right Room: rhs room.
     * @return bool: true if lhs == rhs.
     */
    bool operator==(Room& right);

    /**
     * Overload &gt; operator.
     * @param right Room: rhs room.
     * @return bool: true if lhs &gt; rhs.
     */
    bool operator>(Room& right);

    /**
     * Overload &gt;= operator.
     * @param right Room: rhs room.
     * @return bool: true if lhs &gt;= rhs.
     */
    bool operator>=(Room& right);
    
private:

protected:
    /**
     * int: the x coordinate of the room
     */
    int x;
    
    /**
     * int: the y coordinate of the room
     */
    int y;
    
    /**
     * Room*: north room pointer (aka north door)
     */
    Room* north;
    
    /**
     * Room*: south room pointer (aka south door)
     */
    Room* south;
    
    /**
     * Room*: east room pointer (aka east door)
     */
    Room* east;
    
    /**
     * Room*: west room pointer (aka west door)
     */
    Room* west;
    
    /**
     * FedeList&lt;Item*&gt;*: the list of items in the room (E.g.: on the ground)
     */
    FedeList<Item*>* items;
};

#endif	/* ROOM_HPP */

