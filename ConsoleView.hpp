/* 
 * File:   ConsoleView.hpp
 * Author: Riccardo Maffei
 * Author: Danilo Branca
 *
 * Created on 21 dicembre 2015, 1.52
 */

#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include "View.hpp"
#include "FedeList.hpp"
#include <iostream>
#include <cstring>
using namespace std;

/**
 * Console view for the game.
 */
class ConsoleView: public View{
public:
    /**
     * Construct a console view
     */
    ConsoleView();
    
    /**
     * Console view destructor
     */
    virtual ~ConsoleView();
    
    /**
     * Ask the username and copies it in dest.
     * @param dest char[]: an array big enough to hold the username.
     */
    void getUsername(char dest[]);
    
    /**
     * Show the game splash screen as ascii art.
     */
    virtual void showSplash();

    /**
     * Show the game intro/prologue.
     */
    virtual void showPrologue(int numberOfPlayer);
    
    /**
     * Show actions and retriever the selected action.
     * @param actions FedeList&lt;Action*&gt;*: the action list.
     * @return Action*: the action selected by the user.
     */
    virtual Action* selectAction(FedeList<Action*>* actions);
    
    /**
     * Show the map from the perspective of the given player.
     * @param map Map*: the map.
     * @param player Player*: the player.
     */
    virtual void showMap(Map* map, Player* player);
    
    /**
     * Show the player's information.
     * @param player Player*: the player.
     */
    virtual void showPlayerInfo(Player* player);
    
    /**
     * Show synthetic information of a given list of player (used for roommates).
     * @param players FedeList&lt;Player*&gt;*: the list of players.
     */
    virtual void showShortInfo(FedeList<Player*>* players);
private:
    /**
     * Print text in a frame made with ascii character.
     * @param FedeList&lt;char*&gt;: a list that contain strings.
     */
    void frameText(FedeList<char*>* list);
    
    /**
     * Show a prompt tha inform the player that is his turn.
     * @param player Player*: the player that have the turn.
     */
    void showPromptForTurn(Player* player);
};

#endif /* CONSOLEVIEW_HPP */

