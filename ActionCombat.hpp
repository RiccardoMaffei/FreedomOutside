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

private:
    //the list of attacked players
    FedeList<Player*>* attackedPlayers;
    //the attacker
    Player* attacker;
    //the weapon
    ItemWeapon* weapon;
};

#endif /* ACTIONCOMBAT_HPP */
