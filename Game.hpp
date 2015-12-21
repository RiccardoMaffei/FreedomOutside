/* 
 * File:   Game.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.59
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include <list>
#include "ConsoleView.hpp"
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
     * @param nPlayer int: number of players.
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
    //the number of player
    int nPlayer;
    //the game map
    Map* map;
    //the list of players
    list<Player*>* playerList;
    //the view
    ConsoleView* view;
private:
};

#endif	/* GAME_HPP */

