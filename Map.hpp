/* 
 * File:   Map.hpp
 * Author: Riccardo Maffei
 * Author: Federico Bertani
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef MAP_HPP
#define	MAP_HPP

#include <list>
#include "Room.hpp"

using namespace std;

/**
 * A grid of rooms where players move and make actions.
 */
class Map {
public:
    /**
     * Creates a map with only the entry room.
     */
    Map();
    
    /**
     * Clone the given map.
     * @param orig Map&: the map to clone
     */
    Map(const Map& orig);
    
    /**
     * Map destructor
     */
    virtual ~Map();
    
    /**
     * Finds a room by searching it with its coordinates.
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
     * Create a Room in the position given.
     * 
     * warning: don't call this function to create an existing room.
     * 
     * @param x int: the x coordinate of the room.
     * @param y int: the y coordinate of the room.
     * @return the room created .
     */
    Room* createRoom(int x,int y);
protected:
    //the room where the map starts
    Room* entryPoint;
    //the list of room of a Map
    list<Room*> roomList;
};

#endif	/* MAP_HPP */

