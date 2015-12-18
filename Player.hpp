/* 
 * File:   Player.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.58
 */

#ifndef PLAYER_HPP
#define	PLAYER_HPP

#include <list>
#include "Item.hpp"
#include "Action.hpp"

using namespace std;

/**
 * The game player.
 */
class Player {
public:
    /**
     * Construct a Player with the given username
     * @param username
     */
    Player(char username[]);
    
    /**
     * Clone the given Player.
     * @param orig Player&: player to clone
     */
    Player(const Player& orig);
    
    /**
     * Player destructor
     */
    virtual ~Player();
    
    /**
     * Returns a lisf of possible actions for the player.
     * @return list&ltAction*&gt*: a list of possible actions for the player.
     */
    list<Action*>* getActions();
    
    /**
     * Inflicts given damages to the player.
     * @param damage int: damage to inflict
     * @return int: the inflicted damages. Inclicted damages may be less than give damages in case of protections or death.
     */
    int damage(int damage);
private:

protected:
    //the player username
    char username[50];
    //the player health
    int health;
    //the player inventory
    list<Item> inventory;
};

#endif	/* PLAYER_HPP */

