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
 * File:   Player.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include "../model/FedeList.hpp"
#include "../model/Item.hpp"
#include "../model/Action.hpp"
#include "../model/ItemArmor.hpp"
#include "../model/Room.hpp"

using namespace std;

/**
 * The game player.
 */
class Player {
public:
    
    /**
     * int: the player's max life. (greater than 0)
     */
    static int const MAX_HEALTH = 100;
    
    /**
     * int: the player's max inventory size. (greater than 0)
     */
    static int const MAX_INVENTORY = 5;
    
    /**
     * double: the player's maximum strength. (greater or equal to than the min)
     */
    static double const MAX_STRENGTH = 4.00;
    
    /**
     * double: the player's maximum agility. (greater or equal to than the min)
     */
    static double const MAX_AGILITY = 4.00;
    
    /**
     * double: the player's minimum strength. (greater or equal to 1)
     */
    static double const MIN_STRENGTH = 1.00;
    
    /**
     * double: the player's minimum agility. (greater or equal to 1)
     */
    static double const MIN_AGILITY = 1.00;
    
    /**
     * int: the starting number for prisoners numbering
     */
    static int const STARTING_PRISONER_NUMBER = 15687;
    
    /**
     * Construct a Player with the given username.
     * @param username char[]: the Player's username max 49 char.
     * @param currentRoom Room*: the current Player's room.
     */
    Player(char username[], Room* currentRoom);
   
    
    /**
     * Player destructor
     */
    virtual ~Player();
    
    /**
     * Inflicts given damages to the Player.
     * @param damage int: damage to inflict.
     * @return int: inflicted damages.
     */
    int damage(int damage);
    
    /**
     * Heal the player.
     * @param health int: the health points (greater than 0).
     * @return int: earned health.
     */
    int heal(int toHeal);
    
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
     * @param agility double: the agility (between MIN_AGILITY and MAX_AGILITY).
     */
    void setAgility(double agility);

    /**
     * Get the Player's strength.
     * @return double: Player's strength.
     */
    double getStrength();

    /**
     * Set the given strength to the player.
     * @param strength double: the strength (between MIN_STRENGTH and MAX_STRENGTH).
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
     * @param dest char[]: an array big enough (50) to store the username string.
     */
    void getUsername(char dest[]);
    
    /**
     * Check if the player is alive.
     * @return bool: true if the player is alive false otherwise.
     */
    bool isAlive();
private:

protected:
    /**
     * int: the static idCounter
     */
    static int idCounter;
    
    /**
     * int: the player id
     */
    int id;
    
    /**
     * char[50]: the player username
     */
    char username[50];
    
    /**
     * Room*: the current player room
     */
    Room* currentRoom;
    
    /**
     * int: the player health
     */
    int health;
    
    /**
     * FedeList&lt;Item*&gt;*: the player inventory
     */
    FedeList<Item*>* inventory;
    
    /**
     * ItemArmor*: the player armor
     */
    ItemArmor* armor;
    
    /**
     * double: player strength
     */
    double strength;
    
    /**
     * double: player agility
     */
    double agility;
};

#endif	/* PLAYER_HPP */

