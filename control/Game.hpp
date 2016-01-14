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

