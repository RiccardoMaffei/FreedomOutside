/* 
 * File:   ActionWear.hpp
 * Author: Federico Bertani
 *
 * Created on 29 dicembre 2015, 18.36
 */

#ifndef ACTIONWEAR_HPP
#define	ACTIONWEAR_HPP

#include "Action.hpp"
#include "ItemArmor.hpp"
#include "Player.hpp"

/**
 * The action of wearing an armor.
 */
class ActionWear : public Action {
public:
    /**
     * Create an action of wearing an armor.
     * @param player Player*: the player that wear the armor.
     * @param armor ItemArmor*: the armor to wear.
     */
    ActionWear(Player* player,ItemArmor* armor);
    
    /**
     * Destroy ActionWear.
     */
    virtual ~ActionWear();
    
    /**
     * Wear an armor that is in the player inventory.
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
     * Player*: the player that is going to wear the armor.
     */
    Player* player;
    
    /**
     * ItemArmor*: the armor to wear.
     */
    ItemArmor* armor;
};

#endif	/* ACTIONWEAR_HPP */

