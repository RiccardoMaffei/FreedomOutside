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
 * File:   ConsoleView.hpp
 * Author: Riccardo Maffei
 * Author: Danilo Branca
 *
 * Created on 21 dicembre 2015, 1.52
 */

#ifndef CONSOLEVIEW_HPP
#define CONSOLEVIEW_HPP

#include "../view/View.hpp"
#include "../model/FedeList.hpp"
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
     * @param playerNumber int: a number to identify the player to get the username.
     */
    void getUsername(char dest[],int playerNumber);
    
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
     * Show the outcome of a given action. This method introduces a delay dynamically according to the length of the message.
     * The action should have been already executed.
     * @param action Action*: the action to show the outcome.
     */
    virtual void showActionOutcome(Action* action);
    
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
     * Print the given string slowly using the given delay time.
     * @param string char[]: the string.
     * @param delay int: delay in microseconds.
     */
    void slow_print(const char string[], int delay);
    
    /**
     * Show a prompt tha inform the player that is his turn.
     * @param player Player*: the player that have the turn.
     */
    void showPromptForTurn(Player* player);
    
    /**
     * Add an empty line at the bottom of the ouput list.
     * @param outputList FedeList&lt;char*&gt: the list of string to give in output
     */
    void addEmptyLineToOutput(FedeList<char*>* outputList);
    
    /**
     * Add lines that describe the player statistics.
     * @param outputList FedeList&lt;char*&gt: the list of string to give in output.
     * @param player Player*: the player whose statitics are shown.
     */
    void addPlayerStatsToOutput(FedeList<char*>* outputList,Player* player);
    
    /**
     * Add lines that describe the content of the player inventory.
     * @param outputList FedeList&lt;char*&gt: the list of string to give in output.
     * @param player Player*: the player whose inventory are shown.
     */
    void addInventoryInfoToOutput(FedeList<char*>* outputList,Player* player);
    
    /**
     * Add lines that describe the armor situation of the player.
     * @param outputList FedeList&lt;char*&gt: the list of string to give in output.
     * @param player Player*: the player to display the armor.
     */
    void addArmorInfoToOutput(FedeList<char*>* outputList,Player* player);
    
    /**
     * Clear the console printing 100 empty lines.
     */
    virtual void clear();
      
    /**
     * Show the given player as the winner on the console.
     * If NULL show a message saying that there's no winner.
     * @param p Player*: the player who won or NULL.
     */
    virtual void showWinner(Player* p);
};

#endif /* CONSOLEVIEW_HPP */

