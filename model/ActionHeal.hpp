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

