/* 
 * File:   Game.hpp
 * Author: Riccardo Maffei
 *
 * Created on 16 dicembre 2015, 14.59
 */

#ifndef GAME_HPP
#define	GAME_HPP

class Game {
public:
    /**
     * Construct a game with 4 players.
     */
    Game();
    
    /**
     * Construct a game with a given number of players.
     * @param nPlayers int: number of players.
     */
    Game(int nPlayers);
    
    /**
     * Destruct the game.
     */
    virtual ~Game();
    
    /**
     * Runs the game. This method contains the main game loop functionalities.
     */
    void play();
private:

};

#endif	/* GAME_HPP */

