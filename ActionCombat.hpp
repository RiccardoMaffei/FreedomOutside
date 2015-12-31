/* 
 * File:   ActionCombat.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 14.58
 */

#ifndef ACTIONCOMBAT_HPP
#define ACTIONCOMBAT_HPP

#include "Action.hpp"
#include "ItemWeapon.hpp"
#include "FedeList.hpp"
#include "Player.hpp"

/**
 * A combat action. This action applies damage to a list player with a given weapon using attacker statistics.
 */
class ActionCombat: public Action{
public:
    
    /**
     * Construct an ActionCombat w/ the given data.
     * @param attacker Player*: the attacker.
     * @param weapon ItemWeapon*: the weapon to use for the combat.
     * @param attackedPlayers FedeList&lt;Player*&gt;*: the list of attacked players.
     */
    ActionCombat(Player* attacker, ItemWeapon* weapon, FedeList<Player*>* attackedPlayers);
    
    /**
     * ActionCombat destructor.
     */
    virtual ~ActionCombat();
    
    /**
     * Execute the action.
     */
    virtual void execute();
    
    /**
     * Get the action description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]);
    
    /**
     * Get the action outcome.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual FedeList<char*>* getOutcome();

private:
    //the list of attacked players
    FedeList<Player*>* attackedPlayers;
    //the damages inflicted to players
    FedeList<int>* inflictedDamages;
    //the attacker
    Player* attacker;
    //the weapon
    ItemWeapon* weapon;
    //flag if the strenght has been increased
    bool strengthIncreased;
};

#endif /* ACTIONCOMBAT_HPP */

