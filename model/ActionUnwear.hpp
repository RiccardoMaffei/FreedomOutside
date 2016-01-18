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
 * File:   ActionUnwear.hpp
 * Author: Federico Bertani
 *
 * Created on 29 dicembre 2015, 18.46
 */

#ifndef ACTIONUNWEAR_HPP
#define	ACTIONUNWEAR_HPP

#include "../model/Player.hpp"

/**
 *The action of removing an armor from the player and put it in the invetory.
 */
class ActionUnwear : public Action {
public:
    /**
     * Construct an action to unwear an armor.
     * @param player Player*: the player whose armor will be removed.
     */
    ActionUnwear(Player* player);
    
    /**
     * ActionUnwear deconstructor.
     */
    virtual ~ActionUnwear();

    /**
     * Unwear an armor and put it in the inventory of the player.
     */
    virtual void execute();
    
     /**
     * return a description of the action.
     * @param dest[] char: the string that will be filled with the description. <br> must be 255 long. 
     */
    virtual void getDescription(char dest[]);
    
    /**
     * Get the action outcome.
     * @return FedeList&lt;char**&gt;*: a string list that contains the outcome of the action.
     */
    virtual FedeList<char*>* getOutcome();

private:
    /**
     * Player*: the player whose armor will be removed.
     */
    Player* player;
    
    /**
     * ItemArmor* the armor to unwear.
     */
    ItemArmor* itemArmor;
};

#endif	/* ACTIONUNWEAR_HPP */

