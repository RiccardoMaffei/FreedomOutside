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
 * File:   Game.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.59
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "../model/FedeList.hpp"
#include "../view/View.hpp"
#include "../model/Map.hpp"
#include "../model/Player.hpp"
#include "../model/Action.hpp"
using namespace std;

/**
 * The game main class.
 */
class Game {
public:
    /**
     * Construct a game with 4 players.
     */
    Game();
    
    /**
     * Construct a game with a given number of players.
     * @param nPlayer int: number of players greater than 1.
     */
    Game(int nPlayer);
    
    /**
     * Destruct the game.
     */
    virtual ~Game();
    
    /**
     * Runs the game. This method contains the main game loop functionalities.
     */
    void play();
    
    
protected:
    /**
     * int: the number of player
     */
    int nPlayer;
    
    /**
     * Map*: the game map
     */
    Map* map;
    
    /**
     * FedeList&lt;Player*&gt;*: the list of players
     */
    FedeList<Player*>* playerList;
    
    /**
     * View*: the view
     */
    View* view;
    
    /**
     * int: index of the current Player
     */
    int currPlayer;
    
private:
        
    /**
     * Initialize the game with the given number of player.
     * @param nPlayer int: number of players greater than 1.
     */
    void init(int nPlayer);
    
    /**
     * Returns true if should run.
     * @return bool: true if there are at least two players alive.
     */
    bool shouldRun();
    
    /**
     * Populates the players list.
     */
    void populatePlayers();
    
    /**
     * Generate a list of possible actions for the given player.
     * @param currentPlayer Player*: the current player.
     * @return FedeList&lt;Action*&gt;*: the list of actions.
     */
    FedeList<Action*>* computePlayerActions(Player* currentPlayer);
    
    /**
     * Get the next alive player.
     * @return Player*: the next alive player.
     */
    Player* getNextPlayer();
    
    /**
     * Return a list of player with the same current room.
     * @param player Player* the player.
     * @return FedeList&lt;Player*&gt;*: the list of roommates.
     */
    FedeList<Player*>* getRoomMates(Player* player);
};

#endif	/* GAME_HPP */

