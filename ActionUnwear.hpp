/* 
 * File:   ActionUnwear.hpp
 * Author: Federico Bertani
 *
 * Created on 29 dicembre 2015, 18.46
 */

#ifndef ACTIONUNWEAR_HPP
#define	ACTIONUNWEAR_HPP

#include "Player.hpp"

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

private:
    //the player whose armor will be removed.
    Player* player;
    //the armor to wear
    ItemArmor* itemArmor;
};

#endif	/* ACTIONUNWEAR_HPP */

