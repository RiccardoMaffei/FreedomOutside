/* 
 * File:   Player.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "FedeList.hpp"
#include "Item.hpp"
#include "Action.hpp"
#include "ItemArmor.hpp"
#include "Room.hpp"

using namespace std;

/**
 * The game player.
 */
class Player {
public:
    /**
     * Construct a Player with the given username.
     * @param username char[]: the Player's username max 49 char.
     * @param currentRoom Room*: the current Player's room.
     */
    Player(char username[], Room* currentRoom);
    
    /**
     * Clone the given Player.
     * @param orig Player&: player to clone.
     */
    Player(const Player& orig);
    
    /**
     * Player destructor
     */
    virtual ~Player();
    
    /**
     * Inflicts given damages to the Player.
     * @param damage int: damage to inflict.
     * @return int: the inflicted damages. Inclicted damages may be less than give damages in case of protections or death.
     */
    int damage(int damage);
    
    /**
     * Get the Player's health.
     * @return int: health.
     */
    int getHealth();

    /**
     * Get the Player's inventory.
     * @return FedeList&ltItem*&gt*: returns a pointer to the Player's inventory.
     */
    FedeList<Item*>* getInventory();
    
    /**
     * Get the  the Player's armor.
     * @return ItemArmor*: returns the Player's armor.
     */
    ItemArmor* getArmor();

    /**
     * Set the given armor as the Player's armor.
     * @param armor ItemArmor*: the armor to set.
     */
    void setArmor(ItemArmor* armor);

    /**
     * Get the Player's agility.
     * @return double: Player's agility. Greater than zero (if not will be set as 1).
     */
    double getAgility();

    /**
     * Set the given agility to the Player.
     * @param agility double: the agility.
     */
    void setAgility(double agility);

    /**
     * Get the Player's strength.
     * @return double: Player's strength.
     */
    double getStrength();

    /**
     * Set the given strength to the player.
     * @param strength double: the strength. Greater than zero (if not will be set as 1).
     */
    void setStrength(double strength);
    
    /**
     * Get the Player's id.
     * @return int: the Player's id.
     */
    int getId();
    
    /**
     * Get the room where the Player currently is.
     * @return Room*: the current room.
     */
    Room* getCurrentRoom();

    /**
     * Set the room where the Player currently is.
     * @param currentRoom Room*: the current room
     */
    void setCurrentRoom(Room* currentRoom);
    
    /**
     * Get the Player's username.
     * @param dest char[]: an array big enough to store the username string.
     */
    void getUsername(char dest[]);
private:

protected:
    //the static idCounter
    static int idCounter;
    //the player id
    int id;
    //the player username
    char username[50];
    //the current player room
    Room* currentRoom;
    //the player health
    int health;
    //the player inventory
    FedeList<Item*>* inventory;
    //the player armor
    ItemArmor* armor;
    //player strength
    double strength;
    //player agility
    double agility;
};

#endif	/* PLAYER_HPP */

