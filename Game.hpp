/* 
 * File:   Game.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.59
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "FedeList.hpp"
#include "View.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Action.hpp"
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
    //the number of player
    int nPlayer;
    //the game map
    Map* map;
    //the list of players
    FedeList<Player*>* playerList;
    //the view
    View* view;
    //index of the current Player
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
};

#endif	/* GAME_HPP */

