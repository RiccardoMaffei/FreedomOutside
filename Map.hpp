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
#include <list>
#include "Room.hpp"

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
    static virtual Map* getInstance();
    
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
     * Create a Room in the given position.
     * warning: calling this function with coordinates of an existing room may lead to an unexpected behaviour.
     * @param x int: the x coordinate of the room.
     * @param y int: the y coordinate of the room.
     * @return Room*: the created room.
     */
    Room* createRoom(int x,int y);

protected:    
    /**
     * Creates a map with only the entry room.
     */
    Map();
    //the singleton instance
    static Map* instance = NULL;
    //the room where the map starts (coordinates 0,0)
    Room* entryPoint;
    //the list of room of a Map
    list<Room*> roomList;
};

#endif	/* MAP_HPP */

