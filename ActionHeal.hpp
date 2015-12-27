/* 
 * File:   ActionHeal.hpp
 * Author: Riccardo Maffei
 *
 * Created on 27 dicembre 2015, 19.08
 */

#ifndef ACTIONHEAL_HPP
#define ACTIONHEAL_HPP

#include "Action.hpp"
#include "ItemHealthKit.hpp"
#include "Player.hpp"


class ActionHeal: public Action {
public:
    /**
     * Heal the given Player with the given HealthKit.
     * @param kit ItemHealthKit: the health kit.
     * @param playerToHeal Player*: the player to heal (the kit must be in player's inventory).
     */
    ActionHeal(ItemHealthKit kit, Player* playerToHeal);
    
    /**
     * ActionHeal destructor.
     */
    virtual ~ActionHeal();
    
    /**
     * Execute the action.
     */
    virtual void execute();

protected:
    //the player to heal
    Player* playerToHeal;
    //the health kit
    ItemHealthKit kit;
};

#endif /* ACTIONHEAL_HPP */

