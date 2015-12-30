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
#include "FedeList.hpp"
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
     * Return an ordered list of visible rooms from the given one. (visibility +/- 2x +/- 2y) 
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
    //the singleton instance
    static Map* instance;
    //the room where the map starts (coordinates 0,0)
    Room* entryPoint;
    //the list of room of a Map
    FedeList<Room*>* roomList;
    //the left side of the list
    int sideLeft;
};

#endif	/* MAP_HPP */

