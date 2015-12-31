/* 
 * File:   View.hpp
 * Author: Riccardo Maffei
 *
 * Created on 22 dicembre 2015, 16.28
 */

#ifndef VIEW_HPP
#define VIEW_HPP

#include "Action.hpp"
#include "FedeList.hpp"
#include "Map.hpp"
#include "Player.hpp"
/**
 * The view interface.It has the methods that every view(console,2d,3d,...) should have.
 */
class View {
public:
    View();
    virtual ~View();
    
    /**
     * Ask the username and copies it in dest.
     * @param dest char[]: an array big enough to hold the username.
     */
    virtual void getUsername(char dest[]) = 0;
    
    /**
     * Show the game splash screen.
     */
    virtual void showSplash() = 0;
    
    /**
     * Show the game intro/prologue.
     */
    virtual void showPrologue(int numberOfPlayer) = 0;
    
    /**
     * Show actions and retriever the selected action.
     * @param actions FedeList&lt;Action*&gt;*: the action list.
     * @return Action*: the action selected by the user.
     */
    virtual Action* selectAction(FedeList<Action*>* actions) = 0;
    
    /**
     * Show the outcome of a given action.
     * The action have to been executed.
     * @param action Action*: the action to show the outcome.
     */
    virtual void showActionOutcome(Action* action) = 0;
    
    /**
     * Show the map from the perspective of the given player.
     * @param map Map*: the map.
     * @param player Player*: the player.
     */
    virtual void showMap(Map* map, Player* player) = 0;
    
    /**
     * Show the player's information.
     * @param player Player*: the player.
     */
    virtual void showPlayerInfo(Player* player) = 0;
    
    /**
     * Show synthetic information of a given list of player (used for roommates).
     * @param players FedeList&lt;Player*&gt;*: the list of players.
     */
    virtual void showShortInfo(FedeList<Player*>* players) = 0;
    
    /**
     * Clear the view.
     */
    virtual void clear() = 0;
private:

};

#endif /* VIEW_HPP */

