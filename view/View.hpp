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
 * File:   View.hpp
 * Author: Riccardo Maffei
 *
 * Created on 22 dicembre 2015, 16.28
 */

#ifndef VIEW_HPP
#define VIEW_HPP

#include "../model/Action.hpp"
#include "../model/FedeList.hpp"
#include "../model/Map.hpp"
#include "../model/Player.hpp"
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
     * @param playerNumber int: a number to identify the player to get the username.
     */
    virtual void getUsername(char dest[],int playerNumber) = 0;
    
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
    
    /**
     * Show the given player as the winner.
     * If NULL show a message saying that there's no winner.
     * @param p Player*: the player who won or NULL.
     */
    virtual void showWinner(Player* p) = 0;
private:

};

#endif /* VIEW_HPP */

