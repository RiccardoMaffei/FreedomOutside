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
 * File:   Map.hpp
 * Author: Riccardo Maffei
 * Author: Federico Bertani
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef MAP_HPP
#define	MAP_HPP

#include <stddef.h>
#include "../model/FedeList.hpp"
#include "../model/Room.hpp"

using namespace std;

/**
 * The game map. An expandable grid of rooms.
 * This class is singleton.
 */
class Map {
public:
    
    /**
     * Get the singleton instance of the map.
     * @return Map*: the map instance
     */
    static Map* getInstance();
    
    /**
     * Map destructor
     */
    virtual ~Map();
    
    /**
     * Finds a room by its coordinates.
     * @param x int: the x coordinate.
     * @param y int: the y coordinate.
     * @return Room*: the found room or null if it doesn't exist.
     */
    Room* findRoomByCoordinates(int x,int y);
    
    /**
     * Return the first room of the map.
     * @return Room*: the first room of the map.
     */
    Room* getEntryPoint();
    
    /**
     * Generate a Room in the given position.
     * <br/><b>warning: calling this function with coordinates of an existing room may lead to an unexpected behaviour
     * and data inconsistency.</b> (It doesn't check for existence for performace reasons)
     * @param x int: the x coordinate of the room.
     * @param y int: the y coordinate of the room.
     * @return Room*: the created room.
     */
    Room* generateRoom(int x,int y);
    
    /**
     * Get the left side of the map (the smallest x).
     * @return int: the smallest x.
     */
    int getSideLeft();
    
    /**
     * Return an ordered list of visible rooms from the given one. (e.g. visibility +/- 2x +/- 2y).
     * The area of visible room is a square not a circle. 
     * @param center Room*: the center room.
     * @param radius int: radius of visibility greater or equal to zero.
     * @return FedeList&lt;Room*&gt;*: the list.
     */
    FedeList<Room*>* getVisibleRooms(Room* center, int radius);

protected:
    /**
     * Creates a map with only the entry room.
     */
    Map();
    
    /**
     * Clone the given map. Must not be used.
     * @param orig Map: original map.
     */
    Map(const Map& orig);
    
    /**
     * Inserts the room in the map taking care of ordering and consistency.
     * @param r Room*. the room to insert
     */
    void insertRoom(Room* r);
    
    /**
     * Map*: the singleton instance
     */
    static Map* instance;
    
    /**
     * Room*: the room where the map starts (coordinates 0,0)
     */
    Room* entryPoint;
    
    /**
     * FedeList&lt;Room*&gt;*: the list of room of a Map useful for better search by coordinate
     */
    FedeList<Room*>* roomList;
    
    /**
     * int: the left side of the list
     */
    int sideLeft;
};

#endif	/* MAP_HPP */

