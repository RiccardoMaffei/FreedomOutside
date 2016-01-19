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
 * File:   ActionCombat.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 14.58
 */

#ifndef ACTIONCOMBAT_HPP
#define ACTIONCOMBAT_HPP

#include "../model/Action.hpp"
#include "../model/ItemWeapon.hpp"
#include "../model/FedeList.hpp"
#include "../model/Player.hpp"

/**
 * A combat action. This action applies damage to a list player with a given weapon using attacker statistics.<br>
 * Fighting increase the strenght of the player.
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
     * Execute the action of fighting with others player.
     * Fighting increase strength of 0.2 points.
     */
    virtual void execute();
    
    /**
     * Get the action description. 
     * @param dest char[]: destination array. Must be big enough (max string length 255).
     */
    virtual void getDescription(char dest[]);
    
    /**
     * Get the action outcome.
     * Say also if the strenght has increased over a certain level (every 1 point).
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual FedeList<char*>* getOutcome();

private:
    /**
     * FedeList&lt;Player*&gt;*: the list of attacked players.
     */
    FedeList<Player*>* attackedPlayers;
    
    /**
     * FedeList&lt;int&gt;*: the damages inflicted to players.
     */
    FedeList<int>* inflictedDamages;
    
    /**
     * Player*: the attacker.
     */
    Player* attacker;
    
    /**
     * ItemWeapon*: the weapon.
     */
    ItemWeapon* weapon;
    
    /**
     * bool: flag if the strenght has been increased.
     */
    bool strengthIncreased;
};

#endif /* ACTIONCOMBAT_HPP */

