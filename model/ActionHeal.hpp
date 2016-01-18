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
 * File:   ActionHeal.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 19.08
 */

#ifndef ACTIONHEAL_HPP
#define ACTIONHEAL_HPP

#include "../model/Action.hpp"
#include "../model/ItemHealthKit.hpp"
#include "../model/Player.hpp"

/**
 * The healing action. Used to heal a player.
 */
class ActionHeal: public Action {
public:
    /**
     * Heal the given Player with the given HealthKit.
     * @param kit ItemHealthKit: the health kit.
     * @param playerToHeal Player*: the player to heal (the kit must be in player's inventory).
     */
    ActionHeal(ItemHealthKit* kit, Player* playerToHeal);
    
    /**
     * ActionHeal destructor.
     */
    virtual ~ActionHeal();
    
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

protected:
    /**
     * Player*: the player to heal.
     */
    Player* playerToHeal;
    
    /**
     * ItemHealthKit*: the health kit.
     */
    ItemHealthKit* kit;
};

#endif /* ACTIONHEAL_HPP */

